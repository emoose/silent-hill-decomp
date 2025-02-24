#include "main/fileinfo.h"

#define NAME_PART_CHARS  4
#define NAME_CHAR_BITS   6
#define NAME_CHAR_MASK   0x3F
#define NAME_CHAR_OFFSET 0x20

/** Convenience macros to convert constant filenames to `name0123` and `name4567`. */
#define FA2N(c) (((u8)(c) - 0x20) & 0x3f)
#define FNP(c0, c1, c2, c3) (FA2N(c0) | (FA2N(c1) << 6) | (FA2N(c2) << 12) | (FA2N(c3) << 18))
#define FN(c0, c1, c2, c3, c4, c5, c6, c7) FNP(c0, c1, c2, c3), FNP(c4, c5, c6, c7)

/**
 * @brief File information table.
 *
 * The file table is the index to the game's two data archives:
 * the files `SILENT` and `HILL` on the CD. It contains metadata of every file
 * in those archives, such as the name, size, file type and where the file is on the CD.
 *
 * @note Not `const` because it has to end up in .data. Was also like that in the header
 * found in one of the prototypes.
 * 
 * @note The .inc file is generated by silentassets.
 */
s_FileInfo g_FileTable[FS_FILE_COUNT] =
{
#include "filetable.c.inc"
};

/**
 * @brief Array of file path strings.
 *
 * All possible path strings occuring in the data archives.
 * This is referenced by index (`pathIdx`) in each file table entry.
 *
 * In SLUS_007.07 there are 11 possible paths. They are all one subfolder deep
 * and have starting and trailing path separators (backslashes).
 *
 * @note Not `const char*` because it has to end up in .data/.sdata. Was also `char*` in the header
 * found in one of the prototypes.
 */
char* g_FilePaths[] =
{
    "\\1ST\\",
    "\\ANIM\\",
    "\\BG\\",
    "\\CHARA\\",
    "\\ITEM\\",
    "\\MISC\\",
    "\\SND\\",
    "\\TEST\\",
    "\\TIM\\",
    "\\VIN\\",
    "\\XA\\"
};

/**
 * @brief Array of file extension strings.
 *
 * All possible file extensions occuring in the data archives.
 * This is referenced by index (`type`) in each file table entry.
 *
 * In SLUS_007.07 there are 12 possible extensions. They all start with a dot
 * and are 3 characters long (`.XXX`).
 *
 * @note Not `const char*` because it has to end up in .data/.sdata. Was also `char*` in the header
 * found in one of the prototypes.
 */
char* g_FileExts[] =
{
    ".TIM",
    ".VAB",
    ".BIN",
    ".DMS",
    ".ANM",
    ".PLM",
    ".IPD",
    ".ILM",
    ".TMD",
    ".DAT",
    ".KDT",
    ".CMP"
};

/**
 * Array of starting sector numbers for the first 9 \XA\ files in the file table (2044 - 2052).
 * These files seem to contain dialog and music. Array starts and ends with 0s.
 */
u32 g_FileXaLoc[] =
{
    0x00000,
    0x099BF,
    0x0A227,
    0x0B377,
    0x0D0BF,
    0x0EA57,
    0x0F997,
    0x1096F,
    0x16F07,
    0x19797,
    0x00000
};

/**
 * @brief Decrypts an encrypted overlay.
 *
 * The overlays in the `1ST` folder in the data archives are encrypted.
 * Overlays in the `VIN` folder don't appear to be.
 * This function decrypts data dword-by-dword, so `size` presumably must be
 * divible by 4 to work properly.
 *
 * @param dest Destination buffer. Must be `size` long.
 * @param src Encrypted overlay data.
 * @param size The number of bytes to decrypt.
 */
void Fs_DecryptOverlay(s32* dst, const s32* src, s32 size)
{
    s32 seed = 0;
    s32 i = 0;

    i = 0;
    while (i < (size >> 2))
    {
        seed = (seed + 0x01309125) * 0x03A452F7;

        *dst = *src ^ seed;

        i++;
        src++;
        dst++;
    }
}

/**
 * @brief Gets the size of a file in the file table.
 *
 * Takes a file table entry index (`fileIdx`) and returns the size of that file,
 * obtained from its file table entry.
 *
 * @param fileIdx The index of the file entry to look up.
 * @return The size of the specified file entry in bytes.
 */
s32 Fs_GetFileSize(s32 fileIdx)
{
    return g_FileTable[fileIdx].blockCount * FS_BLOCK_SIZE;
}

/**
 * @brief Gets the full name of a file in the file table.
 *
 * Takes a file table entry index (`fileIdx`) and returns the name of that file (with extension)
 * into `outName`.
 * The name is decoded from its file table representation into proper ASCII and is null terminated.
 *
 * @note `outName` must be at least 13 bytes long to fit the longest possible name in 8.3 format.
 * There are no size checks.
 *
 * @param[out] outName Buffer where the decoded file name will be stored.
 * @param[in] fileIdx Index of the file in the file table.
 */
void Fs_GetFileName(char* outName, s32 fileIdx)
{
    Fs_GetFileInfoName(outName, &g_FileTable[fileIdx]);
}

/**
 * @brief Gets the name from a file table entry.
 *
 * Returns the name (with extension) in the file table entry `fentry`.
 * The name is decoded from its file table representation into proper ASCII and is null terminated.
 *
 * @note `outName` must be at least 13 bytes long to fit the longest possible name in 8.3 format.
 * There are no size checks.
 *
 * @param[out] outName Buffer where the decoded file name will be stored.
 * @param[in] fileEntry Pointer to the file table entry from which to decode the name.
 */
void Fs_GetFileInfoName(char* outName, const s_FileInfo* const fileEntry)
{
    s32 i = 0;
    char decoded;
    u32 namePart;
    char fileType;
    char* fileExt;

    namePart = fileEntry->name0123;

    while (i < FS_NAME_CHAR_MAX)
    {
        if (i == NAME_PART_CHARS)
            namePart = fileEntry->name4567;

        decoded = namePart & NAME_CHAR_MASK;

        if (decoded == 0)
            break;

        outName[i] = decoded + NAME_CHAR_OFFSET;
        namePart >>= NAME_CHAR_BITS;
        i++;
    }

    fileType = fileEntry->type;

    if (fileType == FS_INVALID_TYPE)
    {
        outName[i] = '\0';
        return;
    }

    fileExt = g_FileExts[fileType];
    outName[i] = *fileExt;

    while (*fileExt)
    {
        fileExt++;
        i++;
        outName[i] = *fileExt;
    }
}

/**
 * @brief Encodes a file name into 6-bit file table representation.
 *
 * Takes an ASCII file name and encodes it into the 6-bits per character format
 * used by the file table.
 * The name is stored in two 32-bit integers pointed to by `outName0123` and `outName4567`,
 * corresponding to the `s_FileInfo` fields of the same name.
 * 
 * Example of the file name encoding:
 *   For string like 'HERO':
 *   i0: 'H' - 0x20 << 0       = 0x28     (0000 0000 0000 0000 0010 1000)
 *       -> 0x28 | 0x0         = 0x28     (0000 0000 0000 0000 0010 1000)
 *   i1: 'E' - 0x20 << 6       = 0x940    (0000 0000 0000 1001 0100 0000)
 *       -> 0x28 | 0x940       = 0x968    (0000 0000 0000 1001 0110 1000)
 *   i2: 'R' - 0x20 << 12      = 0x32000  (0000 0011 0010 0000 0000 0000)
 *       -> 0x968 | 0x32000    = 0x32968  (0000 0011 0010 1001 0110 1000)
 *   i3: 'O' - 0x20 << 18      = 0xBC0000 (1011 1100 0000 0000 0000 0000)
 *       -> 0x32968 | 0xBC0000 = 0xBF2968 (1011 1111 0010 1001 0110 1000)
 *
 * @param[out] outName0123 Pointer to the integer where the first part of the
 * encoded name will be stored.
 * @param[out] outName4567 Pointer to the integer where the second part of the
 * encoded name will be stored.
 * @param[in] srcName The file name string to encode.
 */
void Fs_EncodeFileName(s32* outName0123, s32* outName4567, const char* srcName)
{
    s32 i;
    s32 currentShift;
    s32 srcChar;
    s32 encoded;
    s32 name0123;
    s32 name4567;

    name0123 = 0;
    name4567 = 0;
    currentShift = 0;
    for (i = 0; i < FS_NAME_CHAR_MAX; i++)
    {
        srcChar = srcName[i];

        if (i == NAME_PART_CHARS)
            currentShift = 0;

        if (srcChar == '\0' || srcChar == '.')
            break;

        encoded = (srcChar - NAME_CHAR_OFFSET) << currentShift;

        if (i < 4)
        {
            name0123 |= encoded;
        }
        else
        {
            name4567 |= encoded;
        }

        currentShift += NAME_CHAR_BITS;
    }

    *outName0123 = name0123;
    *outName4567 = name4567;
}

/**
 * @brief Gets the size of a file rounded up to CD sector size.
 *
 * Takes an index in the file table and returns that file's size in bytes, rounded up to
 * CD sector size (2048 bytes).
 *
 * @param fileIdx The index of the file entry to look up.
 * @return The size of the specified file entry in bytes rounded up to CD sector boundary.
 */
s32 Fs_GetFileSectorAlignedSize(s32 fileIdx)
{
  return ALIGN(g_FileTable[fileIdx].blockCount * FS_BLOCK_SIZE, FS_SECTOR_SIZE);
}

/**
 * @brief Finds a file of the specified type in the file table.
 *
 * Starts a linear search from the file table index `startIdx`,
 * going forwards if `direction` is positive, or backwards if it's negative.
 * Returns the index of the first file it encounters whose `type` field is `fileType`,
 * or -1 if it reaches the end of the table without finding anything.
 *
 * @param fileType The file type to search for.
 * @param startIdx The table index from which to start the search.
 * @param dir The direction of the search: positive for incrementing,
 * negative for decrementing.
 * @return The index of the first matching file entry, or -1 if not found.
 */
s32 Fs_FindNextFileOfType(s32 fileType, s32 startIdx, s32 dir)
{
    s32 i;
    u32 currentIdx;
    s32 inc;

    inc = (dir < 0) ? -1 : 1;

    i = 0;
    currentIdx = startIdx + inc;

    while (i < FS_FILE_COUNT)
    {
        if (currentIdx >= FS_FILE_COUNT)
            currentIdx = (dir < 0) ? (FS_FILE_COUNT - 1) : 0;

        if (g_FileTable[currentIdx].type == fileType)
            return currentIdx;

        currentIdx += inc;
        i++;
    }

    return -1;
}

/**
 * @brief Finds a file with the specified name and type in the file table.
 *
 * Starts a linear search from the file table index `startIdx` and moves forward.
 * Returns the index of the first file it encounters whose `type` field is `fileType`
 * and whose name is the same as `name`, or -1 if it reaches the end of the table
 * without finding anything.
 *
 * @param name The file name to search for.
 * @param fileType The file type ID to match.
 * @param startIdx The offset from which to start the search.
 * @return The index of the matching file entry, or -1 if not found.
 */
s32 Fs_FindNextFile(const char* name, s32 fileType, s32 startIdx)
{
    s_FileInfo* fileEntry;

    s32 name0123;
    s32 name4567;

    s32 i = startIdx;
    s32 foundIdx = -1;

    Fs_EncodeFileName(&name0123, &name4567, name);

    fileEntry = &g_FileTable[i];
    while (i < FS_FILE_COUNT)
    {
        if (fileEntry->name4567 == name4567 &&
            fileEntry->name0123 == name0123 &&
            fileEntry->type == fileType)
        {
            foundIdx = i;
            break;
        }

        i++;
        fileEntry++;
    }

    return foundIdx;
}

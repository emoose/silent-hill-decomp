#include "common.h"

// struct/fields/comments were included in certain SH releases
typedef struct
{
	u_long  sector   :19;   // ＣＤ上でのセクタ番号
	u_long  size     :12;   // サイズ(x256byte) or フレーム数(ムービー)
    
	u_long  path_no   :4;   // パス番号
	u_long  name0123 :24;   // 拡張子を除いたファイル名を圧縮したもの(6bit x4)

	u_long  name4567 :24;   // 拡張子を除いたファイル名を圧縮したもの(6bit x4)
	u_long  ext_no    :4;   // 拡張子番号
} FILE_INFO;

extern FILE_INFO file_info[];
extern char* path_name_p[];
extern char* ext_name_p[];

u_long FS_GetFileSize_80010B24(int file_index);
u_long FSEntry_GetFilePath_80010B88(char* path, FILE_INFO* file_info);
u_long FS_GetFilePath_80010B54(char* path, int file_index);
u_long FS_GetFileSizeAligned_80010CD4(int file_index);

u_long FS_ReadFileEx_80011074(int file_index, char a2, char a3, char a4, void* a5, void *a6, s32 *a7);

u_long FS_GetFileSize_80010B24(int file_index)
{
	return file_info[file_index].size * 256;
}

u_long FS_GetFilePath_80010B54(char* path, int file_index)
{
	return FSEntry_GetFilePath_80010B88(path, &file_info[file_index]);
}

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSEntry_GetFilePath_80010B88);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_CompressFileName_80010C60);

u_long FS_GetFileSizeAligned_80010CD4(int file_index)
{
	// returns size rounded to sectors?
	u_long size = file_info[file_index].size * 256;
	return (size + 2047) & ~0x7FF;
}

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_SearchNextInDir_80010D0C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_SearchFile_80010D80);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80010E58);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_NumInProgress_80010E68);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80010E84);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80010ECC);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_PreloadFile_80010F34);

u_long FS_ReadFile_80010F68(int file_index, void* buffer)
{
	return FS_ReadFileEx_80011074(file_index, 2, 0, 0, buffer, 0, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_ReadTIM_80010F9C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80011018);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_ReadFileEx_80011074);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_Reset_80011170);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_800111DC);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_Update_80011260);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSQueueEntry_UpdateType1_8001137C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSQueueEntry_UpdateType2_800114C4);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSQueueEntry_PrepareDestBuffer_80011630);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_800116BC);

// unsure about purpose of this
char FS_DoBuffersOverlap_800117AC(char* buf1, u_long buf1_size, char* buf2, u_long buf2_size)
{
	buf1 = (char*)((u_long)buf1 & 0xFFFFFF);
	buf2 = (char*)((u_long)buf2 & 0xFFFFFF);
	if (buf2 >= (buf1 + buf1_size) || buf1 >= (buf2 + buf2_size))
	{
		return 0;
	}
	return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSQueueEntry_CdSetLoc_800117E8);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSQueueEntry_CdRead_8001182C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_CdDisableXa_80011884);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSQueueEntry_HdRead_8001190C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80011A4C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSQueueEntry_LoadTIM_80011B24);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80011C3C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_MemArena_init_80011C70);

void func_80011CFC(void) {
}

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_MemArena_alloc_80011D04);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_MemArena_calcFreeSpace_80011E4C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_MemArena_free_80011ED0);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_MemArena_set_80011F48);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", memcpy);

void func_800120B0(void) {
}

u_long lcg_rand_800120B8();

INCLUDE_ASM("asm/main/nonmatchings/cdfs", lcg_rand_800120B8);

u_long lcg_rand15b_800120E4()
{
	return lcg_rand_800120B8() >> 17;
}

INCLUDE_ASM("asm/main/nonmatchings/cdfs", lcg_srand_get_80012104);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", lcg_srand_80012110);

u_long lcg_rand12b_8001211C()
{
	return lcg_rand_800120B8() >> 20;
}

INCLUDE_ASM("asm/main/nonmatchings/cdfs", memcpy32);

#include "common.h"

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_GetFileSize_80010B24);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_GetFilePath_80010B54);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FSEntry_GetFilePath_80010B88);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_CompressFileName_80010C60);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_GetFileSizeAligned_80010CD4);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_SearchNextInDir_80010D0C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_SearchFile_80010D80);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80010E58);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_NumInProgress_80010E68);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80010E84);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", func_80010ECC);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_PreloadFile_80010F34);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_ReadFile_80010F68);

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

INCLUDE_ASM("asm/main/nonmatchings/cdfs", FS_DoBuffersOverlap_800117AC);

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

INCLUDE_ASM("asm/main/nonmatchings/cdfs", lcg_rand_800120B8);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", lcg_rand15b_800120E4);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", lcg_srand_80012104);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", lcg_srand_get_80012110);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", lcg_rand12b_8001211C);

INCLUDE_ASM("asm/main/nonmatchings/cdfs", memcpy32);

#include "common.h"

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libcard/patch", _patch_wait_start);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libcard/patch", _check_dsr);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libcard/patch", _dsr_start);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libcard/patch", _dsr_end);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libcard/patch", _patch_card);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libcard/patch", _patch_card2);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libcard/patch", _copy_memcard_patch);

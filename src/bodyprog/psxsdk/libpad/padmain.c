#include "common.h"

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", PadEnableCom);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padSetVsyncParam);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", isVsync);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", intPad);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padChkVsync);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padStartCom);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padStopCom);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padInitSioMode);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", execIntState);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padSioRW);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padSioRW2);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padClrIntSio0);

INCLUDE_ASM("asm/bodyprog/nonmatchings/psxsdk/libpad/padmain", _padWaitRXready);

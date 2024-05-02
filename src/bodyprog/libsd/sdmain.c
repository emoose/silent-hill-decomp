#include "common.h"

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", tone_adsr_mem);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", tone_adsr_back);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", sd_alloc_sort);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSpuMalloc);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSpuMallocWithStartAddr);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSpuFree);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdWorkInit);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdInit);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdStart);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdStart2);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetTickMode);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqCalledTbyT);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetStereo);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetMono);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetReservedVoice);

void SdSetTableSize(void) {
}

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdEnd);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdQuit);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetSerialAttr);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetSerialVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetMVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVabOpenHead);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVabOpenHeadSticky);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVabFakeHead);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVbOpenOne);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVabTransBody);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVabTransBodyPartly);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVabTransCompleted);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVabClose);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetAutoKeyOffMode);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdAutoKeyOffCheck);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqOpen);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqOpenWithAccNum);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqPlay);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqStop);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqClose);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqPause);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqReplay);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqSetVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSeqGetVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtFlush);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtReverbOn);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtReverbOff);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtSetReverbType);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtSetReverbDepth);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetRVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtSEAllKeyOff);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtAllKeyOff);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtGetVabHdr);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVoKeyOn);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVoKeyOff);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVoKeyOffWithRROff);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtKeyOnV);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtKeyOn);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdVbKeyOn);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtKeyOffV);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtKeyOffVWithRROff);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetSeqStatus);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtSetDetVVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtSetVVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtGetDetVVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdUtGetVVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetTempo);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetTempo);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetSeqWide);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetMidiVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetMidiVol);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetMidiExpress);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetMidiExpress);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetMidiPan);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetMidiPan);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetMidiPitchBendFine);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetMidiPitchBendFine);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetTrackTranspause);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetTrackTranspause);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetTrackMute);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdSetTrackMute);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetSeqControlStatus);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetSeqPlayStatus);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetSeqBeat);

INCLUDE_ASM("asm/bodyprog/nonmatchings/libsd/sdmain", SdGetSeqBeat2);

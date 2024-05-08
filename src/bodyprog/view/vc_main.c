#include "common.h"

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcInitVCSystem);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcStartCameraSystem);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcEndCameraSystem_80080A04);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", func_80080A10);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", func_80080A30);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", func_80080A3C);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetFirstCamWork);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", func_80080B58);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcWorkSetFlags_80080BF8);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", func_80080C18);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcUserWatchTarget);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcUserCamTarget);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcChangeProjectionValue_80080D5C);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", func_80080D68);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcGetNowWatchPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcGetNowCamPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcReturnPreAutoCamWork);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetSubjChara);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcExecCamera);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetAllNpcDeadTimer);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRetSmoothCamMvF);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRetCurCamMvType);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", func_8008150C);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRetThroughDoorCamEndF);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRetFarWatchRate);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRetSelfViewEffectRate);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetFlagsByCamMvType);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcPreSetDataInVC_WORK);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetTHROUGH_DOOR_CAM_PARAM_in_VC_WORK);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetNearestEnemyDataInVC_WORK);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetNearRoadAryByCharaPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRetRoadUsePriority);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetCurNearRoadInVC_WORK);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcGetBestNewCurNearRoad);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcGetNearestNEAR_ROAD_DATA);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcAdvantageDistOfOldCurRoad);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcAutoRenewalWatchTgtPosAndAngZ);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeNormalWatchTgtPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMixSelfViewEffectToWatchTgtPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeFarWatchTgtPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetWatchTgtXzPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetWatchTgtYParam);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcAdjustWatchYLimitHighWhenFarView);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcAutoRenewalCamTgtPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRetMaxTgtMvXzLen);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeIdealCamPosByHeadPos);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeIdealCamPosForFixAngCam);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeIdealCamPosForThroughDoorCam);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeIdealCamPosUseVC_ROAD_DATA);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcAdjustXzInLimAreaUsingMIN_IN_ROAD_DIST);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeBasicCamTgtMvVec);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcAdjTgtMvVecYByCurNearRoad);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcCamTgtMvVecIsFlipedFromCharaFront);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcFlipFromCamExclusionArea);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcGetUseWatchAndCamMvParam);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRenewalCamData);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRenewalCamMatAng);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeNewBaseCamAng);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcRenewalBaseCamAngAndAdjustOfsCamAng);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeOfsCamTgtAng);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeOfsCam2CharaBottomAndTopAngByBaseMatT);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcAdjCamOfsAngByCharaInScreen);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcAdjCamOfsAngByOfsAngSpd);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcMakeCamMatAndCamAngByBaseAngAndOfsAng);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcSetDataToVwSystem);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcCamMatNoise);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", SQRT_80085B1C);

INCLUDE_ASM("asm/bodyprog/nonmatchings/view/vc_main", vcGetXZSumDistFromLimArea);

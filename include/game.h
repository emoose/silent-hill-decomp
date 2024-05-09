#ifndef _GAME_H_
#define _GAME_H_

#define STATIC_ASSERT(COND, MSG) typedef char static_assertion_##MSG[(COND) ? 1 : -1]
#define STATIC_ASSERT_SIZEOF(TYPE, SIZE) \
    typedef char static_assertion_sizeof_##TYPE[(sizeof(TYPE) == (SIZE)) ? 1 : -1]

// TODO
typedef struct
{
	char unk_800B9FC0[0x2768];
} SYS_W;
STATIC_ASSERT_SIZEOF(SYS_W, 0x2768);

extern Fixed32 FixedPoint_CurDeltaTime;

#include "vw_system.h"

#endif /* _GAME_H_ */

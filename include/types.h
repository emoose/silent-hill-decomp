#ifndef TYPES_H
#define TYPES_H

typedef signed char s8;
typedef short s16;
typedef int s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef int int32_t;
typedef unsigned int uint32_t;

typedef signed char s_char;
typedef signed short s_short;
typedef signed long s_long;
typedef signed int s_int;

typedef volatile char v_char;
typedef volatile short v_short;
typedef volatile long v_long;
typedef volatile int v_int;

typedef const char c_char;
typedef const short c_short;
typedef const long c_long;
typedef const int c_int;

typedef const unsigned char cu_char;
typedef const unsigned short cu_short;
typedef const unsigned long cu_long;
typedef const unsigned int cu_int;

typedef volatile unsigned char vu_char;
typedef volatile unsigned short vu_short;
typedef volatile unsigned long vu_long;
typedef volatile unsigned int vu_int;

#define NULL 0

#ifndef _UCHAR_T
#define _UCHAR_T
typedef unsigned char u_char;
#endif
#ifndef _USHORT_T
#define _USHORT_T
typedef unsigned short u_short;
#endif
#ifndef _UINT_T
#define _UINT_T
typedef unsigned int u_int;
#endif
#ifndef _ULONG_T
#define _ULONG_T
typedef unsigned long u_long;
#endif

// lightly modified VECTOR with padding int removed, seems used through a lot of SH code
typedef struct {
	long	vx, vy;
	long	vz;
} VECTOR3;

// helper typedef to signal fixed point numbers
typedef int Fixed32;

#endif

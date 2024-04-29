#ifndef _LIBGTE_H_
#define _LIBGTE_H_
typedef struct {		/* long word type 3D vector */
	long	vx, vy;
	long	vz, pad;
} VECTOR;
	
typedef struct {		/* short word type 3D vector */	
	short	vx, vy;
	short	vz, pad;
} SVECTOR;

#endif /* _LIBGTE_H_ */

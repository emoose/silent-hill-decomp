#ifndef _LIBPRESS_H_
#define _LIBPRESS_H_

void DecDCTReset(int mode);

void DecDCTin(u_long *buf, int mode);
void DecDCTout(u_long *buf, int size);

int DecDCToutCallback(void (*func)());

int DecDCTvlc(u_long *bs, u_long *buf);

#endif /* _LIBPRESS_H_ */

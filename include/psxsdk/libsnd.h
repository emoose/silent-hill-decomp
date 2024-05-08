#ifndef _LIBSND_H_
#define _LIBSND_H_

// these seem to be wrapper funcs which call into konami SD library equivalents

void SsSetMVol(short voll, short volr);
void SsEnd();
void SsSetSerialAttr(char s_num, char attr, char mode);
void SsSetSerialVol(char s_num, short voll, short volr);
void SsUtAllKeyOff(short mode);

#endif /* _LIBSND_H_ */

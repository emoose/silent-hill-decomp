#ifndef _LIBETC_H_
#define _LIBETC_H_

int VSync(int mode);
int ResetCallback();
int VSyncCallback(void (*f)());
int StopCallback();
int RestartCallback();
int CheckCallback(); // todo: what is this reading?

long SetVideoMode(long mode);
long GetVideoMode();

#endif /* _LIBETC_H_ */

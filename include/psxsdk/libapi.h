#ifndef _LIBAPI_H_
#define _LIBAPI_H_

int EnterCriticalSection();
int ExitCriticalSection();

long OpenEvent(unsigned long desc, long spec, long mode, long (*func)());
long EnableEvent(unsigned long event);
void DeliverEvent(unsigned long ev1, unsigned long ev2);

void _96_remove();

void ReturnFromException();

#endif /* _LIBAPI_H_ */

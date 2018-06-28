#ifndef _EXCEPTION_H
#define _EXCEPTION_H

typedef struct Exception Exception;
struct Exception{
  int errorCode;
  char *errorMsg;
};


#endif // _EXCEPTION_H

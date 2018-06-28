#include "Exception.h"
#include "CException.h"
#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>

void freeError(Exception *ex)
{
  if(ex)
  {
    if(ex->errorMsg)
      free(ex->errorMsg);
    free(ex);
  }
}

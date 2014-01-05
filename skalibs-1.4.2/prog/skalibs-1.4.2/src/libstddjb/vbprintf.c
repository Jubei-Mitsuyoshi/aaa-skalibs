/* ISC license. */

#include <stdarg.h>
#include <stdio.h>
#include "buffer.h"
#include "lolstdio.h"

int vbprintf (buffer *b, char const *format, va_list args)
{
  int r ;
  {
    va_list ugly ;
    va_copy(ugly, args) ;
    r = vsnprintf(0, 0, format, ugly) ;
    va_end(ugly) ;
  }
  if (r < 0) return r ;
  {
    char buf[(unsigned int)r + 1] ;
    r = vsnprintf(buf, (unsigned int)r + 1, format, args) ;
    if (r < 0) return r ;
    if (buffer_put(b, buf, r) < r) return -1 ;
  }
  return r ;
}

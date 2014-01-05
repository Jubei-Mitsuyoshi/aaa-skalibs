/* ISC license. */

#include <stdarg.h>
#include <stdio.h>
#include "stralloc.h"
#include "bufalloc.h"
#include "lolstdio.h"

int vbaprintf (bufalloc *ba, char const *format, va_list args)
{
  int r ;
  {
    va_list ugly ;
    va_copy(ugly, args) ;
    r = vsnprintf(0, 0, format, ugly) ;
    va_end(ugly) ;
  }
  if (r < 0) return r ;
  if (!stralloc_readyplus(&ba->x, (unsigned int)r + 1)) return -1 ;
  r = vsnprintf(ba->x.s + ba->x.len, (unsigned int)r + 1, format, args) ;
  if (r > 0) ba->x.len += r ;
  return r ;
}

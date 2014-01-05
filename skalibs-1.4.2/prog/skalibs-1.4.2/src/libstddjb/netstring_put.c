/* ISC license. */

#include <errno.h>
#include "fmtscan.h"
#include "buffer.h"
#include "netstring.h"

int netstring_put (buffer_ref b, char const *s, unsigned int len, unsigned int *written)
{
  char fmt[UINT_FMT] ;
  unsigned int n = uint_fmt(fmt, len) ;
  if (*written > len + n + 2) return (errno = EINVAL, -1) ;
  fmt[n] = ':' ;
  if (*written < n + 1)
  {
    unsigned int w = *written ;
    int r = buffer_putall(b, fmt, n+1, &w) ;
    if (r == -1) return (*written = w, -1) ;
    *written = n+1 ;
  }
  if (*written < n+1 + len)
  {
    unsigned int w = *written - (n+1) ;
    int r = buffer_putall(b, s, len, &w) ;
    *written = w + (n+1) ;
    if (r == -1) return (*written = n+1 + w, -1) ;
    *written = n+1 + len ;
  }
  {
    unsigned int w = 0 ;
    int r = buffer_putall(b, ",", 1, &w) ;
    if (r == -1) return -1 ;
  }
  *written = 0 ;
  return 0 ;
}

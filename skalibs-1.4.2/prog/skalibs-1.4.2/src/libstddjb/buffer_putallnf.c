/* ISC license. */

#include <errno.h>
#include "buffer.h"

int buffer_putallnoflush (buffer_ref b, char const *buf, unsigned int len)
{
  register unsigned int r = buffer_putnoflush(b, buf, len) ;
  if (r == len) return 0 ;
  buffer_unput(b, r) ;
  errno = ENOBUFS ;
  return -1 ;
}

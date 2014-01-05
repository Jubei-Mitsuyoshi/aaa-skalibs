/* ISC license. */

#include <errno.h>
#include "buffer.h"

int buffer_getallnofill (buffer_ref b, char *buf, unsigned int len)
{
  register unsigned int r = buffer_getnofill(b, buf, len) ;
  if (r == len) return 0 ;
  buffer_unget(b, r) ;
  errno = ENOBUFS ;
  return -1 ;
}

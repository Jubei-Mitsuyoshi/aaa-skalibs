/* ISC license. */

#include "buffer.h"

int buffer_get (buffer_ref b, char *buf, unsigned int len)
{
  register int r = (int)buffer_getnofill(b, buf, len) ;
  if (r) return r ;
  if (len >= b->a) return (*b->op)(b->fd, buf, len) ;
  r = buffer_fill(b) ; if (r <= 0) return r ;
  return (int)buffer_getnofill(b, buf, len) ;
}

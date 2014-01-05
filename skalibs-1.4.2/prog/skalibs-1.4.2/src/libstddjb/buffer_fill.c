/* ISC license. */

#include <errno.h>
#include "buffer.h"

int buffer_fill (buffer_ref b)
{
  register int r ;
  buffer_clean(b) ;
  if (b->n == b->a) return (errno = ENOBUFS, -1) ;
  r = (*b->op)(b->fd, b->x + b->n, b->a - b->n) ;
  if (r > 0) b->n += r ;
  return r ;
}

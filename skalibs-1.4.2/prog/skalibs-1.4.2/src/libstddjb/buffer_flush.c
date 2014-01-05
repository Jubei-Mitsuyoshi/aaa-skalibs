/* ISC license. */

#include "allreadwrite.h"
#include "buffer.h"

int buffer_flush (buffer_ref b)
{
  register unsigned int n = allreadwrite(b->op, b->fd, b->x + b->p, b->n - b->p) ;
  b->p += n ;
  buffer_clean(b) ;
  return buffer_len(b) ? -1 : (int)n ;
}

/* ISC license. */

#include "bytestr.h"
#include "buffer.h"

void buffer_clean (register buffer_ref b)
{
  if (b->p)
  {
    byte_copy(b->x, b->n - b->p, b->x + b->p) ;
    b->n -= b->p ;
    b->p = 0 ;
  }
}

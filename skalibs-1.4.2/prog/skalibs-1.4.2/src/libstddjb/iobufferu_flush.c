/* ISC license. */

#include "buffer.h"
#include "iobuffer.h"

int iobufferu_flush (iobufferu_ref b)
{
  register int r = buffer_flush(&b->b[1]) ;
  b->b[0].n = b->b[1].n ;
  b->b[0].p = b->b[1].p ;
  return r ;
}

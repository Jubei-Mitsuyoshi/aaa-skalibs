/* ISC license. */

#include "buffer.h"
#include "iobuffer.h"

int iobufferu_fill (iobufferu_ref b)
{
  register int r = buffer_fill(&b->b[0]) ;
  b->b[1].n = b->b[0].n ;
  b->b[1].p = b->b[0].p ;
  return r ;
}

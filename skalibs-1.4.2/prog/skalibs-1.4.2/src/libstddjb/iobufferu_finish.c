/* ISC license. */

#include "alloc.h"
#include "iobuffer.h"

void iobufferu_finish (iobufferu_ref b)
{
  alloc_free(b->buf) ;
}

/* ISC license. */

#include <errno.h>
#include "iobuffer.h"

int iobuffer_flush (iobuffer_ref b)
{
  if (b->isk)
  {
    register int r = iobufferk_flush(&b->x.k) ;
    if ((r < 0) && (errno == ENOSYS) && iobuffer_salvage(b)) goto user ;
    return r ;
  }
 user:
  return iobufferu_flush(&b->x.u) ;
}

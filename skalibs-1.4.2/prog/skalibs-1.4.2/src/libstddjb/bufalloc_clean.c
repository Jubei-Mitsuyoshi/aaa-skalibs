/* ISC license. */

#include "bytestr.h"
#include "bufalloc.h"

void bufalloc_clean (register bufalloc_ref ba)
{
  if (ba->p)
  {
    byte_copy(ba->x.s, ba->x.len - ba->p, ba->x.s + ba->p) ;
    ba->x.len -= ba->p ;
    ba->p = 0 ;
  }
}

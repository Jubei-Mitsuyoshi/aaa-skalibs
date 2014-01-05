/* ISC license. */

#include "allreadwrite.h"
#include "bufalloc.h"

int bufalloc_flush (register bufalloc_ref ba)
{
  ba->p += allreadwrite((iofunc_t_ref)ba->op, ba->fd, ba->x.s + ba->p, ba->x.len - ba->p) ;
  bufalloc_clean(ba) ;
  return ba->x.len ? -1 : 0 ;
}

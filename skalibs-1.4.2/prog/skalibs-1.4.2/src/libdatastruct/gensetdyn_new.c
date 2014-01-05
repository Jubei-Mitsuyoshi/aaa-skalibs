/* ISC license. */

#include "freelist.h"
#include "gensetdyn.h"

int gensetdyn_new (gensetdyn_ref g, unsigned int *i)
{
  register unsigned int r = freelist_pop(g->freelist.s, &g->freelist.len, g->storage.len) ;
  if (r >= g->storage.len)
  {
    if (!gensetdyn_readyplus(g, 1)) return 0 ;
    r = freelist_pop(g->freelist.s, &g->freelist.len, g->storage.len) ;
  }
  *i = r ;
  return 1 ;
}

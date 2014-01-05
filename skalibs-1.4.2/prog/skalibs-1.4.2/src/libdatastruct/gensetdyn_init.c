/* ISC license. */

#include "stralloc.h"
#include "gensetdyn.h"

void gensetdyn_init (gensetdyn_ref g, unsigned int esize, unsigned int base, unsigned int fracnum, unsigned int fracden)
{
  g->storage = stralloc_zero ;
  g->freelist = stralloc_zero ;
  g->esize = esize ;
  g->base = base ;
  g->fracnum = fracnum ;
  g->fracden = fracden ;
}

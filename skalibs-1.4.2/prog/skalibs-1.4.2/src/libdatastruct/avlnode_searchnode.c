/* ISC license. */

#include "functypes.h"
#include "avlnode.h"
#include "avlnode-internal.h"

unsigned int avlnode_searchnode (avlnode const *s, unsigned int max, unsigned int r, unsigned int k, uintcmpfunc_t_ref f, void *p)
{
  while (r < max)
  {
    register int h = (*f)(k, s[r].data, p) ;
    if (!h) break ;
    r = s[r].child[avlnode_ufroms(h)] ;
  }
  return r ;
}

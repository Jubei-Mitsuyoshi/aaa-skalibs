/* ISC license. */

#include <errno.h>
#include "genset.h"
#include "avlnode.h"
#include "avltreen.h"

int avltreen_delete (avltreen_ref t, unsigned int k)
{
  unsigned int r = avltreen_root(t) ;
  unsigned int i = avlnode_delete(avltreen_nodes(t), avltreen_totalsize(t), &r, k, t->cmp, t->external) ;
  if (i >= avltreen_totalsize(t)) return (errno = ESRCH, 0) ;
  avltreen_setroot(t, r) ;
  if (!genset_delete(&t->x, i)) return 0 ;
  return 1 ;
}

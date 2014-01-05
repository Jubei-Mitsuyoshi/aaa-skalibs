/* ISC license. */

#include "functypes.h"
#include "genset.h"
#include "avlnode.h"
#include "avltreen.h"

void avltreen_init (avltreen_ref t, avlnode_ref storage, char *freelist, unsigned int size, uintcmpfunc_t_ref f, void *p)
{
  GENSET_init(&t->x, avlnode, storage, freelist, size) ;
  t->root = size ;
  t->cmp = f ;
  t->external = p ;
}

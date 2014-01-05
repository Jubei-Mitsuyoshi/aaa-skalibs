/* ISC license. */

#include <errno.h>
#include "functypes.h"
#include "gensetdyn.h"
#include "avlnode.h"
#include "avltree.h"

void avltree_init (avltree_ref t, unsigned int base, unsigned int fracnum, unsigned int fracden, uintcmpfunc_t_ref f, void *p)
{
  gensetdyn_init(&t->x, sizeof(avlnode), base, fracnum, fracden) ;
  t->root = (unsigned int)-1 ;
  t->cmp = f ;
  t->external = p ;
}

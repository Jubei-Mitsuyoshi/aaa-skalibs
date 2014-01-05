/* ISC license. */

#include "gensetdyn.h"
#include "avltree.h"

void avltree_free (avltree_ref t)
{
  gensetdyn_free(&t->x) ;
  *t = avltree_zero ;
}

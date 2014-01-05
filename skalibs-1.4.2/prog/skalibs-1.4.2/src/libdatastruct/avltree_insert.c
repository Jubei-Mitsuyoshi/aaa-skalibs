/* ISC license. */

#include "avltree.h"

int avltree_insert (avltree_ref t, unsigned int k)
{
  unsigned int i ;
  if (!avltree_newnode(t, k, &i)) return 0 ;
  avltree_insertnode(t, i) ;
  return 1 ;
}

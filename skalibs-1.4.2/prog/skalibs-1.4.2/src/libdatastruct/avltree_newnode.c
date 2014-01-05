/* ISC license. */

#include <errno.h>
#include "gensetdyn.h"
#include "avlnode.h"
#include "avltree.h"

int avltree_newnode (avltree_ref t, unsigned int k, unsigned int *i)
{
  if (!gensetdyn_new(&t->x, i)) return 0 ;
  {
    register avlnode_ref s = avltree_nodes(t) ;
    s[*i].data = k ;
    s[*i].child[0] = s[*i].child[1] = (unsigned int)-1 ;
    s[*i].balance = 0 ;
  }
  return 1 ;
}

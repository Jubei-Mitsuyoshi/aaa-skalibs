/* ISC license. */

#include "genset.h"
#include "avlnode.h"
#include "avltreen.h"

unsigned int avltreen_newnode (avltreen_ref t, unsigned int k)
{
  register unsigned int i = genset_new(&t->x) ;
  if (i < avltreen_totalsize(t))
  {
    register avlnode_ref s = avltreen_nodes(t) ;
    s[i].data = k ;
    s[i].child[0] = s[i].child[1] = avltreen_totalsize(t) ;
    s[i].balance = 0 ;
  }
  return i ;
}

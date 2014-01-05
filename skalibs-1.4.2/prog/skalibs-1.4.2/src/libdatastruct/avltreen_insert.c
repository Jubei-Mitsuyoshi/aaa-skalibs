/* ISC license. */

#include "avltreen.h"

int avltreen_insert (avltreen_ref t, unsigned int k)
{
  unsigned int i = avltreen_newnode(t, k) ;
  if (i >= avltreen_totalsize(t)) return 0 ;
  avltreen_insertnode(t, i) ;
  return 1 ;
}

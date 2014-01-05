/* ISC license. */

#include "avlnode.h"

unsigned int avlnode_height (avlnode const *s, unsigned int max, unsigned int r)
{
  if (r >= max) return 0 ;
  else if (s[r].balance) return 1 + avlnode_height(s, max, s[r].child[s[r].balance > 0]) ;
  else
  {
    unsigned int h1 = avlnode_height(s, max, s[r].child[0]) ;
    unsigned int h2 = avlnode_height(s, max, s[r].child[1]) ;
    return 1 + ((h1 > h2) ? h1 : h2) ;
  }
}

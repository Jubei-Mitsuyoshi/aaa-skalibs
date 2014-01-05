/* ISC license. */

#include <errno.h>
#include "avlnode.h"

int avlnode_search (avlnode const *s, unsigned int max, unsigned int r, unsigned int k, unsigned int *data, uintcmpfunc_t_ref f, void *p)
{
  register unsigned int i = avlnode_searchnode(s, max, r, k, f, p) ;
  if (i >= max) return (errno = ESRCH, 0) ;
  *data = s[i].data ;
  return 1 ;
}

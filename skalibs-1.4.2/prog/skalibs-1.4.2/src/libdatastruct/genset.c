/* ISC license. */

#include <errno.h>
#include "freelist.h"
#include "genset.h"

void genset_init (genset_ref x, void *storage, char *freelist, unsigned int esize, unsigned int max)
{
  x->storage = (char *)storage ;
  x->freelist = freelist ;
  x->esize = esize ;
  x->max = max ;
  x->sp = 0 ;
  freelist_init(freelist, &x->sp, 0, max) ;
}

unsigned int genset_new (genset_ref x)
{
  register unsigned int i = freelist_pop(x->freelist, &x->sp, x->max) ;
  if (i == x->max) errno = ENOSPC ;
  return i ;
}

int genset_delete (genset_ref x, unsigned int i)
{
  if (i >= x->max) return (errno = EINVAL, 0) ;
  if (!freelist_push(x->freelist, &x->sp, x->max, i)) return (errno = EINVAL, 0) ;
  return 1 ;
}

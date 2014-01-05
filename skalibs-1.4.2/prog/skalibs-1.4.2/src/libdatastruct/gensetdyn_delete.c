/* ISC license. */

#include <errno.h>
#include "freelist.h"
#include "gensetdyn.h"

int gensetdyn_delete (gensetdyn_ref g, unsigned int i)
{
  if (i >= g->storage.len) return (errno = EINVAL, 0) ;
  if (!freelist_push(g->freelist.s, &g->freelist.len, g->storage.len, i))
    return (errno = EINVAL, 0) ;
  return 1 ;
}

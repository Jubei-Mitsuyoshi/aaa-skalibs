/* ISC license. */

#include <sys/types.h>
#include <sys/mman.h>
#include "cdb.h"

extern void cdb_free (struct cdb *c)
{
  if (c->map) munmap(c->map, c->size) ;
  *c = cdb_zero ;
}

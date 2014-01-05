/* ISC license. */

#include "stralloc.h"
#include "bufalloc.h"

void bufalloc_init (bufalloc_ref ba, int (*op)(int, char const *, unsigned int), int fd)
{
  ba->x.len = 0 ;
  ba->op = op ;
  ba->fd = fd ;
  ba->p = 0 ;
}

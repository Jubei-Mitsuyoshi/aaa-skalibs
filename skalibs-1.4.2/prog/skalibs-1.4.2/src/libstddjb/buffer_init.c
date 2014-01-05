/* ISC license. */

#include "allreadwrite.h"
#include "buffer.h"

void buffer_init (register buffer_ref b, iofunc_t_ref op, int fd, char *buf, unsigned int len)
{
  b->x = buf ;
  b->a = len ;
  b->fd = fd ;
  b->op = op ;
  b->p = b->n = 0 ;
}

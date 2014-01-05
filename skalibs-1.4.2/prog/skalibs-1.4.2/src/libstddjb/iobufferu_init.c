/* ISC license. */

#include "alloc.h"
#include "allreadwrite.h"
#include "buffer.h"
#include "iobuffer.h"

int iobufferu_init (iobufferu_ref b, int fdin, int fdout)
{
  register char *x = alloc(IOBUFFERU_SIZE) ;
  if (!x) return 0 ;
  b->buf = x ;
  buffer_init(&b->b[0], &fd_read, fdin, x, IOBUFFERU_SIZE) ;
  buffer_init(&b->b[1], (iofunc_t_ref)&fd_write, fdout, x, IOBUFFERU_SIZE) ;
  return 1 ;
}

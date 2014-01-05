/* ISC license. */

#include <errno.h>
#include "buffer.h"

int buffer_unget (register buffer_ref b, register unsigned int len)
{
  if (b->p < len) return (errno = ENOBUFS, -1) ;
  b->p -= len ;
  return 0 ;
}

/* ISC license. */

#include <errno.h>
#include "buffer.h"

int buffer_unput (register buffer_ref b, register unsigned int len)
{
  if (len > (b->n - b->p)) return (errno = ESPIPE, -1) ;
  b->n -= len ;
  return 0 ;
}

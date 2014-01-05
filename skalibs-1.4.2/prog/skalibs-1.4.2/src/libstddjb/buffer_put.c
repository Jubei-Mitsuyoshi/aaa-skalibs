/* ISC license. */

#include "buffer.h"

int buffer_put (register buffer_ref b, char const *buf, unsigned int len)
{
  if (len > (b->a - b->n))
  {
    buffer_clean(b) ;
    if ((len > (b->a - b->n)) && (buffer_flush(b) == -1)) return -1 ;
  }
  return buffer_putalign(b, buf, len) ;
}

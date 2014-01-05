/* ISC license. */

#include "buffer.h"

void buffer_seek (register buffer_ref b, register unsigned int len)
{
  b->p += len ;
}

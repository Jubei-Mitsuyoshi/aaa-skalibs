/* ISC license. */

#include "buffer.h"
#include "genwrite.h"

int genwrite_flush_buffer (void *target)
{
  register buffer *b = target ;
  return buffer_flush(b) >= 0 ;
}

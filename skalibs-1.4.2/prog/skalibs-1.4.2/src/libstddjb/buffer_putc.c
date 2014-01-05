/* ISC license. */

#include "buffer.h"

int buffer_PUTC (buffer_ref b, char c)
{
  return buffer_putalign(b, &c, 1) ;
}

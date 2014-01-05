/* ISC license. */

#include "bytestr.h"
#include "buffer.h"

unsigned int buffer_putnoflush (buffer_ref b, char const *buf, unsigned int len)
{
  if (len > buffer_available(b))
  {
    buffer_clean(b) ;
    if (len > buffer_available(b)) len = buffer_available(b) ;
  }
  byte_copy(buffer_WPEEK(b), len, buf) ;
  buffer_WSEEK(b, len) ;
  return len ;
}

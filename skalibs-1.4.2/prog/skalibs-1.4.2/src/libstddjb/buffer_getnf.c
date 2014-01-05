/* ISC license. */

#include "bytestr.h"
#include "buffer.h"

unsigned int buffer_getnofill (register buffer_ref b, char *buf, unsigned int len)
{
  if (len > buffer_len(b)) len = buffer_len(b) ;
  byte_copy(buf, len, buffer_RPEEK(b)) ;
  buffer_RSEEK(b, len) ;
  return len ;
}

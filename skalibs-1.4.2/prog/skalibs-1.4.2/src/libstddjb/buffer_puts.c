/* ISC license. */

#include "bytestr.h"
#include "buffer.h"

int buffer_puts (buffer_ref b, char const *buf)
{
  return buffer_put(b, buf, str_len(buf)) ;
}

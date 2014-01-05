/* ISC license. */

#include "bytestr.h"
#include "buffer.h"

int buffer_putsflush (buffer_ref b, char const *buf)
{
  return buffer_putflush(b, buf, str_len(buf)) ;
}

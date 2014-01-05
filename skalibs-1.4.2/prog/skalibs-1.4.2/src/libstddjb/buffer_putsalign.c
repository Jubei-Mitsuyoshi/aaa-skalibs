/* ISC license. */

#include "bytestr.h"
#include "buffer.h"

int buffer_putsalign (buffer_ref b, char const *buf)
{
  return buffer_putalign(b, buf, str_len(buf)) ;
}

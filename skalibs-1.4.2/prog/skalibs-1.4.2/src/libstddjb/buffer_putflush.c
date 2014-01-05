/* ISC license. */

#include <errno.h>
#include "error.h"
#include "buffer.h"

int buffer_putflush (buffer_ref b, char const *buf, unsigned int len)
{
  unsigned int written = 0 ;
  if (buffer_putall(b, buf, len, &written) == -1)
    return error_isagain(errno) ? (int)written : -1 ;
  return (buffer_flush(b) == -1) ? -1 : (int)written ;
}

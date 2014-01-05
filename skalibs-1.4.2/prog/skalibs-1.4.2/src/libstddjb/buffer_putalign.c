/* ISC license. */

#include <errno.h>
#include "error.h"
#include "buffer.h"

int buffer_putalign (buffer_ref b, char const *buf, unsigned int len)
{
  unsigned int written = 0 ;
  register int r = buffer_putall(b, buf, len, &written) ;
  if ((r == -1) && !error_isagain(errno)) return -1 ;
  return written ;
}

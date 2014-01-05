/* ISC license. */

#include <errno.h>
#include "buffer.h"

int buffer_putall (buffer_ref b, char const *buf, unsigned int len, unsigned int *written)
{
  if (*written > len) return (errno = EINVAL, -1) ;
  for (;;)
  {
    *written += buffer_putnoflush(b, buf + *written, len - *written) ;
    if (*written >= len) return 0 ;
    buffer_flush(b) ;
    if (!buffer_available(b)) return -1 ;
  }
}

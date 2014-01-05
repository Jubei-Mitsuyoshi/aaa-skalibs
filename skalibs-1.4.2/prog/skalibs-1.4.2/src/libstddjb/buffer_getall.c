/* ISC license. */

#include <errno.h>
#include "allreadwrite.h"
#include "buffer.h"

int buffer_getall (buffer_ref b, char *buf, unsigned int len, unsigned int *written)
{
  if (*written > len) return (errno = EINVAL, -1) ;
  *written += buffer_getnofill(b, buf + *written, len - *written) ;
  if (*written >= len) return (*written = 0, 1) ;
  if ((len - *written) >= b->a)
  {
    *written += allreadwrite((iofunc_t_ref)b->op, b->fd, buf + *written, len - *written) ;
    return (*written >= len) ? (*written = 0, 2) : -1 ;
  }
  while (*written < len)
  {
    register int r = sanitize_read(buffer_fill(b)) ;
    if (r <= 0) return r ;
    *written += buffer_getnofill(b, buf + *written, len - *written) ;
  }
  *written = 0 ;
  return 2 ;
}

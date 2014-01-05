/* ISC license. */

#include <errno.h>
#include "bytestr.h"
#include "buffer.h"
#include "skamisc.h"

int getlnmax (buffer_ref b, char *d, unsigned int max, unsigned int *w, int sep)
{
  register int ok = 1 ;
  if (max < *w) return (errno = EINVAL, -1) ;
  for (;;)
  {
    unsigned int len = (*w + buffer_len(b) > max) ? max - *w : buffer_len(b) ;
    unsigned int pos = byte_chr(buffer_PEEK(b), len, sep) ;
    byte_copy(d + *w, pos, buffer_PEEK(b)) ; *w += pos ; buffer_SEEK(b, pos) ;
    if (*w >= max) return (errno = ERANGE, -1) ;
    if (pos < len)
    {
      d[(*w)++] = *buffer_PEEK(b) ; buffer_SEEK(b, 1) ;
      return ok ;
    }
    {
      register int r = buffer_fill(b) ;
      if (r <= 0) return r ;
    }
    ok = 2 ;
  }
}

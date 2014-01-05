/* ISC license. */

#include <errno.h>
#include "bytestr.h"
#include "buffer.h"
#include "stralloc.h"
#include "skamisc.h"

int skagetln (buffer_ref b, stralloc *sa, int sep)
{
  unsigned int start = sa->len ;
  int ok = 1 ;
  for (;;)
  {
    char *s = buffer_PEEK(b) ;
    unsigned int pos = byte_chr(s, buffer_len(b), sep) ;
    int r = (pos < buffer_len(b)) ;
    if (!stralloc_catb(sa, s, pos)) return -1 ;
    buffer_SEEK(b, pos) ;
    if (r)
    {
      if (!stralloc_catb(sa, buffer_PEEK(b), 1)) return -1 ;
      buffer_SEEK(b, 1) ;
      return ok ;
    }
    r = buffer_fill(b) ;
    if (r == -1) return -1 ;
    if (!r) return (sa->s && (sa->len > start)) ? (errno = EPIPE, -1) : 0 ;
    ok = 2 ;
  }
}

/* ISC license. */

#include <errno.h>
#include "bytestr.h"
#include "buffer.h"
#include "stralloc.h"
#include "tai.h"
#include "unix-timed.h"

int timed_getln (buffer_ref b, stralloc *sa, int sep, struct taia const *deadline, struct taia *stamp)
{
  unsigned int len = sa->len ;
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
    r = timed_buffer_fill(b, deadline, stamp) ;
    if (r == -1) return -1 ;
    if (!r) return (sa->len > len) ? (errno = EPIPE, -1) : 0 ;
    ok = 2 ;
  }
}

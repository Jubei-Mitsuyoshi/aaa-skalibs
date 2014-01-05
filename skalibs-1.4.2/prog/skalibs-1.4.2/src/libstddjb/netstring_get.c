/* ISC license. */

#include <errno.h>
#include "bytestr.h"
#include "fmtscan.h"
#include "buffer.h"
#include "stralloc.h"
#include "netstring.h"

int netstring_get (buffer_ref b, stralloc *sa, unsigned int *unread)
{
  unsigned int written ;
  int ok = 1 ;
  int r ;
  if (!sa->s || (!sa->len && !*unread))
  {
    char *x ;
    unsigned int n ;
    unsigned int len ;
    for (;;)
    {
      x = buffer_PEEK(b) ;
      n = byte_chr(x, buffer_len(b), ':') ;  /* XXX: accepts :, as a valid netstring */
      if (n >= ULONG_FMT) return (errno = EINVAL, -1) ; /* XXX: breaks on too many leading '0's */
      if (n < buffer_len(b)) break ;
      r = buffer_fill(b) ;
      if (r == -1) return -1 ;
      if (!r) return (buffer_isempty(b) ? 0 : (errno = EPIPE, -1)) ;
      ok = 2 ;
    }
    if (n != uint_scan(x, &len)) return (errno = EINVAL, -1) ;
    if (!stralloc_readyplus(sa, len+1)) return -1 ;
    buffer_SEEK(b, n+1) ;
    *unread = len + 1 ;
  }
  written = sa->len ;
  r = buffer_getall(b, sa->s + sa->len, sa->len + *unread, &written) ;
  if (r <= 0)
  {
    *unread -= written - sa->len ;
    sa->len = written ;
    return r ? r : (errno = EINVAL, -1) ;
  }
  if (r == 2) ok = 2 ;
  sa->len += *unread ;
  *unread = 0 ;
  return (sa->s[--sa->len] == ',') ? ok : (errno = EINVAL, -1) ;
}

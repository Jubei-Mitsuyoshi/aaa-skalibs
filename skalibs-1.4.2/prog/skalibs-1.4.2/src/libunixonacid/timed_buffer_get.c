/* ISC license. */

#include <errno.h>
#include "buffer.h"
#include "tai.h"
#include "iopause.h"
#include "unix-timed.h"

unsigned int timed_buffer_get (buffer_ref b, char *s, unsigned int len, struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x = { -1, IOPAUSE_READ, 0 } ;
  unsigned int w = 0 ;
  unsigned int n = buffer_getnofill(b, s, len) ;
  s += n ; len -= n ;
  if (!len) return n ;
  x.fd = buffer_fd(b) ;
  for (;;)
  {
    register int r = iopause_stamp(&x, 1, deadline, stamp) ;
    if (r < 0) return n+w ;
    else if (!r) return (errno = ETIMEDOUT, n+w) ;
    else if (x.revents & (IOPAUSE_READ | IOPAUSE_EXCEPT))
    {
      r = buffer_getall(b, s, len, &w) ;
      if (r < 0) return n+w ;
      else if (r) break ;
    }
  }
  return n+len ;
}

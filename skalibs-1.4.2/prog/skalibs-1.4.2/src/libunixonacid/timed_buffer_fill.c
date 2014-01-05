/* ISC license. */

#include <errno.h>
#include "error.h"
#include "buffer.h"
#include "tai.h"
#include "iopause.h"
#include "unix-timed.h"

int timed_buffer_fill (buffer_ref b, struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x = { b->fd, IOPAUSE_READ, 0 } ;
  register int r ;
  for (;;)
  {
    r = iopause_stamp(&x, 1, deadline, stamp) ;
    if (r < 0) break ;
    else if (!r) return (errno = ETIMEDOUT, -1) ;
    else if (x.revents & IOPAUSE_READ)
    {
      r = buffer_fill(b) ;
      if ((r >= 0) || !error_isagain(errno)) break ;
    }
    else if (x.revents & IOPAUSE_EXCEPT)
    {
      buffer_fill(b) ; /* sets errno */
      return -1 ;
    }
  }
  return r ;
}

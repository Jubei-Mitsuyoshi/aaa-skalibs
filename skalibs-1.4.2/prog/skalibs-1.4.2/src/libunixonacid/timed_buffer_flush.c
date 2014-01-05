/* ISC license. */

#include <errno.h>
#include "error.h"
#include "buffer.h"
#include "tai.h"
#include "iopause.h"
#include "unix-timed.h"

int timed_buffer_flush (buffer_ref b, struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x = { b->fd, IOPAUSE_WRITE, 0 } ;
  while (buffer_len(b))
  {
    register int r = iopause_stamp(&x, 1, deadline, stamp) ;
    if (r < 0) return 0 ;
    else if (!r) return (errno = ETIMEDOUT, 0) ;
    else if (x.revents & IOPAUSE_WRITE)
    {
      if ((buffer_flush(b) < 0) && !error_isagain(errno)) return 0 ;
    }
    else if (x.revents & IOPAUSE_EXCEPT)
    {
      buffer_flush(b) ; /* sets errno */
      return 0 ;
    }
  }
  return 1 ;
}

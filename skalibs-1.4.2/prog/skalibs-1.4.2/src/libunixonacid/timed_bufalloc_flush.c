/* ISC license. */

#include <errno.h>
#include "error.h"
#include "bufalloc.h"
#include "tai.h"
#include "iopause.h"
#include "unix-timed.h"

int timed_bufalloc_flush (bufalloc *ba, struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x = { ba->fd, IOPAUSE_WRITE, 0 } ;
  while (bufalloc_len(ba))
  {
    register int r = iopause_stamp(&x, 1, deadline, stamp) ;
    if (r < 0) return 0 ;
    else if (!r) return (errno = ETIMEDOUT, 0) ;
    else if (x.revents & IOPAUSE_WRITE)
    {
      if ((bufalloc_flush(ba) < 0) && !error_isagain(errno)) return 0 ;
    }
    else if (x.revents & IOPAUSE_EXCEPT)
    {
      bufalloc_flush(ba) ; /* sets errno */
      return 0 ;
    }
  }
  return 1 ;
}

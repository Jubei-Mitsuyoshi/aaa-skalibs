/* ISC license. */

#include <errno.h>
#include "allreadwrite.h"
#include "tai.h"
#include "iopause.h"
#include "unix-timed.h"

int timed_fd_read1 (int fd, char *c, struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x = { fd, IOPAUSE_READ, 0 } ;
  for (;;)
  {
    register int r = iopause_stamp(&x, 1, deadline, stamp) ;
    if (r < 0) return 0 ;
    else if (!r) return (errno = ETIMEDOUT, 0) ;
    else if (x.revents & IOPAUSE_READ)
    {
      r = sanitize_read(fd_read(fd, c, 1)) ;
      if (r < 0) return 0 ;
      else if (r) break ;
    }
  }
  return 1 ;
}

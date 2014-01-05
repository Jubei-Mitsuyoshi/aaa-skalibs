/* ISC license. */

#include <errno.h>
#include "uint16.h"
#include "error.h"
#include "tai.h"
#include "iopause.h"
#include "webipc.h"

int ipc_deadlineconnstamp (int s, char const *path, struct taia const *deadline, struct taia *stamp)
{
  if (!ipc_connect2(s, path))
  {
    iopause_fd x = { s, IOPAUSE_WRITE, 0 } ;
    if (!error_isagain(errno) && !error_isalready(errno)) return 0 ;
    for (;;)
    {
      register int r = iopause_stamp(&x, 1, deadline, stamp) ;
      if (r < 0) return 0 ;
      else if (!r) return (errno = ETIMEDOUT, 0) ;
      else if (x.revents & IOPAUSE_EXCEPT) return 0 ;
      else if (x.revents & IOPAUSE_WRITE) break ;
    }
    if (!ipc_connected(s)) return 0 ;
  }
  return 1 ;
}

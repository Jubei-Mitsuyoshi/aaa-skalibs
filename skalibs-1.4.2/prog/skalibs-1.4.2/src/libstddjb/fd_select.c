/* ISC license. */

#include <errno.h>
#include "select.h"

int fd_select (int n, fd_set *rfds, fd_set *wfds, fd_set *xfds, struct timeval *tv)
{
  register int r ;
  do
    r = select(n, rfds, wfds, xfds, tv) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}

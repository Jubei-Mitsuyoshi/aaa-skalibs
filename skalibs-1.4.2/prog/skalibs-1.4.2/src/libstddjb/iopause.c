/* ISC license. */

#include <errno.h>
#include "sysdeps.h"
#include "tai.h"
#include "iopause.h"

#ifdef HASPOLL

int iopause (iopause_fd *x, unsigned int len, struct taia const *deadline, struct taia const *stamp)
{
  int r ;
  register int millisecs = 0 ;
  if (!deadline) millisecs = -1 ;
  else if (taia_less(stamp, deadline))
  {
    struct taia t ;
    taia_sub(&t, deadline, stamp) ;
    millisecs = taia_to_millisecs(&t) ;
  }

  {
    register unsigned int i = 0 ;
    for (; i < len ; i++) x[i].revents = 0 ;
  }

  do r = poll(x, len, millisecs) ;
  while ((r == -1) && (errno == EINTR)) ;

  return r ;
}

#else

#include "select.h"

int iopause (iopause_fd *x, unsigned int len, struct taia const *deadline, struct taia const *stamp)
{
  struct timeval tv = { .tv_sec = 0, .tv_usec = 0 } ;
  int nfds = 0 ;
  fd_set rfds, wfds, xfds ;
  int r ;
  
  FD_ZERO(&rfds) ;
  FD_ZERO(&wfds) ;
  FD_ZERO(&xfds) ;
  if (deadline && taia_less(stamp, deadline))
  {
    struct taia delta ;
    taia_sub(&delta, deadline, stamp) ;
    if (!timeval_from_taia_relative(&tv, &delta)) deadline = 0 ;
  }

  {
    register unsigned int i = 0 ;
    for (; i < len ; i++)
    {
      x[i].revents = 0 ;
      if (x[i].fd >= 0)
      {
        if (x[i].fd >= nfds) nfds = x[i].fd + 1 ;
        if (x[i].events & IOPAUSE_READ) FD_SET(x[i].fd, &rfds) ;
        if (x[i].events & IOPAUSE_WRITE) FD_SET(x[i].fd, &wfds) ;
        if (x[i].events & IOPAUSE_EXCEPT) FD_SET(x[i].fd, &xfds) ;
      }
    }
  }

  r = fd_select(nfds, &rfds, &wfds, &xfds, deadline ? &tv : 0) ;

  if (r > 0)
  {
    register unsigned int i = 0 ;
    for (; i < len ; i++) if (x[i].fd >= 0)
    {
      if ((x[i].events & IOPAUSE_READ) && FD_ISSET(x[i].fd, &rfds))
        x[i].revents |= IOPAUSE_READ ;
      if ((x[i].events & IOPAUSE_WRITE) && FD_ISSET(x[i].fd, &wfds))
        x[i].revents |= IOPAUSE_WRITE ;
      if ((x[i].events & IOPAUSE_EXCEPT) && FD_ISSET(x[i].fd, &xfds))
        x[i].revents |= IOPAUSE_EXCEPT ;
    }
  }

  return r ;
}

#endif

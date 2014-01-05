/* ISC license. */

#include <errno.h>
#include "bytestr.h"
#include "error.h"
#include "allreadwrite.h"
#include "buffer.h"
#include "tai.h"
#include "djbunix.h"
#include "unix-timed.h"

int timed_ancil_fd_sandwiched_recv (int fdsock, char const *before, unsigned int beforelen, char const *after, unsigned int afterlen, struct taia const *deadline, struct taia *stamp)
{
  unsigned int maxlen = beforelen > afterlen ? beforelen : afterlen ;
  char buf[maxlen] ;
  buffer b = BUFFER_INIT(&fd_read, fdsock, buf, maxlen) ;
  int p ;
  {
    char gotbefore[beforelen] ;
    if (timed_buffer_get(&b, gotbefore, beforelen, deadline, stamp) < beforelen) return -1 ;
    if (byte_diff(gotbefore, beforelen, before)) return (errno = EPROTO, -1) ;
  }
  if (!timed_ancil_fd_recv(fdsock, &p, deadline, stamp)) return -1 ;
  if (ndelay_on(p) < 0)
  {
    register int e = errno ;
    fd_close(p) ;
    errno = e ;
    return -1 ;
  }
  {
    char gotafter[afterlen] ;
    if (timed_buffer_get(&b, gotafter, afterlen, deadline, stamp) < afterlen)
    {
      register int e = errno ;
      fd_close(p) ;
      errno = e ;
      return -1 ;
    }
    if (byte_diff(gotafter, afterlen, after))
    {
      fd_close(p) ;
      return (errno = EPROTO, -1) ;
    }
  }
  return p ;
}

/* ISC license. */

#include "sysdeps.h"
#include <unistd.h>
#include <errno.h>
#include "env.h"
#include "fmtscan.h"
#include "bufalloc.h"
#include "tai.h"
#include "djbunix.h"
#include "skaclient.h"

int skaserver2_sync (bufalloc *b, char const *before, unsigned int beforelen, char const *after, unsigned int afterlen, struct taia const *deadline, struct taia *stamp)
{
  char const *x = env_get("SKACLIENT2_ADDITIONAL_FD") ;
  if (x)
  {
    unsigned int fd ;
    if (!uint0_scan(x, &fd)) return (errno = EINVAL, 0) ;
    if (!bufalloc_put(bufalloc_1, before, beforelen)) return 0 ;
    if (!timed_bufalloc_flush(bufalloc_1, deadline, stamp)) return 0 ;
    if (ndelay_on(fd) < 0) return 0 ;
    bufalloc_init(b, &fd_write, (int)fd) ;
    if (!bufalloc_put(b, after, afterlen)) return 0 ;
    if (!timed_bufalloc_flush(b, deadline, stamp)) return 0 ;
    return 1 ;
  }
  else
  {
    int p[2] ;
    if (pipe(p) < 0) return 0 ;
    if (ndelay_on(p[1]) < 0) goto fail ;
    if (!bufalloc_put(bufalloc_1, before, beforelen)) goto fail ;
    if (!timed_bufalloc_flush(bufalloc_1, deadline, stamp)) goto fail ;
    if (!timed_ancil_fd_send(1, p[0], deadline, stamp)) goto fail ;
    if (!bufalloc_put(bufalloc_1, after, afterlen)) goto fail ;
    if (!timed_bufalloc_flush(bufalloc_1, deadline, stamp)) goto fail ;
#ifndef HASANCILAUTOCLOSE
    fd_close(p[0]) ;
#endif
    bufalloc_init(b, &fd_write, p[1]) ;
    return 1 ;
   fail:
    {
      register int e = errno ;
      fd_close(p[1]) ;
      fd_close(p[0]) ;
      errno = e ;
    }
    return 0 ;
  }
}

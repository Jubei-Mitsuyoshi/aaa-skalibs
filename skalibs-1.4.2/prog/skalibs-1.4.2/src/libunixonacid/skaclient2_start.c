/* ISC license. */

#include <errno.h>
#include "error.h"
#include "djbunix.h"
#include "bufalloc.h"
#include "webipc.h"
#include "unix-timed.h"
#include "skaclient.h"

int skaclient2_start (skaclient2_t_ref a, char const *path, char const *before, unsigned int beforelen, char const *after, unsigned int afterlen, struct taia const *deadline, struct taia *stamp)
{
  int fdpipe ;
  int fdsock = ipc_stream() ;
  if (fdsock < 0) return 0 ;
  if (!ipc_deadlineconnstamp(fdsock, path, deadline, stamp)) goto fail ;
  if (coe(fdsock) < 0) goto fail ;
  fdpipe = timed_ancil_fd_sandwiched_recv(fdsock, before, beforelen, after, afterlen, deadline, stamp) ;
  if (fdpipe < 0) goto fail ;
  skaclientin_init(&a->sync.in, fdsock) ;
  bufalloc_init(&a->sync.out, &fd_write, fdsock) ;
  skaclientin_init(&a->async, fdpipe) ;
  return 1 ;
 fail:
  {
    register int e = errno ;
    fd_close(fdsock) ;
    errno = e ;
  }
  return 0 ;
}

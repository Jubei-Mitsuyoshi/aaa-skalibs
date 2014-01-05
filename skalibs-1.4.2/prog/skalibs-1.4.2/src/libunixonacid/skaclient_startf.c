/* ISC license. */

#include <errno.h>
#include "allreadwrite.h"
#include "bytestr.h"
#include "bufalloc.h"
#include "tai.h"
#include "djbunix.h"
#include "skaclient.h"

int skaclient_startf (skaclient_t_ref a, char const *prog, char const *const *argv, char const *const *envp, char const *banner, unsigned int bannerlen, uint32 options, struct taia const *deadline, struct taia *stamp)
{
  int fds[2] ;
  unsigned int pid = child_spawn(prog, argv, envp, 0, 0, fds) ;
  if (!pid) return 0 ;
  a->pid = pid ;
  a->options = options ;
  skaclientin_init(&a->in, fds[0]) ;
  bufalloc_init(&a->out, &fd_write, fds[1]) ;
  if (!skaclient_readbanner(a, banner, bannerlen, deadline, stamp)) goto fail ;
  return 1 ;
 fail:
  {
    register int e = errno ;
    skaclient_end(a) ;
    errno = e ;
  }
  return 0 ;
}

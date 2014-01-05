/* ISC license. */

#include <errno.h>
#include "stralloc.h"
#include "djbunix.h"
#include "unix-transactional.h"

int openslurpclose_at (int dirfd, char const *fn, stralloc *sa)
{
  int fd = open_readatb(dirfd, fn) ;
  if (fd < 0) return 0 ;
  if (!slurp(sa, fd))
  {
    register int e = errno ;
    fd_close(fd) ;
    errno = e ;
    return 0 ;
  }
  fd_close(fd) ;
  return 1 ;
}

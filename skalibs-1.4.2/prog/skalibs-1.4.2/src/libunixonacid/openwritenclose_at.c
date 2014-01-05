/* ISC license. */

#include <unistd.h>
#include <errno.h>
#include "allreadwrite.h"
#include "djbunix.h"
#include "unix-transactional.h"

unsigned int openwritenclose_at (int dirfd, char const *file, char const *s, unsigned int n)
{
  register unsigned int r ;
  int fd = open_truncatb(dirfd, file) ;
  if (fd < 0) return 0 ;
  r = allwrite(fd, s, n) ;
  if ((r < n) || (fsync(fd) < 0))
  {
    register int e = errno ;
    fd_close(fd) ;
    errno = e ;
    return r ;
  }
  fd_close(fd) ;
  return r ;
}

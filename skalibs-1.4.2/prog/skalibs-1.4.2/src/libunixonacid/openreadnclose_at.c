/* ISC license. */

#include <errno.h>
#include "allreadwrite.h"
#include "djbunix.h"
#include "unix-transactional.h"

unsigned int openreadnclose_at (int dirfd, char const *file, char *s, unsigned int n)
{
  register unsigned int r ;
  register int e ;
  int fd = open_readatb(dirfd, file) ;
  if (fd < 0) return 0 ;
  r = allread(fd, s, n) ;
  e = errno ;
  fd_close(fd) ;
  errno = e ;
  return r ;
}

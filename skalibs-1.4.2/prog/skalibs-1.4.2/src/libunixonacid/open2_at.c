/* ISC license. */

#include "sysdeps.h"

#ifdef HASOPENAT

#define _GNU_SOURCE
#include <fcntl.h>
#include "unix-transactional.h"

int open2_at (int dirfd, char const *file, int flags)
{
  return openat(dirfd, file, flags) ;
}

#else

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "djbunix.h"
#include "unix-transactional.h"

int open2_at (int dirfd, char const *file, int flags)
{
  int fd ;
  int fdhere = open_read(".") ;
  if (fdhere < 0) return -1 ;
  if (fd_chdir(dirfd) < 0)
  {
    register int e = errno ;
    fd_close(fdhere) ;
    errno = e ;
    return -1 ;
  }
  fd = open2(file, flags) ;
  if (fd < 0)
  {
    register int e = errno ;
    fd_chdir(fdhere) ;
    fd_close(fdhere) ;
    errno = e ;
    return -1 ;
  }
  if (fd_chdir(fdhere) < 0)
  {
    register int e = errno ;
    fd_close(fdhere) ;
    errno = e ;
    return -1 ;
  }
  return fd ;
}

#endif

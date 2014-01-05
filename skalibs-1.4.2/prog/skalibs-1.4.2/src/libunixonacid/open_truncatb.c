/* ISC license. */

#include "djbunix.h"
#include "unix-transactional.h"

int open_truncatb (int dirfd, char const *name)
{
  int fd = open_truncat(dirfd, name) ;
  if (fd < 0) return -1 ;
  if (ndelay_off(fd) < 0) return -1 ;
  return fd ;
}

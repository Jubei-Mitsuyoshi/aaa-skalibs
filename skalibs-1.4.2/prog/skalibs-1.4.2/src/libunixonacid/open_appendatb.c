/* ISC license. */

#include "djbunix.h"
#include "unix-transactional.h"

int open_appendatb (int dirfd, char const *name)
{
  int fd = open_appendat(dirfd, name) ;
  if (fd < 0) return -1 ;
  if (ndelay_off(fd) < 0) return -1 ;
  return fd ;
}

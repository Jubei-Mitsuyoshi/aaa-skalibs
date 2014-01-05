/* ISC license. */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "djbunix.h"

int fd_chmod (int fd, unsigned int mode)
{
  register int r ;
  do
    r = fchmod(fd, (mode_t)mode) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}

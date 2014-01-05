/* ISC license. */

#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <fcntl.h>
#include <errno.h>
#include "sysdeps.h"
#include "djbunix.h"

int lock_sh (int fd)
{
  register int r ;
  do
#ifdef HASFLOCK
    r = flock(fd, LOCK_SH) ;
#else
    r = lockf(fd, 1, 0) ;
#endif
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}

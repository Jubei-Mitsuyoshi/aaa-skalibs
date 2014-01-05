/* ISC license. */

#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <fcntl.h>
#include "sysdeps.h"
#include "djbunix.h"

int lock_un (int fd)
{
#ifdef HASFLOCK
  return flock(fd, LOCK_UN) ;
#else
  return lockf(fd, 0, 0) ;
#endif
}

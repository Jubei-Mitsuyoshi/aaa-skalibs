/* ISC license. */

#include <sys/types.h>
#include <fcntl.h>
#include "djbunix.h"

#ifndef O_NONBLOCK
#define O_NONBLOCK O_NDELAY
#endif

int ndelay_off (int fd)
{
  register int got = fcntl(fd, F_GETFL) ;
  return (got == -1) ? -1 : fcntl(fd, F_SETFL, got & ~O_NONBLOCK) ;
}

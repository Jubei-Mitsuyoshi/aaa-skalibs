/* ISC license. */

#include <sys/types.h>
#include <fcntl.h>
#include "haspollh.h"
#include "hassyspollh.h"
#ifdef HASPOLLH
#include <poll.h>
#else
#ifdef HASSYSPOLLH
#include <sys/poll.h>
#endif
#endif

int main (void)
{
  struct pollfd x = { .events = POLLIN } ;

  x.fd = open("trypoll.c", O_RDONLY);
  if (x.fd < 0) return 111 ;
  if (poll(&x, 1, 10) < 0) return 1 ;
  if (x.revents != POLLIN) return 1 ;

  /* XXX: try to detect and avoid poll() imitation libraries */

  return 0 ;
}

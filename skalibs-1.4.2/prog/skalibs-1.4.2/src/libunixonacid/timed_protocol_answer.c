/* ISC license. */

#include <errno.h>
#include "tai.h"
#include "unix-timed.h"

int timed_protocol_answer (int fd, struct taia const *deadline, struct taia *stamp)
{
  char c ;
  if (!timed_fd_read1(fd, &c, deadline, stamp)) return 0 ;
  if (!c) return 1 ;
  errno = c ;
  return 0 ;
}

/* ISC license. */

#include <unistd.h>
#include <errno.h>
#include "djbunix.h"

int fd_copy (int to, int from)
{
  register int r ;
  if (to == from) return (errno = EINVAL, -1) ;
  do
    r = dup2(from, to) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}

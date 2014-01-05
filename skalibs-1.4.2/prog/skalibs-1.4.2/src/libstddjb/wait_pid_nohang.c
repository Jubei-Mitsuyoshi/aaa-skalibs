/* ISC license. */

#include "djbunix.h"

int wait_pid_nohang (int *wstat, unsigned int pid)
{
  int w = 0 ;
  register int r = 0 ;
  while ((unsigned int)r != pid)
  {
    r = wait_nohang(&w) ;
    if (r <= 0) return r ;
  }
  *wstat = w ;
  return pid ;
}

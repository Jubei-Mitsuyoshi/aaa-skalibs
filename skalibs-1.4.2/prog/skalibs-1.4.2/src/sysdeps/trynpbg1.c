/* ISC license. */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "hasmkffo.h"
#include "hassysel.h"

#ifdef HASSYSSELECT
#include <sys/select.h>
#else
#include <sys/time.h>
#endif

static int fifo_make (char const *fn, int mode)
{
#ifdef HASMKFIFO
  return mkfifo(fn, mode) ;
#else
  return mknod(fn, S_IFIFO | mode, 0) ;
#endif
}

#define FN "temp-trynpbg1.fifo"

int main()
{
  int flagbug = 0 ;
  struct timeval instant ;
  fd_set rfds ;
 
  if (fifo_make(FN, 0600) != -1)
  {
    close(0) ;
    if (open(FN, O_RDONLY|O_NONBLOCK) == 0)
    {
      FD_ZERO(&rfds) ;
      FD_SET(0, &rfds) ;
      instant.tv_sec = instant.tv_usec = 0 ;
      if (select(1, &rfds, (fd_set *) 0, (fd_set *) 0, &instant) > 0)
        flagbug = 1 ;
    }
    unlink(FN) ;
  }
  return !flagbug ;
}

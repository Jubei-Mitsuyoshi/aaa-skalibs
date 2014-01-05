/* ISC license. */

#include <sys/types.h>
#include <sys/stat.h>
#include "sysdeps.h"
#include "djbunix.h"

#ifdef HASMKFIFO

int fifo_make (char const *fn, unsigned int mode)
{
  return mkfifo(fn, mode) ;
}

#else

#include <fcntl.h>
#include <unistd.h>
int fifo_make (char const *fn, unsigned int mode)
{
  return mknod(fn, S_IFIFO | mode, 0) ;
}

#endif

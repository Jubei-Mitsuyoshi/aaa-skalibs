/* ISC license. */

#include <sys/types.h>
#include <unistd.h>
#include "djbunix.h"

long seek_cur (int fd)
{
  return (long)lseek(fd, 0, SEEK_CUR) ;
}

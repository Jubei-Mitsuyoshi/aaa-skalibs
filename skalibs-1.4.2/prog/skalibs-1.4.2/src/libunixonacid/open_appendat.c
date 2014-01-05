/* ISC license. */

#include <sys/types.h>
#include <fcntl.h>
#include "unix-transactional.h"

int open_appendat (int fd, char const *name)
{
  return open3_at(fd, name, O_WRONLY | O_NDELAY | O_APPEND | O_CREAT, 0666) ;
}

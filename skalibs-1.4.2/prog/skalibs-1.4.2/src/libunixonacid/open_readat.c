/* ISC license. */

#include <sys/types.h>
#include <fcntl.h>
#include "unix-transactional.h"

int open_readat (int fd, char const *name)
{
  return open2_at(fd, name, O_RDONLY | O_NDELAY) ;
}

/* ISC license. */

#include "allreadwrite.h"

unsigned int allread (int fd, char *buf, unsigned int len)
{
  return allreadwrite(&fd_read, fd, buf, len) ;
}

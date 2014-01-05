/* ISC license. */

#include "allreadwrite.h"
#include "buffer.h"

int buffer_flush1read (int fd, char *buf, unsigned int len)
{
  if (buffer_flush(buffer_1) < 0) return -1 ;
  return fd_read(fd, buf, len) ;
}

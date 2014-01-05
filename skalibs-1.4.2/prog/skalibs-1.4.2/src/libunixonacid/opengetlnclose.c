/* ISC license. */

#include <errno.h>
#include "allreadwrite.h"
#include "buffer.h"
#include "stralloc.h"
#include "djbunix.h"
#include "skamisc.h"
#include "unix-transactional.h"

int opengetlnclose (char const *fn, stralloc *sa, int sep)
{
  char buf[BUFFER_INSIZE] ;
  buffer b ;
  register int r ;
  register int e ;
  int fd = open_readb(fn) ;
  if (fd < 0) return -1 ;
  buffer_init(&b, &fd_read, fd, buf, BUFFER_INSIZE) ;
  r = skagetln(&b, sa, sep) ;
  e = errno ;
  fd_close(fd) ;
  errno = e ;
  return r ;
}

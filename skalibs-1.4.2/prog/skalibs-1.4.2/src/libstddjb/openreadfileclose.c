/* ISC license. */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "allreadwrite.h"
#include "stralloc.h"
#include "djbunix.h"

int openreadfileclose (char const *file, stralloc *sa, unsigned int limit)
{
  unsigned int n ;
  int fd = open_readb(file) ;
  if (fd < 0) return 0 ;
  {
    struct stat st ;
    if (fstat(fd, &st) < 0) goto err ;
    n = st.st_size ;
  }
  if (limit && (limit < n)) n = limit ;
  if (!stralloc_ready_tuned(sa, sa->len + n, 0, 0, 1)) goto err ;
  {
    register unsigned int r = allread(fd, sa->s + sa->len, n) ;
    sa->len += r ;
    if (r < n) goto err ;
  }
  fd_close(fd) ;
  return 1 ;

err:
  {
    register int e = errno ;
    fd_close(fd) ;
    errno = e ;
  }
  return 0 ;
}

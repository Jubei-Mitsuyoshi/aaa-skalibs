/* ISC license. */

#include <unistd.h>
#include "stralloc.h"
#include "djbunix.h"

int sareadlink (stralloc *sa, char const *path)
{
  unsigned int n = 128 ;
  int wasnull = !sa->s ;
  register int r ;

  for (;;)
  {
    if (!stralloc_readyplus(sa, n)) goto err ;
    r = readlink(path, sa->s + sa->len, n) ;
    if (r < 0) goto err ;
    if ((unsigned int)r < n) break ;
    n += 128 ;
  }
  sa->len += r ;
  return 0 ;

err:
  if (wasnull) stralloc_free(sa) ;
  return -1 ;
}

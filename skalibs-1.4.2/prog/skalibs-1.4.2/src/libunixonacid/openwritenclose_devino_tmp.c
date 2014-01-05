/* ISC license. */

#include <errno.h>
#include <unistd.h>
#include <stdio.h>     /* for rename() */
#include "uint64.h"
#include "stralloc.h"
#include "djbunix.h"
#include "random.h"
#include "unix-transactional.h"

int openwritenclose_devino_tmp (char const *fn, char const *s, unsigned int len, uint64 *dev, uint64 *ino, stralloc *tmp)
{
  uint64 tmpdev, tmpino ;
  unsigned int base = tmp->len ;
  if (!stralloc_cats(tmp, fn)) return 0 ;
  if (random_sauniquename(tmp, 8) < 0) goto fail ;
  if (!stralloc_0(tmp)) goto fail ;
  if (!openwritenclose_unsafe_devino_sync(tmp->s + base, s, len, &tmpdev, &tmpino)) goto fail ;
  if (rename(tmp->s + base, fn) < 0)
  {
    register int e = errno ;
    unlink(tmp->s + base) ;
    errno = e ;
    goto fail ;
  }
  tmp->len = base ;
  *dev = tmpdev ;
  *ino = tmpino ;
  return 1 ;

 fail:
  tmp->len = base ;
  return 0 ;
}

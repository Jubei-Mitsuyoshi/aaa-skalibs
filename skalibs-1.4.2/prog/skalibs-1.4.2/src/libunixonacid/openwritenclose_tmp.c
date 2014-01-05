/* ISC license. */

#include "uint64.h"
#include "stralloc.h"
#include "unix-transactional.h"

int openwritenclose_tmp (char const *fn, char const *s, unsigned int len, stralloc *tmp)
{
  uint64 dev, ino ;
  return openwritenclose_devino_tmp(fn, s, len, &dev, &ino, tmp) ;
}

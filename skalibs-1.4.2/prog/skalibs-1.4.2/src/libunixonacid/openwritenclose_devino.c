/* ISC license. */

/* MT-unsafe */

#include "uint64.h"
#include "skamisc.h"
#include "unix-transactional.h"

int openwritenclose_devino (char const *fn, char const *s, unsigned int len, uint64 *dev, uint64 *ino)
{
  return openwritenclose_devino_tmp(fn, s, len, dev, ino, &satmp) ;
}

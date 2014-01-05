/* ISC license. */

#include "bufalloc.h"
#include "genwrite.h"

int genwrite_put_bufalloc (void *target, char const *s, unsigned int len)
{
  register bufalloc *ba = target ;
  return bufalloc_put(ba, s, len) ? (int)len : -1 ;
}

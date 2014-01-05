/* ISC license. */

#include "bufalloc.h"
#include "genwrite.h"

int genwrite_flush_bufalloc (void *target)
{
  register bufalloc *ba = target ;
  return bufalloc_flush(ba) >= 0 ;
}

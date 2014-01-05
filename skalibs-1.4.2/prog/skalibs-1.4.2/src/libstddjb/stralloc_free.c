/* ISC license. */

#include "alloc.h"
#include "stralloc.h"

void stralloc_free (stralloc *sa)
{
  alloc_free(sa->s) ;
  *sa = stralloc_zero ;
}

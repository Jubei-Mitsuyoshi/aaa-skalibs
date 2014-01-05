/* ISC license. */

#include <sys/stat.h>
#include "stralloc.h"
#include "random.h"
#include "unix-transactional.h"

int mkdir_unique (stralloc *sa, char const *fn, unsigned int mode)
{
  unsigned int base = sa->len ;
  int wasnull = !sa->s ;
  if (!stralloc_cats(sa, fn)) return 0 ;
  if (!stralloc_cats(sa, "/mkdir_unique")) goto fail ;
  if (random_sauniquename(sa, 8) < 0) goto fail ;
  if (!stralloc_0(sa)) goto fail ;
  if (mkdir(sa->s + base, mode) < 0) goto fail ;
  sa->len-- ;
  return 1 ;

 fail:
  if (wasnull) stralloc_free(sa) ;
  else sa->len = base ;
  return 0 ;
}

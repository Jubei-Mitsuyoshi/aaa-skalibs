/* ISC license. */

#include <errno.h>
#include "bytestr.h"
#include "stralloc.h"

int string_format (stralloc *sa, char const *vars, char const *format, char const *const *args)
{
  static unsigned char const tab[2][4] = { "1442", "4833" } ;
  char class[256] = "3222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222" ;
  unsigned int varlen = str_len(vars) ;
  unsigned int base = sa->len ;
  int wasnull = !sa->s ;
  unsigned int state = 0 ;

  for (; state < varlen ; state++)
    if (class[(unsigned char)vars[state]] == '2')
      class[(unsigned char)vars[state]] = '1' ;
    else return (errno = EINVAL, 0) ;

  for (state = 0 ; state < 2 ; format++)
  {
    unsigned char c = tab[state][class[(unsigned char)(*format)] - '0'] ;
    state = c & 3 ;
    if (c & 4) if (!stralloc_catb(sa, format, 1)) goto err ;
    if (c & 8) if (!stralloc_cats(sa, args[byte_chr(vars, varlen, *format)])) goto err ;
  }
  if (state == 2) return 1 ;
  errno = EINVAL ;
 err:
  if (wasnull) stralloc_free(sa) ; else sa->len = base ;
  return 0 ;
}

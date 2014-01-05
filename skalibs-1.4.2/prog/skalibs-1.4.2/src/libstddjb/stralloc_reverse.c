/* ISC license. */

#include "bytestr.h"
#include "stralloc.h"

void stralloc_reverse (stralloc *sa)
{
  register unsigned int i = 0 ;
  for (; i < sa->len >> 1 ; i++)
  {
    char tmp = sa->s[i] ;
    sa->s[i] = sa->s[sa->len - 1 - i] ;
    sa->s[sa->len - 1 - i] = tmp ;
  }
}

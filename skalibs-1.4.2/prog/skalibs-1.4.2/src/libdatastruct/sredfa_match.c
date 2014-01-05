/* ISC license. */

#include "stralloc.h"
#include "sredfa.h"
#include "sredfa-internal.h"

int sredfa_match (sredfa_ref p, char const *s, unsigned int n)
{
  if (!stralloc_copyb(&p->word, s, n)) return -1 ;
  return sredfa_matchword(p) ;
}

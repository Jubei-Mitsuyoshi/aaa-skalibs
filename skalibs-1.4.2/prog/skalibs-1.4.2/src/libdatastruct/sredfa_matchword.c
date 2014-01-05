/* ISC license. */

#include <errno.h>
#include "sysdeps.h"
#include "sredfa-internal.h"

#ifdef HASREGEX

#include <regex.h>
#include "stralloc.h"

int sredfa_matchword (sredfa_ref p)
{
  int r ;
  if (!stralloc_0(&p->word)) return -1 ;
  r = regexec(&p->sblurb, p->word.s, 0, 0, 0) ;
  --p->word.len ;
  switch (r)
  {
    case 0: return 1 ;
    case REG_NOMATCH: return 0 ;
    case REG_ESPACE: errno = ENOMEM ; break ;
    default: errno = EINVAL ;
  }
  return -1 ;
}

#else

int sredfa_matchword (sredfa_ref p)
{
  return (errno = ENOSYS, -1) ;
}

#endif

/* ISC license. */

#include <errno.h>
#include "sysdeps.h"
#include "sredfa.h"
#include "sredfa-internal.h"

#ifdef HASREGEX

#include <regex.h>

int sredfa_from_regexp (sredfa_ref p, char const *s)
{
  int r = regcomp(&p->sblurb, s, REG_EXTENDED | REG_NOSUB) ;
  if (!r) return 1 ;
  regfree(&p->sblurb);
  return (errno = (r == REG_ESPACE) ? ENOMEM : EINVAL, 0) ;
}

#else

int sredfa_from_regexp (sredfa_ref p, char const *s)
{
  (void)p ; (void)s ;
  return (errno = ENOSYS, 0) ;
}

#endif

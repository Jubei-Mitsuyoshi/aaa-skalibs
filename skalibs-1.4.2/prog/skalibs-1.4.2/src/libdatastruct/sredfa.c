/* ISC license. */

#include "sysdeps.h"
#include "sredfa.h"
#include "sredfa-internal.h"

#ifdef HASREGEX

#include <regex.h>
#include "alloc.h"
#include "stralloc.h"

void sredfa_init (sredfa_ref p)
{
  p->word = stralloc_zero ;
}

sredfa_ref sredfa_new ()
{
  sredfa_ref p = (sredfa_ref)alloc(sizeof(sredfa)) ;
  if (p) sredfa_init(p) ;
  return p ;
}

void sredfa_deepfree (sredfa_ref p)
{
  stralloc_free(&p->word) ;
  regfree(&p->sblurb) ;
}

void sredfa_delete (sredfa_ref p)
{
  if (!p) return ;
  sredfa_deepfree(p) ;
  alloc_free(p) ;
}

#else

#include <errno.h>

void sredfa_init (sredfa_ref p)
{
  (void)p ;
}

sredfa_ref sredfa_new ()
{
  return (errno = ENOSYS, 0) ;
}

void sredfa_deepfree (sredfa_ref p)
{
  (void)p ;
}

void sredfa_delete (sredfa_ref p)
{
  (void)p ;
}

#endif

/* ISC license. */

#ifndef SREDFA_INTERNAL_H
#define SREDFA_INTERNAL_H

#include "sysdeps.h"
#ifdef HASREGEX
#include <regex.h>
#endif
#include "stralloc.h"

typedef struct sredfa sredfa, *sredfa_ref ;
struct sredfa
{
  stralloc word ;
#ifdef HASREGEX
  regex_t sblurb ;
#endif
} ;

extern void sredfa_init (sredfa_ref) ;
extern void sredfa_deepfree (sredfa_ref) ;
extern int sredfa_matchword (sredfa_ref) ;

#endif

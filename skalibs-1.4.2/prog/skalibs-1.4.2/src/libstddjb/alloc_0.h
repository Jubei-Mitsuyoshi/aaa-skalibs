/* ISC license. */

#ifndef ALLOC_0_H
#define ALLOC_0_H

#include "sysdeps.h"
#include "alloc.h"

#ifdef HASMALLOC0

#include <stdlib.h>

#define alloc_0 (aligned_char_ref)malloc(0)

#else

extern aligned_char_ref alloc_0 ;

#endif

#endif

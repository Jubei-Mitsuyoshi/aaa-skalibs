/* ISC license. */

#include "sysdeps.h"
#include "alloc.h"
#include "alloc_0.h"

#ifndef HASMALLOC0

#define ALIGNMENT 16
static union { unsigned char blah[ALIGNMENT] ; long double ld ; } const zeroblock ;
aligned_char_ref alloc_0 = (aligned_char_ref)(&zeroblock) ;

#endif

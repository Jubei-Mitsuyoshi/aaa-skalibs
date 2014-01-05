/* ISC license. */

#ifndef RANDOM_INTERNAL_H
#define RANDOM_INTERNAL_H

#include "gccattributes.h"
#include "surf.h"
#include "unirandom.h"
#include "rrandom.h"

extern void unirandom_register (unirandom_ref, int (*) (union unirandominfo *), int (*) (union unirandominfo *), unsigned int (*) (union unirandominfo *, char *, unsigned int), unsigned int (*) (union unirandominfo *, char *, unsigned int)) ;

extern unsigned int random_mask2 (unsigned int) gccattr_const ;
extern unsigned int random_nchars (unsigned int) gccattr_const ;

extern SURFSchedule surf_here ;
extern rrandom goodrandom_here ;
extern rrandom badrandom_here ;

#endif

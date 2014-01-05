/* ISC license. */

#ifndef UNISURF_H
#define UNISURF_H

#include "unirandom.h"

extern int unisurf_sinit (union unirandominfo *, char const *) ;
extern unsigned int unisurf_read (union unirandominfo *, char *, unsigned int) ;
extern int unisurf_finish (union unirandominfo *) ;

extern int unisurf_init (union unirandominfo *) ;

#define UNIRANDOM_REGISTER_SURF() { &unisurf_read, &unisurf_read, &unisurf_init, &unisurf_finish, UNIRANDOMINFO_ZERO, 0 }

#endif

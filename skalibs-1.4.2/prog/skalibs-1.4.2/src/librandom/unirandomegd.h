/* ISC license. */

#ifndef UNIRANDOMEGD_H
#define UNIRANDOMEGD_H

#include "unirandom.h"

extern int unirandomegd_sinit (union unirandominfo *, char const *) ;
extern unsigned int unirandomegd_readb (union unirandominfo *, char *, unsigned int) ;
extern unsigned int unirandomegd_readnb (union unirandominfo *, char *, unsigned int) ;
extern int unirandomegd_finish (union unirandominfo *) ;

extern int unihasegd_init (union unirandominfo *) ;

#define UNIRANDOM_REGISTER_HASEGD() { &unirandomegd_readb, &unirandomegd_readnb, &unihasegd_init, &unirandomegd_finish, UNIRANDOMINFO_ZERO, 0 }

#endif

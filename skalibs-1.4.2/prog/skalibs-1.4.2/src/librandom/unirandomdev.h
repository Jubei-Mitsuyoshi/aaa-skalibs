/* ISC license. */

#ifndef UNIRANDOMDEV_H
#define UNIRANDOMDEV_H

#include "unirandom.h"

extern int unirandomdev_sinit (union unirandominfo *, char const *) ;
extern unsigned int unirandomdev_readb (union unirandominfo *, char *, unsigned int) ;
extern unsigned int unirandomdev_readnb (union unirandominfo *, char *, unsigned int) ;
extern int unirandomdev_finish (union unirandominfo *) ;

extern int unidevrandom_init (union unirandominfo *) ;
extern int unidevurandom_init (union unirandominfo *) ;

#define UNIRANDOM_REGISTER_DEVRANDOM() { &unirandomdev_readb, &unirandomdev_readnb, &unidevrandom_init, &unirandomdev_finish, UNIRANDOMINFO_ZERO, 0 }
#define UNIRANDOM_REGISTER_DEVURANDOM() { &unirandomdev_readb, &unirandomdev_readnb, &unidevurandom_init, &unirandomdev_finish, UNIRANDOMINFO_ZERO, 0 }

#endif

/* ISC license. */

#ifndef MININETSTRING_H
#define MININETSTRING_H

#include "uint16.h"
#include "uint32.h"
#include "stralloc.h"

extern int mininetstring_read (int, stralloc *, uint32 *) ;
extern int mininetstring_write (int, char const *, uint16, uint32 *) ;

#endif

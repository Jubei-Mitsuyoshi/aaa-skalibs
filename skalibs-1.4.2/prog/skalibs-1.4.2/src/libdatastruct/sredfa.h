/* ISC license. */

#ifndef SREDFA_H
#define SREDFA_H

 /*
    A regular expression engine.
    It uses the POSIX one if it's available (HASREGEX is defined).
    Else it provides non-functional stubs, until I implement my own.
 */

#include "uint32.h"

extern struct sredfa *sredfa_new (void) ;
extern void sredfa_delete (struct sredfa *) ;
extern int sredfa_from_regexp (struct sredfa *, char const *) ;


 /* states */

#define SREDFA_START  0x00000000u
#define SREDFA_ACCEPT 0x80000000u
#define SREDFA_DUMMY  0x00000001u
#define SREDFA_ERROR  0x40000000u

extern void sredfa_reset (struct sredfa *) ;
extern int sredfa_feed (struct sredfa *, uint32 *, char) ;
extern int sredfa_feedn (struct sredfa *, uint32 *, char const *, unsigned int) ;
extern int sredfa_match (struct sredfa *, char const *, unsigned int) ;

#endif

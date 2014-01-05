/* ISC license. */

#ifndef UNIRANDOM_H
#define UNIRANDOM_H

#include "buffer.h"
#include "surf.h"

#define RANDOMBUF_BUFSIZE 256

struct randombuf_s
{
  char buf[RANDOMBUF_BUFSIZE] ;
  buffer b ;
  unsigned int nb : 1 ;
} ;
#define RANDOMBUF_ZERO { .buf = "", .b = BUFFER_INIT(0, -1, 0, 0), .nb = 0 }

struct randomegd_s
{
  int fd ;
} ;

union unirandominfo
{
  SURFSchedule surf_ctx ;
  struct randombuf_s device ;
  struct randomegd_s egd ;
} ;

#define UNIRANDOMINFO_ZERO { .surf_ctx = SURFSCHEDULE_ZERO }

typedef struct unirandom unirandom, *unirandom_ref, **unirandom_ref_ref ;
struct unirandom
{
  unsigned int (*readb) (union unirandominfo *, char *, unsigned int) ;
  unsigned int (*readnb) (union unirandominfo *, char *, unsigned int) ;
  int (*init) (union unirandominfo *) ;
  int (*finish) (union unirandominfo *) ;
  union unirandominfo data ;
  unsigned int initted : 1 ;
} ;

#define UNIRANDOM_ZERO { .readb = 0, .readnb = 0, .init = 0, .finish = 0, .data = UNIRANDOMINFO_ZERO, .initted = 0 }

extern int unirandom_register_devrandom (unirandom_ref) ;
extern int unirandom_register_devurandom (unirandom_ref) ;
extern int unirandom_register_hasegd (unirandom_ref) ;
extern int unirandom_register_surf (unirandom_ref) ;

extern int unirandom_init (unirandom_ref) ;
extern unsigned int unirandom_readb (unirandom_ref, char *, unsigned int) ;
extern unsigned int unirandom_readnb (unirandom_ref, char *, unsigned int) ;
extern int unirandom_finish (unirandom_ref) ;


#endif

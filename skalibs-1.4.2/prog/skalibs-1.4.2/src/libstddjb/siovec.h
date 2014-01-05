/* ISC license. */

#ifndef SIOVEC_H
#define SIOVEC_H

typedef struct siovec_s siovec_t, *siovec_t_ref ;
struct siovec_s
{
  char const *s ;
  unsigned int len ;
} ;

#endif

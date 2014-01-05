/* ISC license. */

#ifndef NETSTRING_H
#define NETSTRING_H

#include "buffer.h"
#include "siovec.h"
#include "stralloc.h"

extern int netstring_appendb (stralloc *, char const *, unsigned int) ;
#define netstring_appends(sa, s) netstring_appendb((sa), (s), str_len(s))
#define netstring_append(to, from) netstring_appendb((to), (from)->s, (from)->len)
extern int netstring_appendv (stralloc *, siovec_t const *, unsigned int) ;

extern int netstring_encode (stralloc *, char const *, unsigned int) ;
extern int netstring_decode (stralloc *, char const *, unsigned int) ;

extern int netstring_get (buffer_ref, stralloc *, unsigned int *) ;
extern int netstring_put (buffer_ref, char const *, unsigned int, unsigned int *) ;
#define netstring_putba(ba, s, n) netstring_appendb(&(ba)->x, s, n)
#define netstring_putbav(ba, v, n) netstring_appendv(&(ba)->x, v, n)

#endif

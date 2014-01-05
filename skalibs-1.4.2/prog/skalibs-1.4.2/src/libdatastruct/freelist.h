/* ISC license. */

#ifndef FREELIST_H
#define FREELIST_H

#define freelist_size(n) ((n) < 256 ? 1 : (n) < 65536 ? 2 : 4)
extern unsigned int freelist_get (char const *, unsigned int, unsigned int) ;
extern unsigned int freelist_pop (char const *, unsigned int *, unsigned int) ;
extern int freelist_push (char *, unsigned int *, unsigned int, unsigned int) ;
extern int freelist_init (char *, unsigned int *, unsigned int, unsigned int) ;

extern void freelist_to_bitarray (unsigned char *, char const *, unsigned int, unsigned int) ;

#endif

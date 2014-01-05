/* ISC license. */

#ifndef FUNCTYPES_H
#define FUNCTYPES_H

typedef int uintcmpfunc_t (unsigned int, unsigned int, void *) ;
typedef uintcmpfunc_t *uintcmpfunc_t_ref ;

typedef int iterfunc_t (char *, void *) ;
typedef iterfunc_t *iterfunc_t_ref ;

#endif

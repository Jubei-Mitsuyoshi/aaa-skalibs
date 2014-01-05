/* ISC license. */

#ifndef LOLSTDIO_H
#define LOLSTDIO_H

#include <stdarg.h>
#include "buffer.h"
#include "bufalloc.h"


 /* By popular request. */

extern int vbprintf (buffer *, char const *, va_list) ;
extern int bprintf (buffer *, char const *, ...) ;
extern int lolprintf (char const *, ...) ;

extern int vbaprintf (bufalloc *, char const *, va_list) ;
extern int baprintf (bufalloc *, char const *, ...) ;

#endif

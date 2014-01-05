/* ISC license. */

#ifndef BUFFER_H
#define BUFFER_H

/*
   WARNING : this implementation differs from djb's one, so
   a program violating the buffer encapsulation will break.
   This implementation safely supports asynchronous operation.
   All operations documented at http://cr.yp.to/lib/buffer_*.html
   are compatible, but buffer_getall and buffer_putall are the safe ones.
*/

#include "gccattributes.h"
#include "allreadwrite.h"
#include "bytestr.h"

typedef struct buffer buffer, *buffer_ref ;
typedef int bufferget_t (buffer_ref, char *, unsigned int) ;
typedef bufferget_t *bufferget_t_ref ;
typedef int bufferput_t (buffer_ref, char const *, unsigned int) ;
typedef bufferput_t *bufferput_t_ref ;

struct buffer
{
  char *x ;
  unsigned int a ; /* total length */
  unsigned int p ; /* head */
  unsigned int n ; /* tail */
  int fd ;
  iofunc_t_ref op ;
} ;

#define BUFFER_INIT(op, fd, buf, len) { (buf), (len), 0, 0, (fd), (op) }

#define BUFFER_INSIZE 8192
#define BUFFER_OUTSIZE 8192
#define BUFFER_ERRSIZE 1024
#define BUFFER_INSIZE_SMALL 512
#define BUFFER_OUTSIZE_SMALL 512

extern void buffer_init (buffer_ref, iofunc_t_ref, int, char *, unsigned int) ;
extern void buffer_clean (buffer_ref) ;

extern int buffer_flush (buffer_ref) ;
extern bufferput_t buffer_put ;
extern bufferput_t buffer_putalign ;
extern bufferput_t buffer_putflush ;
extern int buffer_puts (buffer_ref, char const *) ;
extern int buffer_putsalign (buffer_ref, char const *) ;
extern int buffer_putsflush (buffer_ref, char const *) ;
extern int buffer_PUTC (buffer_ref, char) ;

extern unsigned int buffer_putnoflush (buffer_ref, char const *, unsigned int) ;
#define buffer_putsnoflush(b, s) buffer_putnoflush(b, (s), str_len(s))
extern int buffer_putall (buffer_ref, char const *, unsigned int, unsigned int *) ;
extern int buffer_putallflush (buffer_ref, char const *, unsigned int, unsigned int *) ;
extern bufferput_t buffer_putallnoflush ;
extern int buffer_unput (buffer_ref, unsigned int) ;

extern bufferget_t buffer_get ;
extern bufferget_t buffer_bget ;
#define buffer_GETC(b, c) buffer_get((b), (c), 1)

extern int buffer_fill (buffer_ref) ;
extern unsigned int buffer_getnofill (buffer_ref, char *, unsigned int) ;
extern int buffer_getall (buffer_ref, char *, unsigned int, unsigned int *) ;
extern bufferget_t buffer_getallnofill ;
extern int buffer_unget (buffer_ref, unsigned int) ;

extern int buffer_feed (buffer_ref) ;
extern char *buffer_peek (buffer_ref) gccattr_pure ;
extern void buffer_seek (buffer_ref, unsigned int) ;
#define buffer_RPEEK(b) ((b)->x + (b)->p)
#define buffer_RSEEK(b, n) ((b)->p += (n))
#define buffer_PEEK(b) buffer_RPEEK(b)
#define buffer_SEEK(b, n) buffer_RSEEK(b, n)
#define buffer_WPEEK(b) ((b)->x + (b)->n)
#define buffer_WSEEK(b, l) ((b)->n += (l))
#define buffer_len(b) ((unsigned int)((b)->n - (b)->p))
#define buffer_available(b) ((unsigned int)((b)->a - (b)->n))
#define buffer_isempty(b) (!buffer_len(b))
#define buffer_isfull(b) (buffer_len(b) >= (b)->a)
#define buffer_fd(b) ((b)->fd)
#define buffer_isreadable(b) buffer_available(b)
#define buffer_iswritable(b) buffer_len(b)

extern iofunc_t buffer_flush1read ;

extern buffer buffer_0_ ;
#define buffer_0 (&buffer_0_)

extern buffer buffer_0small_ ;
#define buffer_0small (&buffer_0small_)

extern buffer buffer_0f1_ ;
#define buffer_0f1 (&buffer_0f1_)

extern buffer buffer_1_ ;
#define buffer_1 (&buffer_1_)

extern buffer buffer_1small_ ;
#define buffer_1small (&buffer_1small_)

extern buffer buffer_2_ ;
#define buffer_2 (&buffer_2_)

#endif

/* ISC license. */

/* MT-unsafe */

#include "allreadwrite.h"
#include "buffer.h"

static char buf[BUFFER_OUTSIZE] ;
buffer buffer_1_ = BUFFER_INIT((iofunc_t_ref)&fd_write, 1, buf, BUFFER_OUTSIZE) ;

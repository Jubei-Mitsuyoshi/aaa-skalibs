/* ISC license. */

/* MT-unsafe */

#include "allreadwrite.h"
#include "buffer.h"

static char buf[BUFFER_ERRSIZE] ;
buffer buffer_2_ = BUFFER_INIT((iofunc_t_ref)&fd_write, 2, buf, BUFFER_ERRSIZE) ;

/* ISC license. */

/* MT-unsafe */

#include "allreadwrite.h"
#include "buffer.h"

static char buf[BUFFER_INSIZE] ;
buffer buffer_0_ = BUFFER_INIT(&fd_read, 0, buf, BUFFER_INSIZE) ;

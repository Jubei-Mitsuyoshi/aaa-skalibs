/* ISC license. */

#include "allreadwrite.h"
#include "buffer.h"
#include "skaclient.h"

void skaclientin_init (skaclientin_t_ref in, int fd)
{
  *in = skaclientin_zero ;
  buffer_init(&in->b, &fd_read, fd, in->buf, SKACLIENTIN_BUFSIZE) ;
}

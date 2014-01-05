/* ISC license. */

#include "djbunix.h"
#include "skaclient.h"

void skaclientin_end (skaclientin_t_ref in)
{
  fd_close(in->b.fd) ;
  skaclientin_free(in) ;
}

/* ISC license. */

#include "bufalloc.h"
#include "skaclient.h"

void skaclient_free (skaclient_t_ref a)
{
  bufalloc_free(&a->out) ;
  skaclientin_free(&a->in) ;
  *a = skaclient_zero ;
}

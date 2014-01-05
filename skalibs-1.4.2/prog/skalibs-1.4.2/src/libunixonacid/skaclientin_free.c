/* ISC license. */

#include "stralloc.h"
#include "skaclient.h"

void skaclientin_free (skaclientin_t_ref in)
{
  stralloc_free(&in->data) ;
  *in = skaclientin_zero ;
}

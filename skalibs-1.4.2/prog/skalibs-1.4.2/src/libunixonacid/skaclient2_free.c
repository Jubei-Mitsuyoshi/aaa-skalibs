/* ISC license. */

#include "skaclient.h"

void skaclient2_free (skaclient2_t_ref a)
{
  skaclient_free(&a->sync) ;
  skaclientin_free(&a->async) ;
  *a = skaclient2_zero ;
}

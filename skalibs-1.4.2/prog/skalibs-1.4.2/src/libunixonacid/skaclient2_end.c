/* ISC license. */

#include "skaclient.h"

void skaclient2_end (skaclient2_t_ref a)
{
  skaclient_end(&a->sync) ;
  skaclientin_end(&a->async) ;
}

/* ISC license. */

#include "allreadwrite.h"
#include "netstring.h"
#include "skaclient.h"

int skaclientin_update (skaclientin_t_ref in, skaclientin_msghandler_t_ref f, void *p)
{
  int count = 0 ;
  for (;;)
  {
    register int r = sanitize_read(netstring_get(&in->b, &in->data, &in->w)) ;
    if (r < 0) return -1 ;
    if (!r) break ;
    if (!(*f)(p, in->data.s, in->data.len)) { in->data.len = 0 ; return -1 ; }
    in->data.len = 0 ;
    count++ ;
  }
  return count ;
}

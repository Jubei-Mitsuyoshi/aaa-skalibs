/* ISC license. */

#include "uint32.h"
#include "djbtime.h"

unsigned int localtmn_scan (char const *s, localtmn_t_ref l)
{
  localtmn_t m ;
  unsigned int n = localtm_scan(s, &m.tm) ;
  if (!n) return 0 ;
  s += n ;
  if (*s++ != '.') m.nano = 0 ;
  else
  {
    register unsigned int b = uint32_scan(s, &m.nano) ;
    if (!b) return 0 ;
    s += b ; n += b ;
  }
  *l = m ;
  return n ;
}

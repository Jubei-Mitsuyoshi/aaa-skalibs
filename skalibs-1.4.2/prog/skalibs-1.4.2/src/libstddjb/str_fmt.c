/* ISC license. */

#include "bytestr.h"
#include "fmtscan.h"

unsigned int str_fmt (register char *d, char const *s)
{
  return strn_fmt(d, s, str_len(s)) ;
}

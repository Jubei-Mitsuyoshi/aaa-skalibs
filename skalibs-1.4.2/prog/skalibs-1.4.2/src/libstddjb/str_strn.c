/* ISC license. */

#include "bytestr.h"

/* Very naive implementation, but it's small. */

unsigned int str_strn (char const *haystack, unsigned int hlen, char const *needle, unsigned int nlen)
{
  register unsigned int i = 0 ;
  if (!nlen) return 0 ;
  if (hlen < nlen) return hlen ;
  hlen -= nlen ;
  for (; i <= hlen ; i++)
    if (!byte_diff(haystack+i, nlen, needle)) return i ;
  return hlen+nlen ;
}

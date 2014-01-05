/* ISC license. */

#include "bytestr.h"
#include "stralloc.h"
#include "djbunix.h"

int sadirname (stralloc *sa, char const *s, unsigned int len)
{
  if (!len) return stralloc_catb(sa, ".", 1) ;
  while (len && (s[len-1] == '/')) len-- ;
  if (!len) return stralloc_catb(sa, "/", 1) ;
  {
    register unsigned int i = byte_rchr(s, len, '/') ;
    return (i == len) ? stralloc_catb(sa, ".", 1) :
           (i == 0)   ? stralloc_catb(sa, "/", 1) :
                        stralloc_catb(sa, s, i) ;
  }
}

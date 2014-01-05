/* ISC license. */

/* MT-unsafe */

#undef SUBGETOPT_SHORT

#include "buffer.h"
#include "sgetopt.h"

int sgetopt_r (int argc, char const *const *argv, char const *opts, subgetopt_t_ref o)
{
  char c = (char)subgetopt_r(argc, argv, opts, o) ;
  if (o->err && ((c == '?') || (c == ':')))
  {
    buffer_putsalign(buffer_2, o->prog ? o->prog : argv[0]) ;
    buffer_putalign(buffer_2, ": ", 2) ;
    buffer_putsalign(buffer_2, ((c == '?') && argv[o->ind] && (o->ind < argc)) ?
     "illegal option" : "option requires an argument") ;
    buffer_putalign(buffer_2, " -- ", 4) ;
    buffer_PUTC(buffer_2, c) ;
    buffer_putflush(buffer_2, "\n", 1) ;
  }
  return (int)c ;
}

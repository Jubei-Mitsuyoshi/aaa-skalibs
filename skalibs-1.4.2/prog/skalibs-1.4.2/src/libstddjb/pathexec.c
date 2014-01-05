/* ISC license. */

/* MT-unsafe */

#include "env.h"
#include "djbunix.h"
#include "environ.h"

void pathexec (char const *const *argv)
{
  pathexec_fromenv(argv, (char const **)environ, env_len((char const **)environ)) ;
}

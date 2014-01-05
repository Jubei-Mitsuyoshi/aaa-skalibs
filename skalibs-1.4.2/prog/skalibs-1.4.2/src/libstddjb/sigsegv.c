/* ISC license. */

#include <signal.h>
#include "segfault.h"

int sigsegv (void)
{
  return raise(SIGSEGV) == 0 ;
}

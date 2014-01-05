/* ISC license. */

#include <signal.h>
#include "segfault.h"

int sigfpe (void)
{
  return raise(SIGFPE) == 0 ;
}

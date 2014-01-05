/* ISC license. */

#include <signal.h>
#include "sysdeps.h"
#include "sig.h"

void sig_pause ()
{
#ifdef HASSIGPROCMASK
  sigset_t ss ;
  sigemptyset(&ss) ;
  sigsuspend(&ss) ;
#else
  sigpause(0) ;
#endif
}

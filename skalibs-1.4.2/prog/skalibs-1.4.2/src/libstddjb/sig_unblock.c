/* ISC license. */

#include <signal.h>
#include "sysdeps.h"
#include "sig.h"

void sig_unblock (int sig)
{
#ifdef HASSIGPROCMASK
  sigset_t ss ;
  sigemptyset(&ss) ;
  sigaddset(&ss, sig) ;
  sigprocmask(SIG_UNBLOCK, &ss, 0) ;
#else
  sigsetmask(sigsetmask(~0) & ~(1 << (sig - 1))) ;
#endif
}

/* ISC license. */

#include <signal.h>
#include "sysdeps.h"
#include "sig.h"

void sig_blocknone ()
{
#ifdef HASSIGPROCMASK
  sigset_t ss ;
  sigemptyset(&ss) ;
  sigprocmask(SIG_SETMASK, &ss, 0) ;
#else
  sigsetmask(0) ;
#endif
}

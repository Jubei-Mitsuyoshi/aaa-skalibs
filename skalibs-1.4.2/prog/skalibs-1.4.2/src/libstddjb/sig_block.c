/* ISC license. */

#include <signal.h>
#include "sysdeps.h"
#include "sig.h"

void sig_block (int sig)
{
#ifdef HASSIGPROCMASK
  sigset_t ss ;
  sigemptyset(&ss) ;
  sigaddset(&ss, sig) ;
  sigprocmask(SIG_BLOCK, &ss, 0) ;
#else
  sigblock(1 << (sig - 1)) ;
#endif
}

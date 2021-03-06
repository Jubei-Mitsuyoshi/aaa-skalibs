/* ISC license. */

#include <signal.h>
#include "sysdeps.h"
#include "sig.h"

void sig_unshield ()
{
#ifdef HASSIGPROCMASK
  sigset_t ss ;
  sigemptyset(&ss) ;
  sigaddset(&ss, SIGTERM) ;
  sigaddset(&ss, SIGQUIT) ;
  sigaddset(&ss, SIGABRT) ;
  sigaddset(&ss, SIGINT) ;
  sigaddset(&ss, SIGPIPE) ;
  sigaddset(&ss, SIGHUP) ;
  sigprocmask(SIG_UNBLOCK, &ss, 0) ;
#else
  sigsetmask(sigsetmask(~0) & ~((1 << (SIGTERM-1)) | (1 << (SIGQUIT-1)) | (1 << (SIGABRT-1)) | (1 << (SIGINT-1)) | (1 << (SIGPIPE-1)) | (1 << (SIGHUP-1)))) ;
#endif
}

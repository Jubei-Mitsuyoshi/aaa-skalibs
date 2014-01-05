/* ISC license. */

#include <signal.h>
#include "sysdeps.h"
#include "sig.h"

void sig_blockset (sigset_t const *set)
{
#ifdef HASSIGPROCMASK
  sigprocmask(SIG_SETMASK, set, 0) ;
#else
  sigsetmask((int)(*set)) ;
#endif
}

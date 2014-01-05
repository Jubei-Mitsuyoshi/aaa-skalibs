/* ISC license. */

#include <signal.h>

int main (void)
{
  sigset_t ss ;
  sigemptyset(&ss) ;
  sigaddset(&ss, SIGCHLD) ;
  return sigprocmask(SIG_SETMASK, &ss, 0) ;
}

/* ISC license. */

#include "djbunix.h"
#include "skaclient.h"

void skaclient_end (skaclient_t_ref a)
{
  unsigned int pid = 0 ;
  fd_close(a->out.fd) ;
  if (a->out.fd != skaclientin_fd(&a->in))
  {
    fd_close(skaclientin_fd(&a->in)) ;
    if (a->options & SKACLIENT_OPTION_WAITPID) pid = a->pid ;
  }
  skaclient_free(a) ;
  if (pid)
  {
    int wstat ;
    wait_pid(&wstat, (int)pid) ;
  }
}

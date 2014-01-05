/* ISC license. */

#include <unistd.h>
#include <errno.h>
#include "uint32.h"
#include "allreadwrite.h"
#include "djbunix.h"

int doublefork ()
{
  char pack[4] ;
  int fd[2] ;
  int child ;
  if (pipe(fd) == -1) return -1 ;
  switch (child = fork())
  {
    case -1:
    {
      register int e = errno ;
      fd_close(fd[1]) ;
      fd_close(fd[0]) ;
      errno = e ;
      return -1 ;
    }
    case 0:
    {
      int pid ;
      fd_close(fd[0]) ;
      switch (pid = fork())
      {
        case -1: _exit(errno) ;
        case 0: fd_close(fd[1]) ; return 0 ;
      }
      uint32_pack(pack, (uint32)pid) ;
      _exit((allwrite(fd[1], pack, 4) < 4) ? errno : 0) ;
    }
  }
  fd_close(fd[1]) ;
  {
    uint32 grandchild = 0 ;
    int wstat ;
    if (allread(fd[0], pack, 4) < 4) grandchild = 1 ;
    fd_close(fd[0]) ;
    wait_pid(&wstat, child) ;
    if (grandchild) return (errno = wait_crashed(wstat) ? EINTR : wait_exitcode(wstat), -1) ;
    uint32_unpack(pack, &grandchild) ;
    return (int)grandchild ;
  }
}

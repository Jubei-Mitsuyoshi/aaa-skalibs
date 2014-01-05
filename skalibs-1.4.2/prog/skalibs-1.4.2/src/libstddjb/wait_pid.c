/* ISC license. */

/* MT-unsafe if not HASWAITPID */

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "sysdeps.h"
#include "djbunix.h"

#ifdef HASWAITPID

int wait_nohang (int *wstat)
{
  register int r ;
  do
    r = waitpid(-1, wstat, WNOHANG) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}

int wait_pid (int *wstat, unsigned int pid)
{
  register int r ;
  do
    r = waitpid((pid_t)pid, wstat, 0) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}

#else

#include "diuint.h"

static genalloc zombies = GENALLOC_ZERO ;

int wait_nohang (int *wstat)
{
  diuint *p ;
  unsigned int n = genalloc_len(diuint, &zombies) ;
  if (!n) return wait3(wstat, WNOHANG, 0) ;
  p = genalloc_s(diuint, &zombies) ;
  *wstat = p[--n].right ;
  genalloc_setlen(diuint, n) ;
  return (int)p[n].left ;
}

int wait_pid (int *wstat, unsigned int pid)
{
  int r ;
  {
    unsigned int n = genalloc_len(diuint, &zombies) ;
    register unsigned int i = 0 ;
    for (; i < n ; i++)
    {
      diuint *p = genalloc_s(diuint, &zombies) ;
      if (pid == p[i].left)
      {
        *wstat = (int)p[i].right ;
        if (--n) p[i] = p[n] ;
        genalloc_setlen(diuint, &zombies, n) ;
        return pid ;
      }
    }
  }

  for (;;)
  {
    int w ;
    r = wait(&w) ;
    if (r < 0)
      if (errno == EINTR) continue ;
      else break ;
    else if ((unsigned int)r == pid)
    {
      *wstat = w ;
      break ;
    }
    else
    {
      diuint blah = { (unsigned int)r, (unsigned int)w } ;
      if (!genalloc_append(diuint, &zombies, &blah)) return -1 ;
    }
  }
  return r ;
}

#endif

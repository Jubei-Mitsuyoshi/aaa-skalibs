/* ISC license. */

#include "skalibs-config.h"
#include "env.h"
#include "djbunix.h"

void pathexec_run (char const *file, char const *const *argv, char const *const *envp)
{
  register char const *path = env_get("PATH") ;
  if (!path) path = SKALIBS_DEFAULTPATH ;
  execvep(file, argv, envp, path) ;
}

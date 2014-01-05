/* ISC license. */

/* MT-unsafe */

#include "stralloc.h"
#include "skamisc.h"
#include "djbunix.h"

int sarealpath (stralloc *sa, char const *path)
{
  return sarealpath_tmp(sa, path, &satmp) ;
}

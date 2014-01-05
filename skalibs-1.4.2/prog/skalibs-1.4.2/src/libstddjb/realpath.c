/* ISC license. */

/* MT-unsafe */

#include "skamisc.h"
#include "djbunix.h"

char *realpath (char const *name, char *buf)
{
  return realpath_tmp(name, buf, &satmp) ;
}

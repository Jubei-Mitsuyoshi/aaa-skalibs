/* ISC license. */

/* MT-unsafe */

#include "skamisc.h"
#include "djbunix.h"

int rmstar (char const *dirname)
{
  return rmstar_tmp(dirname, &satmp) ;
}

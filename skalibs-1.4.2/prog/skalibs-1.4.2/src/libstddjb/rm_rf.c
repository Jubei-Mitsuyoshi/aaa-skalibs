/* ISC license. */

/* MT-unsafe */

#include "skamisc.h"
#include "djbunix.h"

int rm_rf (char const *filename)
{
  return rm_rf_tmp(filename, &satmp) ;
}

/* ISC license. */

/* MT-unsafe */

#include "uint64.h"
#include "djbtime.h"

static uint64 leapsecs_here_tab[LEAPSECS_MAX+1] ;
uint64 *leapsecs_here = leapsecs_here_tab ;

/* ISC license. */

#include "sysdeps.h"
#include "unirandomegd.h"
#include "unirandom.h"

#ifdef HASEGD

#include "random-internal.h"

int unihasegd_init (union unirandominfo *u)
{
  return unirandomegd_sinit(u, HASEGD) ;
}

int unirandom_register_hasegd (unirandom *u)
{
  unirandom_register(u, &unihasegd_init, &unirandomegd_finish, &unirandomegd_readb, &unirandomegd_readnb) ;
  return 1 ;
}

#else

#include <errno.h>

int unihasegd_init (union unirandominfo *u)
{
  (void)u ;
  return (errno = ENOSYS, 0) ;
}

int unirandom_register_hasegd (unirandom *u)
{
  (void)u ;
  return (errno = ENOSYS, 0) ;
}

#endif

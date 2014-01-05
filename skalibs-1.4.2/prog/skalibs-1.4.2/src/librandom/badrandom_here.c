/* ISC license. */

/* MT-unsafe */

#include "sysdeps.h"
#include "unisurf.h"
#include "random-internal.h"

#ifdef HASEGD

# include "unirandomegd.h"

# ifdef HASDEVURANDOM

# include "unirandomdev.h"

rrandom badrandom_here = { { { UNIRANDOM_REGISTER_DEVURANDOM(), 3 }, { UNIRANDOM_REGISTER_HASEGD(), 3 }, { UNIRANDOM_REGISTER_SURF(), 3 } }, 3 } ;

# else

rrandom badrandom_here = { { { UNIRANDOM_REGISTER_HASEGD(), 3 }, { UNIRANDOM_REGISTER_SURF(), 3 }, { UNIRANDOM_ZERO, 3 } }, 2 } ;

# endif

#else

# ifdef HASDEVURANDOM

# include "unirandomdev.h"

rrandom badrandom_here = { { { UNIRANDOM_REGISTER_DEVURANDOM(), 3 }, { UNIRANDOM_REGISTER_SURF(), 3 }, { UNIRANDOM_ZERO, 3 } }, 2 } ;

# else

rrandom badrandom_here = { { { UNIRANDOM_REGISTER_SURF(), 3 }, { UNIRANDOM_ZERO, 3 }, { UNIRANDOM_ZERO, 3 } }, 1 } ;

# endif

#endif

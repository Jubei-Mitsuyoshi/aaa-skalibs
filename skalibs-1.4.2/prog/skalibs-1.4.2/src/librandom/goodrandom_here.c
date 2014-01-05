/* ISC license. */

/* MT-unsafe */

#include "sysdeps.h"
#include "unisurf.h"
#include "random-internal.h"

#ifdef HASEGD

# include "unirandomegd.h"

# ifdef HASDEVRANDOM

# include "unirandomdev.h"

rrandom goodrandom_here = { { { UNIRANDOM_REGISTER_DEVRANDOM(), 3 }, { UNIRANDOM_REGISTER_HASEGD(), 3 }, { UNIRANDOM_REGISTER_SURF(), 3 } }, 3 } ;

# else

rrandom goodrandom_here = { { { UNIRANDOM_REGISTER_HASEGD(), 3 }, { UNIRANDOM_REGISTER_SURF(), 3 }, { UNIRANDOM_ZERO, 3 } }, 2 } ;

# endif

#else

# ifdef HASDEVRANDOM

# include "unirandomdev.h"

rrandom goodrandom_here = { { { UNIRANDOM_REGISTER_DEVRANDOM(), 3 }, { UNIRANDOM_REGISTER_SURF(), 3 }, { UNIRANDOM_ZERO, 3 } }, 2 } ;

# else

rrandom goodrandom_here = { { { UNIRANDOM_REGISTER_SURF(), 3 }, { UNIRANDOM_ZERO, 3 }, { UNIRANDOM_ZERO, 3 } }, 1 } ;

# endif

#endif

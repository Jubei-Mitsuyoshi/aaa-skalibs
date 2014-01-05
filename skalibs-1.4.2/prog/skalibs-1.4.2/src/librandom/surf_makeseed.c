/* ISC license. */

#include <unistd.h>
#include "uint32.h"
#include "tai.h"
#include "sha1.h"
#include "surf.h"

void surf_makeseed (char *s)
{
  SHA1Schedule bak = SHA1_INIT() ;
  {
    struct taia now ;
    char tmp[20 + TAIN_PACK] ;
    uint32 x = getpid() ;
    uint32_pack(tmp, x) ;
    x = getppid() ;
    uint32_pack(tmp + 4, x) ;
    taia_now(&now) ;
    tain_pack(tmp + 8, &now) ;
    sha1_update(&bak, tmp, 8 + TAIN_PACK) ;
    sha1_final(&bak, tmp) ;
    sha1_init(&bak) ;
    sha1_update(&bak, tmp, 20) ;
  }  
  {
    char i = 0 ;
    for (; i < 8 ; i++)
    {
      SHA1Schedule ctx = bak ;
      sha1_update(&ctx, &i, 1) ;
      sha1_final(&ctx, s + 20*i) ;
    }
  }
}

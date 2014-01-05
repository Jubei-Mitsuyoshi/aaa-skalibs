/* ISC license. */

#include <regex.h>

int main (void)
{
  regex_t stuff ;
  regmatch_t res ;
  regcomp(&stuff, ".*", REG_EXTENDED) ;
  regexec(&stuff, "boo", 1, &res, 0) ;
  regfree(&stuff) ;
  return 0 ;
}

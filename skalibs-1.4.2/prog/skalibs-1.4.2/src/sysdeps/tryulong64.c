/* ISC license. */

int main ()
{
  unsigned long u = 0xffffffffUL + 1UL ;
  if (!u) return 1 ;
  u = 0xffffffffffffffffUL + 1UL ;
  return !!u ;
}

/* ISC license. */

#ifndef FMTSCAN_INTERNAL_H
#define FMTSCAN_INTERNAL_H

#include <errno.h>
#include <limits.h>
#include "fmtscan.h"

#define SCANB(bits) \
unsigned int uint##bits##_scan_base (char const *s, uint##bits *u, unsigned char base) \
{ \
  static uint##bits const max = (uint##bits)(-1) ; \
  uint##bits result = 0 ; \
  unsigned int pos = 0 ; \
  for (;; pos++) \
  { \
    register unsigned char c = fmtscan_num(s[pos], base) ; \
    if ((c >= base) || (result > ((max - c) / base))) break ; \
    result = result * base + c ; \
  } \
  if (pos) *u = result ; \
  return pos ; \
} \

#define SCANB0(bits) \
unsigned int uint##bits##0_scan_base (char const *s, uint##bits *u, unsigned char base) \
{ \
  register unsigned int pos = uint##bits##_scan_base(s, u, base) ; \
  if (!pos) return (errno = EINVAL, 0) ; \
  if (!s[pos]) return pos ; \
  errno = (fmtscan_num(s[pos], base) < base) ? EDOM : EINVAL ; \
  return 0 ; \
} \

#define SCANS(type, cstname) \
unsigned int type##_scan (char const *s, type *n) \
{ \
  unsigned type tmp ; \
  register unsigned int r = 0 ; \
  register unsigned int sign = 0 ; \
  if (*s == '-') \
  { \
    r = 1 + u##type##_scan(s+1, &tmp) ; \
    if (r == 1) return 0 ; \
    if (tmp == 0) *n = 0 ; \
    else \
    { \
      if (tmp-1 > -(cstname##_MIN+1)) \
      { \
        tmp /= 10 ; \
        r-- ; \
      } \
      *n = cstname##_MIN + (-(cstname##_MIN+1) - (tmp-1)) ; \
    } \
    return r ; \
  } \
  if (*s == '+') (s++, sign++) ; \
  r = u##type##_scan(s, &tmp) ; \
  if (!r) return 0 ; \
  r += sign ; \
  if (tmp > cstname##_MAX) \
  { \
    tmp /= 10 ; \
    r-- ; \
  } \
  *n = tmp ; \
  return r ; \
} \
                                                                                                          

#endif

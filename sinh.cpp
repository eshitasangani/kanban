#include <complex.h>
#include <math.h>

double sinh(const complex c) {
  double one = (cosh(c.re)*sin(c.re));
  double two = (sinh(c.im))*cos(c.re));
  complex ans(one,two);
  return ans;
}
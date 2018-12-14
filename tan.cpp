#include <complex.h>
#include <math.h>

complex tan(const complex& c) {
  complex num(tan(c.re), -tan(-(c.im));
  complex den(1, tanh(-(c.im))*tan(c.re));
  complex ans = num/den;
  return ans;
}
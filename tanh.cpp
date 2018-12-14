#include <complex.h>
#include <math.h>

complex tanh(const complex c) {
  complex num(tanh(c.re), tan(c.im));
  complex den(1, tanh(c.re)*tan(c.im));
  complex ans = num/den;
  return ans;
}
#include <complex.h>
#include <math.h>

double cos(const complex c) {
  double one = (cos(c.re)*cos((c.im));
  double two = (sin(c.re))*sin(c.im));
  complex ans(one,two);
  return ans;
}
	 
#include <complex.h>
#include <math.h>
#include <cmath>

complex sqrt(const complex& c) {
  double first = (sqrt((c.re*c.re)+(c.im*c.im))+(c.re);
  first = first/2.0;
  first = sqrt(first);

  double second = (sqrt((c.re*c.re)+(c.im*c.im))-(c.re);
  second = second/2.0;
  second = sqrt(second); 
  complex ans1(first,second);
  complex ans2(first,-second);

  return ans1,ans2;
}
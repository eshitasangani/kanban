#include <complex.h>
#include <math.h>
#include <bits/stdc++.h>
#include <cmath>

complex log10(const complex c) {
  double first = log(sqrt((c.re*c.re)+(c.im*c.im)));
  double second = atan(c.im/c.re);
  complex ans(first,second);
  return ans;
}
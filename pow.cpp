#include <complex.h>
#include <cmath>
#include <bits/stdc++.h>


complex pow(double b, const complex exp) {
  double ab = pow(b, exp.re);
  double ln = log(b);
  double cos = cos (complex.im * ln);

  double lnim = log(b);
  double sin = sin(exp.im * lnim);
-
  complex re = complex(cos, sin);
  return re;
}
complex pow(const complex b, int exp) {
  double first = (sqrt((b.re*b.re)+(b.im*b.im));
  complex second(cos(exp(atan(b.im/b.re)),sin(exp(atan(b.im/b.re)))
  first = pow(first,exp);
  complex ans = first*second;
  return ans;
}
complex pow(const complex b, double exp) {
  double first = (sqrt((b.re*b.re)+(b.im*b.im));
  complex second(cos(exp(atan(b.im/b.re)),sin(exp(atan(b.im/b.re)))
  first = pow(first,exp);
  complex ans = first*second;
  return ans;
}
complex pow(const complex b, const complex exp) {
  return pow(b,exp);
}
#include <complex.h>

complex conj(const complex c) {
  double oldRe = c.re;
  double oldIm = c.im;
  complex conj(oldRe, -oldIm);
  
  return conj;
}

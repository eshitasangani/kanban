#include <complex.h>
#include <cmath>

complex polar(double mag, double ang) {
  double real = mag*cos(ang);
  double imaginary = mag*sin(ang);
  complex conj(real, imaginary);
  
  return conj;
}

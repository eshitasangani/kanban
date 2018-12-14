#include "complex.hpp"
#include <stdlib.h>
#include <math.h>
using namespace std;

complex abs(const complex a){
  double asqr = (a.re)*(a.re);
  double bsqr = (a.im)*(a.im);
  a = math.sqrt((asqr+bsqr));
  return a;
}
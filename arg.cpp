#include <complex.h>
#include <cmath>



double arg(const complex num) {
  double re = num.re;
  double im = num.img;
  
  re = (re * re);
  im = im * im;
  double sum = im + re;
  sum = sqrt(sum);

  double theta = arccos(num.re/sum);
  double theta1 = arcsin(num.im/sum);
  if (theta == theta1){
    return theta;
  }
  return 0.0;
}
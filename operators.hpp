#include <iostream>
#include <complex.hpp>
#include <stdlib.h>
#include <math.h>

using namespace std; //using standard namespace

class Operators{
  public:
    complex operator =(const complex a, const complex b){
      a.re = b.re;
      a.im = b.im;
      return a;
    }
    complex operator +(const complex a, const complex b){ //addition operator
      complex c((a.re+b.re), (a.im+b.im));
      return c;
    }
    complex operator -(const complex a, const complex b){ //subtraction operator
      complex c((a.re-b.re), (a.im-b.im));
      return c;
    }
    complex operator *(const complex a, const complex b){ //multiplication operator
      complex c();
      //Multiply and combine like terms:
      c.re = a.re * b.re - a.im * b.im; //subtracting because i^2 is -1, negating the value
      c.im = a.re * b.im + a.im * b.re;
      return c;
    }
    complex operator /(const complex a, const complex b), { //division operator
      complex c(b.re, (0-b.im)); //grab the conjugate of the denominator
      a = a * c; //multiply by conjugate
      b = b * c;
      //Split the fraction up into binary terms:
      c.re = c.re/b.re; //b.im should be 0i, since it got multiplied by its conjugate
      c.im = c.im/b.re;
      return c;
    }
    complex operator +=(const complex a, const complex b){ //add-assign operator
      a = a + b;
      return a;
    }
    complex operator -=(const complex a, const complex b){ //subtract-assign operator
      a = a - b;
      return a;
    }
    complex operator /=(const complex a, const complex b){ //divide-assign operator
      a = a / b;
      return a;
    }
    complex operator *=(const complex a, const complex b){ //multiply-assign operator
      a = a * b;
      return a;
    }
    bool operator ==(const complex a, const complex b){
      if((a.re == b.re) && (a.im == b.im))
        return true;
      else
        return false;
    }
    /*bool operator !=(const complex a, const complex b){
      if((a.re != b.re) || (a.im != b.im))
        return true;
      else
        return false;
    }*/ //Not-equals operator does not work as a non-member function, so can't really be defined here
};
#include <iostream>
#include <complex.hpp>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Extensions{
  public:
    friend ostream& operator <<(ostream& s, const complex& c);
    friend istream& operator >>(istream& s, complex& c);
};

class Operators{
  public:
    friend complex operator =(const complex a, const complex b);
    friend complex operator +(const complex a, const complex b);
    friend complex operator -(const complex a, const complex b);
    friend complex operator *(const complex a, const complex b);
    friend complex operator /(const complex a, const complex b);
    friend complex operator +=(const complex a, const complex b);
    friend complex operator -=(const complex a, const complex b);
    friend complex operator /=(const complex a, const complex b);
    friend complex operator *=(const complex a, const complex b);
    friend bool operator ==(const complex a, const complex b);
    friend bool operator !=(const complex a, const complex b);
};

ostream& operator <<(ostream& s, const complex& c){
      s << "(" << c.re << ", " << c.im << ")";
      return s; //Should return as "(real number, imaginary number)"
    }

istream& operator >>(istream& s, complex& c){
      int counter = 1; //keep track of where I am in the istream
      int decimal = 1; //needed to keep track of decimal place
      c.re = 0.0; //reset needed
      c.im = 0.0;
      do{ //this is supposed to grab the whole number part of the real number
      s.seekg(counter, ios::beg); //read in the next digit
      c.re *= 10; //move c one digit over so digits don't get added together
      c.re += s.tellg(); //add in the digit
      counter++; //increment my counter/mover
      }while((s.tellg() != '.') || (s.tellg() != ','));
      if(s.tellg() == '.'){ //grab the decimal part, if there is one
        counter++;
        do{
          s.seekg(counter, ios::beg);
          c.re *= 10;
          c.re += s.tellg();
          counter++;
          decimal *= 10;
        }while(s.tellg() != ',');
        c.re /= decimal; //make sure decimal is in the right place
      }
      //Now do it all again, except for the imaginary part
      counter += 2; //skip the comma and space
      decimal = 1;
      do{ //whole number part
      s.seekg(counter, ios::beg);
      c.im *= 10;
      c.im += s.tellg();
      counter++;
      }while((s.tellg() != '.') || (s.tellg() != ','));
      if(s.tellg() == '.'){ //decimal part
        counter++;
        do{
          s.seekg(counter, ios::beg);
          c.im *= 10;
          c.im += s.tellg();
          counter++;
          decimal *= 10;
        }while(s.tellg() != ',');
        c.im /= decimal;
      }
      //Should return the original istream, but c has been updated
      return s;
    }
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
  complex c = new complex();
  //Multiply and combine like terms:
  c.re = a.re * b.re - a.im * b.im; //subtracting because i^2 is -1, negating the value
  c.im = a.re * b.im + a.im * b.re;
  return c;
  }
complex operator /(const complex a, const complex b){ //division operator
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
bool operator !=(const complex a, const complex b){
  if((a.re != b.re) || (a.im != b.im))
    return true;
  else
    return false;
  }
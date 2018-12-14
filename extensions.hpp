#include <iostream>
#include "complex.hpp"

using namespace std;

class Extensions{
  public:
    friend ostream& operator <<(ostream& s, const complex& c);
    friend istream& operator >>(istream& s, complex& c);
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
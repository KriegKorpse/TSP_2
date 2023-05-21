#include <iostream>
#include <cmath>
#include "Triangle.h"
using namespace std;


   bool Triangle::exist_tr() {
      return (a + b > c) && (b + c > a) && (a + c > b);
   };

   void Triangle::set(double a_, double b_, double c_) {
      a = a_;
      b = b_;
      c = c_;
   };

   void Triangle::show() {
      cout << "1-st side = " << a << endl;
      cout << "2-nd side = " << b << endl;
      cout << "3-rd side = " << c << endl;
   };

   double Triangle::perimeter() {
      return a + b + c;
   };

   double Triangle::square() {
      double h_p = 0.5 * this->perimeter();
      return sqrt(h_p * (h_p - a) * (h_p - b) * (h_p - c));
   };
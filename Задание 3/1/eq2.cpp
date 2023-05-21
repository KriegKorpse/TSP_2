#include<iostream>
#include"eq2.h"
using namespace std;

eq2::eq2() {
   this->a = 1.0;
   this->b = 1.0;
   this->c = 1.0;
   this->D = -3.0;
}

eq2::eq2(double a1, double b1, double c1) {
   this->a = a1;
   this->b = b1;
   this->c = c1;
   this->D = b * b - 4 * a * c;
}

void eq2::set(double a1, double b1, double c1) {
   this->a = a1;
   this->b = b1;
   this->c = c1;
   this->D = b * b - 4 * a * c;
}

double eq2::find_X() {
   if (0 == a) {
      cout << "Не является квадратным уравнением (a = " << this->a << endl;
      return 0;
   }
   else {
      if (D < 0) {
         cout << "Корней нет" << endl;
         return 0;
      }
      else if (0 == D) {
         cout << "Уравнение имеет 1 корень ";
         double x = (-b) / (2.0 * a);
         cout << "x = " << x << endl;
         return x;
      }
      else {
         cout << "Уравнение имеет 2 корня, наибольший ";
         double x1 = (-b + sqrt(D)) / (2 * a);
         double x2 = (-b - sqrt(D)) / (2 * a);
         cout << "x = " << max(x1, x2) << endl;
         return max(x1, x2);
      }
   }
   return 0;
}

double eq2::find_Y(double x1) {
   return a * x1 * x1 + b * x1 + c;
}

eq2 eq2::operator + (eq2& eq2_2) {
   
   double a = (this->a + eq2_2.a)/2;
   double b = (this->b + eq2_2.b)/2;
   double c = (this->c + eq2_2.c)/2;
   eq2 tmp(a, b, c);
   return tmp;
}

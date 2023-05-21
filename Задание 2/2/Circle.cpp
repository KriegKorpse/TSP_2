#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "Circle.h"
using namespace std;

   Circle::Circle(float radius_, float x_center_, float y_center_) {
      radius = abs(radius_);
      x_center = x_center_;
      y_center = y_center_;
   }

   void Circle::set_circle(float r, float x, float y) {
      radius = abs(r);
      x_center = x;
      y_center = y;
   }

   float Circle::get_radius() {
      return radius;
   }

   float Circle::get_x_center() {
      return x_center;
   }

   float Circle::get_y_center() {
      return y_center;
   }

   void Circle::show_parms() {
      cout << "Parms of a circle: " << endl;
      cout << "Radius is " << radius << endl;
      cout << "x_center is " << x_center << endl;
      cout << "y_center is " << y_center << endl;
   }

   float Circle::square() {
      return M_PI * radius * radius;
   }

   bool Circle::triangle_around(float a, float b, float c) {
      Triangle tr;
      tr.set(a, b, c);
      float h_p = 0.5 * tr.perimeter();
      float square_tr_orig = tr.square();
      float square_tr_around = h_p * radius;
      if (square_tr_orig == square_tr_around)
         return true;
      return false;
   }

   bool Circle::triangle_in(float a, float b, float c) {
      Triangle tr;
      tr.set(a, b, c);
      float square_tr_orig = tr.square();
      float square_tr_in = a * b * c / (4 * radius);
      if (square_tr_orig == square_tr_in)
         return true;
      return false;
   }
   bool Circle::check_circle(float r, float x_cntr, float y_cntr) {
      float d = sqrt(pow(x_cntr - x_center, 2) + pow(y_cntr - y_center, 2));
      if (0 == d && r == radius)
         return false;
      else if (d > r + radius)
         return false;
      else if (d < abs(r - radius))
         return false;
      return true;
   }
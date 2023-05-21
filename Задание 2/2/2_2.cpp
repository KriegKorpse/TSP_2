#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "Circle.h"
using namespace std;

int main()
{
   float radius, x_center, y_center = 0;
   cout << "Enter the circle 1: radius, coord-s of x and y of it's center" << endl;
   cin >> radius >> x_center >> y_center;
   // c_1 : 4, 2, 2
   Circle c_1(radius, x_center, y_center);
   cout << "Circle 1 parms: " << endl;
   c_1.show_parms();
   cout << "Enter the circle 2: radius, coord-s of x and y of it's center" << endl;
   cin >> radius >> x_center >> y_center;
   // c_2 : 1, 1, 1 changed to 3, 3, 3
   Circle c_2(radius, x_center, y_center);
   cout << "Circle 2 parms: " << endl;
   c_2.show_parms();

   bool flag = true;
   while(flag) {
      char ch = '0';
      cout << "Do you want to change parm-s of entered circles? y/n" << endl;
      cin >> ch;
      if ('y' == ch) {
         cout << "Which circle? 1 or 2" << endl;
         cin >> ch;
         if ('1' == ch) {
            cout << "Enter the circle 1: radius, coord-s of x and y of it's center" << endl;
            cin >> radius >> x_center >> y_center;
            c_1.set_circle(radius, x_center, y_center);
            c_1.show_parms();
         }
         else if ('2' == ch) {
            cout << "Enter the circle 2: radius, coord-s of x and y of it's center" << endl;
            cin >> radius >> x_center >> y_center;
            c_2.set_circle(radius, x_center, y_center);
            c_2.show_parms();
         }
         else
            cout << "Found no such circle" << endl;
      }
      else
         flag = false;
   }

   float square_c_1 = c_1.square();
   cout << "Square of a circle 1 = " << square_c_1 << endl;

   float a, b, c = 0;
   // 12 16 20 true; 12 16 30 false
   cout << "Enter 3 sides of triangle which we will try to draw around the Circle 1" << endl;
   cin >> a >> b >> c;
   bool triangle_around_c_1 = c_1.triangle_around(a, b, c);
   if (triangle_around_c_1)
      cout << "Triangle with sides: " << a << ", " << b << ", " << c << " can be drawn around the Circle 1" << endl;
   else
      cout << "Triangle with sides: " << a << ", " << b << ", " << c << " can't be drawn around the Circle 1" << endl;
   // 6.4, 4.8, 8 true; 6.4, 4.8, 10
   cout << "Enter 3 sides of triangle which we will try to draw in the Circle 1" << endl;
   cin >> a >> b >> c;
   bool triangle_in_c_1 = c_1.triangle_in(a, b, c);
   if (triangle_around_c_1)
      cout << "Triangle with sides: " << a << ", " << b << ", " << c << " can be drawn in the Circle 1" << endl;
   else
      cout << "Triangle with sides: " << a << ", " << b << ", " << c << " can't be drawn in the Circle 1" << endl;
   // c_1 4, 2, 2 and c_2 3. 3, 3 cross
   bool check_circle_c_1_c_2 = c_1.check_circle(c_2.get_radius(), c_2.get_x_center(), c_2.get_y_center());
   if (check_circle_c_1_c_2)
      cout << "Circle 1 cross Circle 2" << endl;
   else
      cout << "Circle 1 doesn't cross Circle 2" << endl;
   

   //Circle c_1(4, 2, 2), c_2(3, 3, 3);
   //cout << "flag " << c_1.triangle_around(12, 16, 20);
   //cout << "flag " << c_1.triangle_in(6.4, 4.8, 8);
   //cout << "flag " << c_1.check_circle(c_2.get_radius(), c_2.get_x_center(), c_2.get_y_center());

}



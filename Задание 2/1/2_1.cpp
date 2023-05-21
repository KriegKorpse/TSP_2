#include <iostream>
#include "Triangle.h"
using namespace std;

int main()
{
   Triangle arr[3];
   for (int i = 0; i < 3; i++) {
      double a, b, c;
      cout << "Enter 3 sides of the triangle N" << i + 1 << " divided by space" << endl;
      cin >> a >> b >> c;
      arr[i].set(a, b, c);
      if (!arr[i].exist_tr()) {
         arr[i].show();
         cout << "Triangle with these sides doesn't exist, try again" << endl;
         i--;
      }
   }

   for (int i = 0; i < 3; i++) {
      arr[i].show();
      cout << "Perimeter = " << arr[i].perimeter() << endl;
      cout << "Square = " << arr[i].square() << endl;
   }
   return 0;
}
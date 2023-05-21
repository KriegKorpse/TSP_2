#include <iostream>
#include "eq2.h"
using namespace std;

void input_eq2(double& a, double& b, double& c, eq2& eq2_1);

int main()
{
   setlocale(LC_ALL, "RUS");
   double a = 0, b = 0, c = 0;
   eq2 eq2_1(1, 2, 1);
   cout << "Уравнение eq2_1: " << endl;
   input_eq2(a, b, c, eq2_1);
   double x = eq2_1.find_X();
   double y = eq2_1.find_Y(x);
   cout << "y(" << x << ") = " << y << endl << endl;

   eq2 eq2_2;
   cout << "Уравнение eq2_2: " << endl;
   input_eq2(a, b, c, eq2_2);
   x = eq2_1.find_X();
   y = eq2_1.find_Y(x);
   cout << "y(" << x << ") = " << y << endl << endl;

   cout << "Уравнение полученное в результате суммы eq2_1 и eq2-2: " << endl;
   eq2 eq2_sum = eq2_1 + eq2_2;
   show_parms(eq2_sum);
   x = eq2_1.find_X();
   y = eq2_1.find_Y(x);
   cout << "y(" << x << ") = " << y << endl << endl;
}

void show_parms(eq2 &eq2_1) {
   cout << "Параметры уравнения: " << endl;
   cout << "a = " << eq2_1.a << endl;
   cout << "b = " << eq2_1.b << endl;
   cout << "c = " << eq2_1.c << endl;
   cout << "D = " << eq2_1.D << endl;
}

void input_eq2(double &a, double& b, double& c, eq2& eq2_1) {
   cout << "Введите коэффициенты квадратного уравнения a, b, c:" << endl;
   cin >> a >> b >> c;
   eq2_1.set(a, b, c);
   show_parms(eq2_1);
   bool flag = false;
   while (!flag) {
      char ch = 'n';
      cout << "Изменить введенные коэффициенты? y/n ";
      cin >> ch;
      if ('n' == ch)
         flag = true;
      else {
         cout << "Введите коэффициенты квадратного уравнения a, b, c:" << endl;
         cin >> a >> b >> c;
         eq2_1.set(a, b, c);
         show_parms(eq2_1);
      }
   }
}

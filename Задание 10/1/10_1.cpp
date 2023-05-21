#include <iostream>
#include <windows.h>
using namespace std;

template <class T> void Swap(T& x, T& y) {
   T z = x;
   x = y;
   y = z;
}

template <class T> void OutXY(T& x, T& y) {
   cout << "x= " << x << "; y= " << y << endl;
}

class Test {
private:
   int a;
   double b;
public:
   Test() {
      a = 0;
      b = 0.0;
   }

   Test(int a_, float b_) {
      a = a_;
      b = b_;
   }

   Test operator = (Test T) {
      a = T.a;
      b = T.b;
      return *this;
   }

   int get_a() {
      return a;
   }

   double get_b() {
      return b;
   }

   friend ostream& operator << (ostream& stream, Test& T);
};

ostream& operator << (ostream& stream, Test& T) {
   return stream << "{ a=  " << T.get_a() << "; b= " << T.get_b() << " }";
}

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   setlocale(LC_ALL, "Russian");

   int ix = 1, iy = 2;
   cout << "Перед обменом (целые): ";
   OutXY(ix, iy);
   Swap(ix, iy);
   cout << "После обмена (целые): ";
   OutXY(ix, iy);

   double dx = 1.19, dy = -2.85;
   cout << "Перед обменом (double): ";
   OutXY(dx, dy);
   Swap(dx, dy);
   cout << "После обмена (double): ";
   OutXY(dx, dy);

   Test T_x(9, 17.34), T_y(23, -89.45);
   cout << "Перед обменом (Класс Test): " << T_x << " ; " << T_y << endl;
   Swap(T_x, T_y);
   cout << "После обмена (Класс Test): " << T_x << " ; " << T_y << endl;
}


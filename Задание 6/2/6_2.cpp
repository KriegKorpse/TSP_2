#include <iostream>
#include <windows.h>
#include "trunc_cone.h"
using namespace std;

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   setlocale(LC_ALL, "Rus");

   Trunc_Cone tr;
   cout << "Tr: " << tr << endl;

   Trunc_Cone tr1(1, 2 ,3, 4, 5, 6, 7, 8);
   cout << "Tr1: " << tr1 << endl;

   cin >> tr1;
   cout << "Tr1 после изменений: " << tr1 << endl;

   int k = 0;
   cout << "Введите количество желаемых усеченных конусов:" << endl;
   cin >> k;
   Trunc_Cone* tr_c_arr = new Trunc_Cone[k];
   for (int i = 0; i < k; i++) {
      cin >> tr_c_arr[i];
      cout << tr_c_arr[i] << endl;
   }

   //Определите методы сравнения конусов. Определите несколько усеченных конусов, наследующих одному базовому конусу
   Cone base_cone(5, 12);
   //Trunc_Cone child_cone_a(base_cone, 3, 4, 5);
   Trunc_Cone child_cone_a(base_cone, 3, 2, 1);
   Trunc_Cone child_cone_b(base_cone, 3, 4, 5);
   int a_more_than_b = child_cone_a > child_cone_b;
   if (1 == a_more_than_b)
      cout << "TruncCone A > B true" << endl;
   else
      cout << "TruncCone A > B false" << endl;
   int a_less_than_b = child_cone_a < child_cone_b;
   if (1 == a_less_than_b)
      cout << "TruncCone A < B true" << endl;
   else
      cout << "TruncCone A < B false" << endl;
   int a_equals_b = child_cone_a == child_cone_b;
   if (a_equals_b)
      cout << "TruncCone A = B true" << endl;
   else
      cout << "TruncCone A = B false" << endl;

   delete[] tr_c_arr;
   return 0;
}

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <windows.h>
#include <vector>
#include "Cone.h"
using namespace std;

int main() {
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   setlocale(LC_ALL, "Russian");

   // Объявите конус с центром в начале координат и произвольный конуса как статические объекты созданного типа, найдите площадь поверхности и объём каждого.
   Cone cone_1(3, 7);
   Cone cone_2(1, 2, 3, 5, 10);

   cout << "Конус 1: " << cone_1;
   cout << "Площадь поверхности: " << cone_1.area() << endl;
   cout << "Обьем: " << cone_1.volume() << endl;

   cout << "Конус 2: " << cone_2;
   cout << "Площадь поверхности: " << cone_2.area() << endl;
   cout << "Обьем: " << cone_2.volume() << endl;

   //Объявите динамический объект по умолчанию, введите данные и выведите на экран.
   cout << "Введите количество желаемых элементов" << endl;
   int n = 0;
   cin >> n;

   Cone* arr_cones = new Cone[n];
   for (int i = 0; i < n; i++) {
      double x = 0, y = 0, z = 0, r = 0, h = 0;
      cout << "Хотите ввести данные произвольного конуса (y) или с центром в начале координат (n)?  y/n" << endl;
      char ch = 'n';
      cin >> ch;
      if ('y' == ch) {
         cout << "Введите координаты центра (x, y, z) конуса " << i+1 << " а также его радиус r и высоту h" << endl;
         cin >> x >> y >> z >> r >> h;
         arr_cones[i].set(x, y, z, r, h);
      }
      else
      {
         cout << "Введите радиус r и высоту h конуса " << i+1 << endl;
         cin >> r >> h;
         arr_cones[i].set_radius(r);
         arr_cones[i].set_heigth(h);
      }
   }

   cout << "Вывод массива " << n << " конусов" << endl;
   for (int i = 0; i < n; i++) {
      cout << arr_cones[i];
   }

   //Объявите массив из 2 - 3 конусов.Найдите способ присвоить им значения при создании объектов.
   vector<Cone> v_cones;
   cout << "Введите количество желаемых элементов" << endl;
   int k = 0;
   cin >> k;
   for (int i = 0; i < k; i++) {
      double x = 0, y = 0, z = 0, r = 0, h = 0;
      cout << "Хотите ввести данные произвольного конуса (y) или с центром в начале координат (n)?  y/n" << endl;
      char ch = 'n';
      cin >> ch;
      if ('y' == ch) {
         cout << "Введите координаты центра (x, y, z) конуса " << i + 1 << " а также его радиус r и высоту h" << endl;
         cin >> x >> y >> z >> r >> h;
         v_cones.push_back(Cone(x, y, z, r, h));
      }
      else
      {
         cout << "Введите радиус r и высоту h конуса " << i + 1 << endl;
         cin >> r >> h;
         v_cones.push_back(Cone(0, 0, 0, r, h));
      }
   }

   cout << "Вывод массива " << k << " конусов" << endl;
   for (int i = 0; i < k; i++) {
      cout << v_cones[i];
   }

   return 0;
}


#include <iostream>
#include <stdexcept>
#include <vector>
#include "rational.h"
using namespace std;

void enter_rational(rational * rat, int i, bool read_or_set);

int main()
{
   setlocale(LC_ALL, "RUS");
   int n = 0;
   cout << "введите количество дробей: ";
   cin >> n;
   rational* arr_rat = new rational[n];
   for (int i = 0; i < n; i++) {
      enter_rational(arr_rat, i, true);
   } 

   bool stop_read = false;
   while (!stop_read && n != 0) {
      int choice = 0;
      cout << "Хотите изменить значения дробей? Выберите номер дроби от 1 до " << n << ". Для выхода введите 0" << endl;
      cin >> choice;
      if (0 == choice)
         stop_read = true;
      else if ((1 > choice) || (n < choice)) {
         cout << "Номер дроби должен быть от 1 до " << n << endl;
      }
      else
      {
         enter_rational(arr_rat, choice-1 , false);
      }
   }

   for (int i = 0; i < n; i++) {
      cout << "Дробь №" << i + 1 << ": ";
      arr_rat[i].show();
      cout << endl;
   }
  delete[] arr_rat;
}


void enter_rational(rational * rat, int i, bool read_or_set) {
   bool is_valid = false;
   while (!is_valid) {
      is_valid = true;
      cout << "Введите дробь №" << i + 1 << " числитель и знаменатель через пробел" << endl;
      int a = 0; int b = 0;
      cin >> a >> b;
      if (read_or_set) {
         try {
            rat[i] = rational(a, b);
         }
         catch (exception& e) {
            is_valid = false;
            cout << "Ошибка: " << e.what() << endl;
         }
      }
      else {
         try {
            rat[i].set(a, b);
         }
         catch (exception& e) {
            is_valid = false;
            cout << "Ошибка: " << e.what() << endl;
         }
      }
      
   }
}
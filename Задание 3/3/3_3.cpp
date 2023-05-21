#include <iostream>
#include <stdexcept>
#include <vector>
#include "rational.h"
using namespace std;

void enter_rational(rational* rat, int i, bool read_or_set);

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
         enter_rational(arr_rat, choice - 1, false);
      }
   }

   for (int i = 0; i < n; i++) {
      cout << "Дробь №" << i + 1 << ": ";
      arr_rat[i].show();
      cout << endl;
   }

   bool stop_choice = false;
   rational* arr_choice = new rational[3];
   int counter = 0;
   int choice = 0;
   while (!stop_choice) {
      cout << "Выберите несколько дробей номерами от 1 до " << n << endl;
      cin >> choice;
      
      if ((1 > choice) || (n < choice)) {
         cout << "Номер выбранной дроби должен быть от 1 до " << n << endl;
      }
      else
      {
         arr_choice[counter] = arr_rat[choice-1];
         counter++;
         if (2 == counter)
            stop_choice = true;
      }
   }

   cout << "A: ";
   arr_choice[0].show();
   cout << endl;

   cout << "B: ";
   arr_choice[1].show();
   cout << endl;

   bool A_is_B = arr_choice[0] == arr_choice[1];
   if(A_is_B)
      cout << "A is B?: true" << endl << endl;
   else
      cout << "A is B?: false" << endl << endl;

   bool A_more_than_B = arr_choice[0] > arr_choice[1];
   if (A_more_than_B)
      cout << "A more than B?: true" << endl << endl;
   else
      cout << "A more than B?: false" << endl << endl;

   rational c = arr_choice[0] + arr_choice[1];
   cout << "A + B: ";
   c.show();
   cout << endl;

   rational d = arr_choice[0] - arr_choice[1];
   cout << "A - B: ";
   d.show();
   cout << endl;
   
   ++arr_choice[0];
   cout << "++A: ";
   arr_choice[0].show();
   cout << endl;

   arr_choice[0]++;
   cout << "A++: ";
   arr_choice[0].show();
   cout << endl;

   arr_choice[2] = arr_choice[0];
   cout << "E = A: ";
   arr_choice[2].show();
   cout << endl;

   delete[] arr_rat;
   delete[] arr_choice;
}


void enter_rational(rational* rat, int i, bool read_or_set) {
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
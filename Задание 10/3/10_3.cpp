#include <iostream>
#include <windows.h>
#include "Set.h"
using namespace std;

int main() {
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   setlocale(LC_ALL, "Russian");
   Set<int> arr_1(5);
   cout << "Is_Empty? " << arr_1.Is_Empty() << endl;
   cout << "Is_Full? " << arr_1.Is_Full() << endl;

   arr_1.Add(4);
   cout << "Is_Empty? " << arr_1.Is_Empty() << endl;
   cout << "Is_Full? " << arr_1.Is_Full() << endl;
   cout << "Print arr " << arr_1 << endl;

   cout << "Is -3 in array: " << arr_1.In_Set(-3) << endl;
   arr_1.Add(-3);
   cout << "Is_Empty? " << arr_1.Is_Empty() << endl;
   cout << "Is_Full? " << arr_1.Is_Full() << endl;
   cout << "Print arr " << arr_1 << endl;
   cout << "Is -3 in array: " << arr_1.In_Set(-3) << endl;

   arr_1.Add(78);
   cout << "Is_Empty? " << arr_1.Is_Empty() << endl;
   cout << "Is_Full? " << arr_1.Is_Full() << endl;
   cout << "Print arr " << arr_1 << endl;

   arr_1.Add(0);
   cout << "Is_Empty? " << arr_1.Is_Empty() << endl;
   cout << "Is_Full? " << arr_1.Is_Full() << endl;
   cout << "Print arr " << arr_1 << endl;

   arr_1.Add(0);
   cout << "Is_Empty? " << arr_1.Is_Empty() << endl;
   cout << "Is_Full? " << arr_1.Is_Full() << endl;
   cout << "Print arr " << arr_1 << endl;

   arr_1.Add(111);
   cout << "Is_Empty? " << arr_1.Is_Empty() << endl;
   cout << "Is_Full? " << arr_1.Is_Full() << endl;
   cout << "Print arr " << arr_1 << endl;

   int c = arr_1.Get(-3);
   cout << "Is_Empty? " << arr_1.Is_Empty() << endl;
   cout << "Is_Full? " << arr_1.Is_Full() << endl;
   cout << "arr_1" << arr_1 << endl;

   Set<int> arr_2(3);
   arr_2.Add(17);
   arr_2.Add(4);
   arr_2.Add(-34);
   cout << "arr_2: " << arr_2 << endl;

   Set<int> arr_3 = arr_1 + arr_2;
   Set<int> arr_4 = arr_1;
   Set<int> arr_5;
   arr_5 = arr_1 * arr_2;
   bool arr_1_in_arr_2 = arr_1 <= arr_2;
   bool arr_5_in_arr_4 = arr_5 <= arr_4;
   cout << "arr_3: " << arr_3 << endl;
   cout << "arr_4: " << arr_4 << endl;
   cout << "arr_5: " << arr_5 << endl;
   cout << "arr_1_in_arr_2?: " << arr_1_in_arr_2 << endl;
   cout << "arr_5_in_arr_4?: " << arr_5_in_arr_4 << endl;

   Set<string> str_1(5);
   str_1.Add("we"); str_1.Add("are"); str_1.Add("the"); str_1.Add("godless"); str_1.Add("entity");
   cout << "str_1: " << str_1 << endl;

   Set<string> str_2(6);
   str_2.Add("we"); str_2.Add("are"); str_2.Add("legion"); str_2.Add("of"); str_2.Add("the"); ; str_2.Add("damned");
   cout << "str_2: " << str_2 << endl;

   Set<string> str_3 = str_1 + str_2;
   cout << "str_3: " << str_3 << endl;

   Set<string> str_4 = str_1 * str_2;
   cout << "str_4: " << str_4 << endl;

   bool str_4_in_str_1 = str_4 <= str_1;
   cout << "str_4_in_str_1: " << str_4_in_str_1 << endl;
   return 0;
}
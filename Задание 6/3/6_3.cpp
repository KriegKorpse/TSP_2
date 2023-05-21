#include <iostream>
#include <windows.h>
#include "bay.h"
using namespace std;

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   setlocale(LC_ALL, "Rus");
   Ocean oc_1, oc_2("Opened", "Ocean of souls", "Warp", 666.0, 444.0, 999.0);
   cout << "Введите данные для обьекта океана" << endl;
   cin >> oc_1;
   cout << "oc_1: " << endl << oc_1 << endl;
   cout << "oc_2: " << endl << oc_2 << endl;

   Sea sea_1, sea_2("Sea of Blood", "Warp", 644.0, 466.0, 919.0, 456);
   cout << "Введите данные для обьекта моря" << endl;
   cin >> sea_1;
   sea_1.set_parent(&oc_1);
   cout << "sea_1: " << endl << sea_1 << endl;
   cout << "sea_2: " << endl << sea_2 << endl;

   Bay bay_1, bay_2("Bay of Blades", "Norsca", 6445.0, 4616.0, 9191.0, 4056, "Belakor"), bay_3("Bay of Victory", "Kaurava", 7435, 345.9, 325463.598, 84356, "202 Vendoland");
   cout << "Введите данные для обьекта залива" << endl;
   cin >> bay_1;
   bay_1.set_parent(&oc_2);
   bay_2.set_parent(&oc_1);
   bay_2.set_parent(&sea_2);
   cout << "bay_1: " << endl << bay_1 << endl;
   cout << "bay_2: " << endl << bay_2 << endl;
   cout << "bay_3: " << endl << bay_3 << endl;
}
#ifndef _CONE_H
#define _CONE_H

#include <iostream>
using namespace std;

class Cone { //класс конуса
private:
   double x, y, z; //координаты центра основания
   double r; // радиус
   double h; // высота

public:

   //Конструкторы класса : конструктор по умолчанию, конструктор конуса с центром в начале координат, конструктор произвольного конуса.
   Cone();

   Cone(double r_, double h_);

   Cone(double x_, double y_, double z_, double r_, double h_);

   //Определите методы : ввод конуса, вывод на экран, определение площади поверхности, определение объёма конуса.
   // функции доступа
   void set(double x_, double y_, double z_, double r_, double h_);

   void set_coords(double x_, double y_, double z_);

   void set_radius(double r_); // установка радиуса конуса

   void set_heigth(double h_); // установка высоты конуса

   double get_radius(); // получение радиуса конуса

   double get_heigth(); // получение высоты конуса

   // Площадь полной поверхности
   double area();

   // Объем конуса
   double volume();

   friend ostream& operator<< (ostream& stream, const Cone& obj);
};

#endif //_CONE_H

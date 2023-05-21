#define _USE_MATH_DEFINES
#include "Cone.h"
#include <cmath>
#include <iostream>
using namespace std;

   //Конструкторы класса : конструктор по умолчанию, конструктор конуса с центром в начале координат, конструктор произвольного конуса.
   Cone::Cone() {
      x = 0; y = 0; z = 0; r = 0; h = 0;
   }

   Cone::Cone(double r_, double h_) { // конструктор конуса с центром в нач. коорд-т.
      x = 0; y = 0; z = 0;
      this->r = r_; this->h = h_;
   }

   Cone::Cone(double x_, double y_, double z_, double r_, double h_) { //конструктор произвольного конуса 
      this->x = x_; this->y = y_; this->z = z_;
      this->r = r_; this->h = h_;
   }

   //Определите методы : ввод конуса, вывод на экран, определение площади поверхности, определение объёма конуса.
   // функции доступа
   void Cone::set(double x_, double y_, double z_, double r_, double h_) {
      this->x = x_; this->y = y_; this->z = z_;
      this->r = r_; this->h = h_;
   }

   void Cone::set_coords(double x_, double y_, double z_) { // установка координат центра конуса
      this->x = x_; this->y = y_; this->z = z_;
   }

   void Cone::set_radius(double r_) { this->r = r_; } // установка радиуса конуса

   void Cone::set_heigth(double h_) { this->h = h_; } // установка высоты конуса

   double Cone::get_radius() { return this->r; }; // получение радиуса конуса

   double Cone::get_heigth() { return this->h; }; // получение высоты конуса

   // Площадь полной поверхности
   double Cone::area() {
      double l = sqrt(h * h + r * r);
      return M_PI * r * (r + l);
   }

   // Объем конуса
   double Cone::volume() { return M_PI * r * r * h / 3; }

   ostream& operator << (ostream& stream, const Cone& obj) {
      stream << "(" << obj.x << ": ";
      stream << obj.y << "; ";
      stream << obj.z << ") ";
      stream << "r= " << obj.r << " ";
      stream << "h= " << obj.h << endl;
      return stream;
}
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "trunc_cone.h"
using namespace std; 
   // Определите конструкторы по умолчанию и с параметрами.
   Trunc_Cone::Trunc_Cone() : Cone() {
      this->x1 = 0;
      this->y1 = 0;
      this->z1 = 0;
      this->is_valid = false;
   }

   Trunc_Cone::Trunc_Cone(double x_, double y_, double z_, double r_, double h_, double x1_, double y1_, double z1_) :Cone(x_, y_, z_, r_, h_) {
      this->x1 = x1_;
      this->y1 = y1_;
      this->z1 = z1_;
      this->is_valid = true;
   }

   Trunc_Cone::Trunc_Cone(const Cone& obj, double x1_, double y1_, double z1_) :Cone(obj) {
      this->x1 = x1_;
      this->y1 = y1_;
      this->z1 = z1_;
      this->is_valid = true;
   }


   void Trunc_Cone::set(double x_, double y_, double z_, double r_, double h_, double x1_, double y1_, double z1_) {
      this->x = x_; this->y = y_; this->z = z_;
      this->r = r_; this->h = h_;
      this->x1 = x1_; this->y1 = y1_; this->z1 = z1_;
      this->is_valid = true;
   }

   bool Trunc_Cone::get_valid() {
      return this->is_valid;
   }

   //Переопределите методы вычисления площади поверхности и объема для усеченного конуса с использованием методов базового класса.Для ввода и вывода на экран перегрузите операции >> и << .Объявите несколько усеченных конусов, выведите на экран их площади поверхности и объемы.
   // Площадь полной поверхности
   double Trunc_Cone::area(){
      Cone tmp_big(x, y, z, r, h);
      double area_big = tmp_big.area();

      double h1 = h - sqrt(pow((x1 - x), 2) + pow((y1 - y), 2) + pow((z1 - z), 2));
      double k = h1 / h;
      double r1 = k * r;
      Cone tmp_small(x1, y1, z1, r1, h1);
      double area_small = tmp_small.area();

      return area_big - area_small + M_PI * r1 * r1;
   }

   // Объем конуса
   double Trunc_Cone::volume(){
      Cone tmp_big(x, y, z, r, h);
      double vol_big = tmp_big.volume();

      double h1 = h - sqrt(pow((x1 - x), 2) + pow((y1 - y), 2) + pow((z1 - z), 2));
      double k = h1 / h;
      double r1 = k * r;
      Cone tmp_small(x1, y1, z1, r1, h1);
      double vol_small = tmp_small.volume();

      return vol_big - vol_small;
   }
   // Операторы ввода/вывода
   ostream& operator << (ostream& stream, Trunc_Cone& obj) {
      stream << "(" << obj.x << ": ";
      stream << obj.y << "; ";
      stream << obj.z << ") ";
      stream << "r= " << obj.r << " ";
      stream << "h= " << obj.h << " ";
      stream << "(" << obj.x1 << ": ";
      stream << obj.y1 << "; ";
      stream << obj.z1 << ") ";
      if (obj.is_valid)
      {
         stream << "Sп.п. = " << obj.area() << " , ";
         stream << "V = " << obj.volume();
      }
      return stream;
   }

   istream& operator >> (istream& stream, Trunc_Cone& obj) {
      double x_ = 0, y_ = 0, z_ = 0; // координаты центра основания конуса
      double r_ = 0; double h_ = 0; // радиус и высота конуса
      double x1_ = 0, y1_ = 0, z1_ = 0; // координаты центра сечения конуса

      cout << "Введите через пробел координаты основания конуса (x, y, z), радиус, высоту и координаты его сечения (x1, y1, z1)" << endl;
      stream >> x_ >> y_ >> z_ >> r_ >> h_ >> x1_ >> y1_ >> z1_;
      obj.set(x_, y_, z_, r_, h_, x1_, y1_, z1_);
      return stream;
   }

   // Операции сравнения
   int Trunc_Cone::operator == (Trunc_Cone tr) {
      Cone tmp_this(this->x, this->y, this->z, this->r, this->h);
      Cone tmp_tr(tr.x, tr.y, tr.z, tr.r, tr.h);
      return (tmp_this == tmp_tr) && (this->x1 == tr.x1) && (this->y1 == tr.y1) && (this->z1 == tr.z1);
   }
   int Trunc_Cone::operator < (Trunc_Cone tr) {
      Cone tmp_this(this->x, this->y, this->z, this->r, this->h);
      Cone tmp_tr(tr.x, tr.y, tr.z, tr.r, tr.h);
      if (tmp_this == tmp_tr) {
         double l_this = sqrt(pow((this->x1 - this->x), 2) + pow((this->y1 - this->y), 2) + pow((this->z1 - this->z), 2));
         double l_tr = sqrt(pow((tr.x1 - tr.x), 2) + pow((tr.y1 - tr.y), 2) + pow((tr.z1 - tr.z), 2));
         if (l_this < l_tr)
            return 1;
         else
            return 0;
      }
      return -1;
   }
   int Trunc_Cone::operator > (Trunc_Cone tr) {
      Cone tmp_this(this->x, this->y, this->z, this->r, this->h);
      Cone tmp_tr(tr.x, tr.y, tr.z, tr.r, tr.h);
      if (tmp_this == tmp_tr) {
         double l_this = sqrt(pow((this->x1 - this->x), 2) + pow((this->y1 - this->y), 2) + pow((this->z1 - this->z), 2));
         double l_tr = sqrt(pow((tr.x1 - tr.x), 2) + pow((tr.y1 - tr.y), 2) + pow((tr.z1 - tr.z), 2));
         if (l_this > l_tr)
            return 1;
         else
            return 0;
      }
      return -1;
   }

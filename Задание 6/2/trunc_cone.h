#ifndef _TRUNC_CONE_H
#define _TRUNC_CONE_H
#include "Cone.h"

class Trunc_Cone : public Cone {
   // Определите конструкторы по умолчанию и с параметрами.
private:
   double x1, y1, z1; // координаты окружности конуса, полученная усечением
   bool is_valid; // признак заполнения обьекта фактическими значениями
public:
   Trunc_Cone();

   Trunc_Cone(double x_, double y_, double z_, double r_, double h_, double x1_, double y1_, double z1_);

   Trunc_Cone(const Cone& obj, double x1_, double y1_, double z1_);

   void set(double x_, double y_, double z_, double r_, double h_, double x1_, double y1_, double z1_);

   bool get_valid();

   //Переопределите методы вычисления площади поверхности и объема для усеченного конуса с использованием методов базового класса.Для ввода и вывода на экран перегрузите операции >> и << .Объявите несколько усеченных конусов, выведите на экран их площади поверхности и объемы.
   // Площадь полной поверхности
   double area() override;

   // Объем конуса
   double volume() override;
   // Операторы ввода/вывода
   friend ostream& operator << (ostream& stream, Trunc_Cone& c1);
   friend istream& operator >> (istream& stream, Trunc_Cone& c1);

   // Операции сравнения
   int operator == (Trunc_Cone tr);
   int operator < (Trunc_Cone tr);
   int operator > (Trunc_Cone tr);

};

#endif //_TRUNC_CONE_H

#ifndef _CONE_H
#define _CONE_H

#include <iostream>
using namespace std;

class Cone { //����� ������
protected:
   double x, y, z; //���������� ������ ���������
   double r; // ������
   double h; // ������

public:

   //������������ ������ : ����������� �� ���������, ����������� ������ � ������� � ������ ���������, ����������� ������������� ������.
   Cone();

   Cone(double r_, double h_);

   Cone(double x_, double y_, double z_, double r_, double h_);

   Cone(const Cone &obj);

   //���������� ������ : ���� ������, ����� �� �����, ����������� ������� �����������, ����������� ������ ������.
   // ������� �������
   void set(double x_, double y_, double z_, double r_, double h_);

   void set_coords(double x_, double y_, double z_);

   void set_radius(double r_); // ��������� ������� ������

   void set_heigth(double h_); // ��������� ������ ������

   double get_radius(); // ��������� ������� ������

   double get_heigth(); // ��������� ������ ������

   // ������� ������ �����������
   virtual double area();

   // ����� ������
   virtual double volume();

   int operator == (const Cone & obj);
   friend ostream& operator<< (ostream& stream, const Cone& obj);
};

#endif //_CONE_H

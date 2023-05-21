#ifndef _TRUNC_CONE_H
#define _TRUNC_CONE_H
#include "Cone.h"

class Trunc_Cone : public Cone {
   // ���������� ������������ �� ��������� � � �����������.
private:
   double x1, y1, z1; // ���������� ���������� ������, ���������� ���������
   bool is_valid; // ������� ���������� ������� ������������ ����������
public:
   Trunc_Cone();

   Trunc_Cone(double x_, double y_, double z_, double r_, double h_, double x1_, double y1_, double z1_);

   Trunc_Cone(const Cone& obj, double x1_, double y1_, double z1_);

   void set(double x_, double y_, double z_, double r_, double h_, double x1_, double y1_, double z1_);

   bool get_valid();

   //�������������� ������ ���������� ������� ����������� � ������ ��� ���������� ������ � �������������� ������� �������� ������.��� ����� � ������ �� ����� ����������� �������� >> � << .�������� ��������� ��������� �������, �������� �� ����� �� ������� ����������� � ������.
   // ������� ������ �����������
   double area() override;

   // ����� ������
   double volume() override;
   // ��������� �����/������
   friend ostream& operator << (ostream& stream, Trunc_Cone& c1);
   friend istream& operator >> (istream& stream, Trunc_Cone& c1);

   // �������� ���������
   int operator == (Trunc_Cone tr);
   int operator < (Trunc_Cone tr);
   int operator > (Trunc_Cone tr);

};

#endif //_TRUNC_CONE_H

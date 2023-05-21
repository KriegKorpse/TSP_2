#define _USE_MATH_DEFINES
#include "Cone.h"
#include <cmath>
#include <iostream>
using namespace std;

   //������������ ������ : ����������� �� ���������, ����������� ������ � ������� � ������ ���������, ����������� ������������� ������.
   Cone::Cone() {
      x = 0; y = 0; z = 0; r = 0; h = 0;
   }

   Cone::Cone(double r_, double h_) { // ����������� ������ � ������� � ���. �����-�.
      x = 0; y = 0; z = 0;
      this->r = r_; this->h = h_;
   }

   Cone::Cone(double x_, double y_, double z_, double r_, double h_) { //����������� ������������� ������ 
      this->x = x_; this->y = y_; this->z = z_;
      this->r = r_; this->h = h_;
   }

   //���������� ������ : ���� ������, ����� �� �����, ����������� ������� �����������, ����������� ������ ������.
   // ������� �������
   void Cone::set(double x_, double y_, double z_, double r_, double h_) {
      this->x = x_; this->y = y_; this->z = z_;
      this->r = r_; this->h = h_;
   }

   void Cone::set_coords(double x_, double y_, double z_) { // ��������� ��������� ������ ������
      this->x = x_; this->y = y_; this->z = z_;
   }

   void Cone::set_radius(double r_) { this->r = r_; } // ��������� ������� ������

   void Cone::set_heigth(double h_) { this->h = h_; } // ��������� ������ ������

   double Cone::get_radius() { return this->r; }; // ��������� ������� ������

   double Cone::get_heigth() { return this->h; }; // ��������� ������ ������

   // ������� ������ �����������
   double Cone::area() {
      double l = sqrt(h * h + r * r);
      return M_PI * r * (r + l);
   }

   // ����� ������
   double Cone::volume() { return M_PI * r * r * h / 3; }

   ostream& operator << (ostream& stream, const Cone& obj) {
      stream << "(" << obj.x << ": ";
      stream << obj.y << "; ";
      stream << obj.z << ") ";
      stream << "r= " << obj.r << " ";
      stream << "h= " << obj.h << endl;
      return stream;
}
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Figure.h"
using namespace std;

float get_length(float x_1, float x_2, float y_1, float y_2);
bool belongs_to_line(float x, float x_1, float x_2, float y, float y_1, float y_2);

   Figure::Figure(float x1_, float x2_, float x3_, float x4_,
      float y1_, float y2_, float y3_, float y4_)
   {
      x1 = x1_;
      x2 = x2_;
      x3 = x3_;
      x4 = x4_;

      y1 = y1_;
      y2 = y2_;
      y3 = y3_;
      y4 = y4_;

      AB = get_length(x1, x2, y1, y2);
      BC = get_length(x2, x3, y2, y3);
      CD = get_length(x3, x4, y3, y4);
      DA = get_length(x4, x1, y4, y1);
      AC = get_length(x1, x3, y1, y3);
      BD = get_length(x2, x4, y2, y4);

      P = 0;
      S = 0;
      if (this->is_prug(false))
      {
         P = AB + BC + CD + DA;
         S = 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - y1 * x2 - y2 * x3 - y3 * x4 - y4 * x1);
      }
   }

   void Figure::show() {
      cout << "Координаты точек четырехугольника: " << endl;
      cout << "Точка A( " << x1 << " ; " << y1 << " )" << endl;
      cout << "Точка B( " << x2 << " ; " << y2 << " )" << endl;
      cout << "Точка C( " << x3 << " ; " << y3 << " )" << endl;
      cout << "Точка D( " << x4 << " ; " << y4 << " )" << endl;
      cout << "Периметр P(ABCD): " << P << endl;
      cout << "Площадь S(ABCD): " << S << endl;
   }

   bool Figure::is_prug(bool flag) {
      bool point_C_in_AB = belongs_to_line(x3, x1, x2, y3, y1, y2);
      bool point_D_in_AB = belongs_to_line(x4, x1, x2, y4, y1, y2);

      bool point_A_in_BC = belongs_to_line(x1, x2, x3, y1, y2, y3);
      bool point_D_in_BC = belongs_to_line(x4, x2, x3, y4, y2, y3);

      bool point_A_in_CD = belongs_to_line(x1, x3, x4, y1, y3, y4);
      bool point_B_in_CD = belongs_to_line(x2, x3, x4, y2, y3, y4);

      bool point_B_in_DA = belongs_to_line(x2, x4, x1, y2, y1, y1);
      bool point_C_in_DA = belongs_to_line(x3, x4, x1, y3, y1, y1);

      if (flag)
      {
         cout << endl << "point_C_in_AB " << point_C_in_AB << endl <<
            "point_D_in_AB " << point_D_in_AB << endl <<
            "point_A_in_BC " << point_A_in_BC << endl <<
            "point_D_in_BC " << point_D_in_BC << endl <<
            "point_A_in_CD " << point_A_in_CD << endl <<
            "point_B_in_CD " << point_B_in_CD << endl <<
            "point_B_in_DA " << point_B_in_DA << endl <<
            "point_C_in_DA " << point_C_in_DA << endl << endl;
      }

      if (point_C_in_AB == true || point_D_in_AB == true ||
         point_A_in_BC == true || point_D_in_BC == true ||
         point_A_in_CD == true || point_B_in_CD == true ||
         point_B_in_DA == true || point_C_in_DA == true)
      {
         return false;
      }
      return true;
   }

   bool Figure::is_square() {
      if (AB == BC && BC == CD && CD == DA && S == AB * AB)
         return true;
      return false;
   }

   bool Figure::is_romb() {
      if (AB == BC && BC == CD && CD == DA && ((BD == 2 * AC / 3) || (AC == 2 * BD / 3)))
         return true;
      return false;
   }

   bool Figure::is_in_circle() {
      pair<float, float> vect_AB = make_pair((x2 - x1), (y2 - y1));
      pair<float, float> vect_AD = make_pair((x4 - x1), (y4 - y1));
      float cos_A = (vect_AB.first * vect_AD.first + vect_AB.second * vect_AD.second) / (AB * DA);

      pair<float, float> vect_CB = make_pair((x2 - x3), (y2 - y3));
      pair<float, float> vect_CD = make_pair((x4 - x3), (y4 - y3));
      float cos_C = (vect_CB.first * vect_CD.first + vect_CB.second * vect_CD.second) / (BC * CD);

      if (180 == (int)((abs(acos(cos_A)) + abs(acos(cos_C))) * 180 / M_PI))
         return true;
      return false;
   }

   bool Figure::is_out_circle() {
      if (this->is_prug(false) && ((AB + CD) == (BC + DA)))
         return true;
      return false;
   }

float get_length(float x_1, float x_2, float y_1, float y_2) {
   float l = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));
   return l;

}

bool  belongs_to_line(float x, float x_1, float x_2, float y, float y_1, float y_2)
{
   float S = (x_1 - x) * (y_2 - y) - (y_1 - y) * (x_2 - x);
   if (0 == S)
      return true;
   return false;
}
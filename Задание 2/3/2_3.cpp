#include <iostream>
#include "Figure.h"
using namespace std;

void show_info_fig(Figure& fig);

int main()
{
   setlocale(LC_ALL, "RU");
   Figure fig_1(1, 1, 5, 5, 1, 5, 5, 1); // Квадрат
   Figure fig_2(3, 1, 3, 5, 1, 4, 7, 4); // Ромб
   Figure fig_3(1, 1, 5, 1, 1, 5, 5, 3); // Треугольник
   Figure fig_4(1, 3, 7, 5, 1, 5, 5, 1); // Выпуклый четырехугольник
   Figure fig_5(5, 8, 10, 8, 2, 8, 2, 4); // Вогнутый многоугольник
   Figure fig_6(1, 5, 10, 6, 1, 5, 5, 1); // Параллелограмм

   cout << "Фигура fig_1 " << endl;
   fig_1.show();
   show_info_fig(fig_1);

   cout << "Фигура fig_2 " << endl;
   fig_2.show();
   show_info_fig(fig_2);

   cout << "Фигура fig_3 " << endl;
   fig_3.show();
   show_info_fig(fig_3);

   cout << "Фигура fig_4 " << endl;
   fig_4.show();
   show_info_fig(fig_4);

   cout << "Фигура fig_5 " << endl;
   fig_5.show();
   show_info_fig(fig_5);

   cout << "Фигура fig_6 " << endl;
   fig_6.show();
   show_info_fig(fig_6);
}

void show_info_fig(Figure &fig) {
   if (fig.is_prug(false))
   {
      if (fig.is_square())
         cout << "Является квадратом" << endl;
      else if (fig.is_romb())
         cout << "Является ромбом" << endl;
      else
         cout << "Является 4-угольником" << endl;
   }
   else
      cout << "Не является 4-угольником" << endl;

   if (fig.is_in_circle())
      cout << "Может быть вписан в окружность" << endl;
   else
      cout << "Не может быть вписан в окружность" << endl;

   if (fig.is_out_circle())
      cout << "Можно вписать окружность" << endl << endl;
   else
      cout << "Нельзя вписать окружность" << endl << endl;
}
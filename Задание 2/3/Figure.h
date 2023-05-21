#ifndef _FIGURE_H
#define _FIGURE_H

class Figure {
private:
   float x1, x2, x3, x4;
   float y1, y2, y3, y4;
   float AB, BC, CD, DA, AC, BD;
   float S;
   float P;

public:
   Figure(float x1_, float x2_, float x3_, float x4_,
      float y1_, float y2_, float y3_, float y4_);

   void show();

   bool is_prug(bool flag);

   bool is_square();

   bool is_romb();

   bool is_in_circle();

   bool is_out_circle();
};

#endif// _FIGURE_H
#ifndef _CIRCLE_H
#define _CIRCLE_H

class Circle {
private:
   float radius, x_center, y_center;
public:
   Circle(float radius_, float x_center_, float y_center_);
   void set_circle(float r, float x, float y);
   float get_radius();
   float get_x_center();
   float get_y_center();
   void show_parms();
   float square();
   bool triangle_around(float a, float b, float c);
   bool triangle_in(float a, float b, float c);
   bool check_circle(float r, float x_cntr, float y_cntr);
};

#endif // _CIRCLE_H


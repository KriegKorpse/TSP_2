#ifndef _TRIANGLE_H
#define _TRIANGLE_H

class Triangle {
private:
   double a, b, c;

public:
   bool exist_tr();
   void set(double a_, double b_, double c_);
   void show();
   double perimeter();
   double square();
};

#endif // _TRIANGLE_H


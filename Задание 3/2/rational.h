#ifndef _RATIONAL_H
#define _RATIONAL_H

class rational {
private:
   int a, b;
public:
   rational();

   rational(const int a_, const int b_);

   void set(int a_, int b_);

   void show();
};

#endif //_RATIONAL_H

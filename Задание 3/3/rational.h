#ifndef _RATIONAL_H
#define _RATIONAL_H

class rational {
private:
   int a, b;
   bool sign; //true = + ; false = -
   void set_sign(int a_, int b_);
public:
   rational();

   rational(const int a_, const int b_);

   void set(int a_, int b_);

   void show();

   rational operator + (const rational& rat);
   friend rational operator - (const rational& rat_1, const rational& rat_2);
   rational& operator ++ (); // префиксный инкремент
   rational& operator ++ (int); // постфиксный инкремент
   bool operator == (const rational rat);
   bool operator > (const rational rat);
   rational operator = (rational const& rat);
};

#endif //_RATIONAL_H

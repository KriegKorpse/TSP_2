#include <iostream>
#include <cmath>
#include <sstream>
#include "Ops.h"
using namespace std;

Ops::Ops() {
   a = 0;
   b = 0;
   res = 0;
}

Ops::Ops(int a_, int b_) {
	a = a_;
	b = b_;
   res = 0;
}
int Ops::add() {
    try {
       bool flag = ((a > 0) && (b > 0) && (a > INT_MAX - b)) || ((a < 0) && (b < 0) && (a < INT_MIN - b));
       if (flag)
          throw overflow_error("overflow a + b");
       else {
          res = a + b;
          cout << "res: " << res << endl;
       }
         
    }
    catch (overflow_error& e) {
        cout << "error: " << e.what() << endl;
        return 0;
    }
    return res;
}
int Ops::sub() {
   try {
      bool flag = ((a > 0) && (b < 0) && (a > INT_MAX + b)) || ((a < 0) && (b > 0) && (a < INT_MIN + b));
      if (flag)
         throw overflow_error("overflow a - b");
      else {
         res = a - b;
         cout << "res: " << res << endl;
      }
   }
    catch (overflow_error& e) {
        cout << "error: " << e.what() << endl;
        return 0;
    }
    return res;
}

int Ops::div() {
    try {
        if (b == 0) {
            throw runtime_error("div by 0"); // бросаем исключение
        }
        res = a / b;
        cout << "Res: " << res << endl;
        return res;
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
        return 0;
    }
}

int Ops::mult() {
    try {
       bool flag =  (a > 0 && b > 0 && a > INT_MAX / b) ||
                    (a > 0 && b < 0 && b < INT_MIN / a) ||
                    (a < 0 && b > 0 && a < INT_MIN / b) ||
                    (a < 0 && b < 0 && a < INT_MAX / b);
       if(flag)
         throw overflow_error("oveflow a * b");
       else {
         res = a * b;
         cout << "Res: " << res << endl;
       } 
    }
    catch (overflow_error& e) {
       cout << "Error: " << e.what() << endl;
       return 0;
    }
    return res;
}

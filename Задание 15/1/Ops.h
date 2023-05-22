#ifndef _OPS_H_
#define _OPS_H_

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Ops {
    int a, b, res;

public:
    Ops();
    Ops(int a_, int b_);
    int add();
    int sub();
    int div();
    int mult();

};

#endif //_OPS_H_

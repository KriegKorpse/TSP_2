#include <iostream>
#include "Ops.h"
using namespace std;

int main() {
    Ops p1(INT_MAX, 1);
    Ops p2(INT_MIN, -1);
    p1.add();
    p2.add();
    Ops p3(INT_MIN, +1);
    Ops p4(-4, 1996);

    p3.sub();
    p4.sub();
    Ops p5(300000, 0);
    Ops p6(300000, 2);

    p5.div();
    p6.div();
    Ops p7(INT_MAX, 2);
    Ops p8(250, 2);
    p7.mult();
    p8.mult();
    return 0;
}

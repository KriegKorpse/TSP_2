#ifndef _ARRAY_H_
#define _ARRAY_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Array {
    vector <int> a;

public:
    Array();
    bool add();
    bool remove(int a);
    bool show(int a);

};

#endif //_ARRAY_H_

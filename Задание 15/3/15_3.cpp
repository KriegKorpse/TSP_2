#include <iostream>
#include "Set.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    Set<int> s(5);
    s.Get(1);
    s.Add(1);
    s.Add(2);
    s.Add(3);
    s.Add(4);
    s.Add(5);
    cout << "Set: " << s << endl;
    s.Get(10);
    cout << "Set: " << s << endl;
    return 0;
}

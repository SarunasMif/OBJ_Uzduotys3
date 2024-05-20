#include <iostream>
#include "Vector_Lib.h"

using namespace std;

int main() {
    Vector_Lib<int> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(i + 2);
    }

    v.print();
    v.size();
    v.capacity();
    v.pop_back();
    v.print();
    
    system("pause");
}
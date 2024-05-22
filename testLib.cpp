#include "Vector_Lib.h"
#include <iostream>
#include <span>

using namespace std;

int main() {
    Vector_Lib<int> vec;
    
    for (int i = 0; i < 3; i++) {
        vec.push_back(i + 1);
    }
    

    vec.print();

    vec.insert(1, 9);

    vec.print();

    vec.insert(1, 9);

    vec.print();

    // vec.insert(1, 2, 6);

    // vec.print();

    // vec.insert(1, 3, 8);

    // vec.print();

    // vec.insert(1, 4, 7);

    // vec.print();

    vec.push_back(12);

    vec.print();

    system("pause");

    return 0;
}
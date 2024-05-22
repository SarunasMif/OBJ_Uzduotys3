#include "Vector_Lib.h"
#include <iostream>
#include <span>

using namespace std;

int main() {
    Vector_Lib<int> vec;
    Vector_Lib<int> vec2;
    
    for (int i = 0; i < 3; i++) {
        vec.push_back(i + 1);
    }
    
    for (int i = 0; i < 3; i++) {
        vec2.push_back(i + 3);
    }

    cout << "v1: ";
    vec.print();
    cout << "v2: ";
    vec2.print();

    vec.swap(vec2);

    cout << "v1: ";
    vec.print();
    cout << "v2: ";
    vec2.print();


    system("pause");

    return 0;
}
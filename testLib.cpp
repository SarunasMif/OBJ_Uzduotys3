#include "Vector_Lib.h"
#include <iostream>
#include <span>

int main() {
    Vector_Lib<int> vec;
    std::cout << "Max size of int vector: " << vec.max_size() << std::endl;

    Vector_Lib<double> vecDouble;
    std::cout << "Max size of double vector: " << vecDouble.max_size() << std::endl;


    Vector_Lib<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for (int value : vec) {
        cout << value << " ";
    }

    int* arr = vec.data();

    system("pause");

    return 0;
}
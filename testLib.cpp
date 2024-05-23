#include "Vector_Lib.h"
#include "Studentas.h"

int main() {
    Vector_Lib<int> vec;
    
    for (int i = 0; i < 15; i++) {
        vec.push_back(i);
    }

    std::cout << "Original vector: ";
    vec.print();
    std::cout << endl;

    vec.erase(2);
    std::cout << "Vector after erasing the 3rd member: ";
    vec.print();
    std::cout << endl;

    vec.erase(vec.begin() + 4, vec.end() - 1);
    std::cout << "Vector after erasing all members accept the first four and the last: ";
    vec.print();
    std::cout << endl;


    system("pause");
}
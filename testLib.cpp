#include <iostream>
#include "Vector_Lib.h"

using namespace std;

int main() {
    Vector_Lib<int> v;

    cout << v.empty() << endl;

    for (int i = 0; i < 5; i++) {
        v.push_back(i + 2);
    }

    v.print();
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.pop_back();
    v.print();
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v.empty() << endl;
    system("pause");
}
//#include "includes.h"
#include "Vector_Lib.h"

template <typename V_Lib>
void Vector_Lib<V_Lib>::push_back(V_Lib data) {
    if (current == Capacity) {
        V_Lib*  temp = new V_Lib[2 * Capacity];

        for (int i = 0; i < Capacity; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        Capacity *= 2;
        arr = temp;
    }

    arr[current] = data;
    current++;
}

template <typename V_Lib>
int Vector_Lib<V_Lib>::size() {
    return current;
}

template <typename V_Lib>
int Vector_Lib<V_Lib>::capacity() {
    return Capacity;
}

template <typename V_Lib>
void Vector_Lib<V_Lib>::pop_back() {
    current--;
}

template class Vector_Lib<int>;
template class Vector_Lib<char>;
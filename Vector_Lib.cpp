//#include "includes.h"
#include "Vector_Lib.h"

template <typename V_Lib>
void Vector_Lib<V_Lib>::push_back(V_Lib data) {
    if (current == Capacity) {
        V_Lib* temp = new V_Lib[2 * Capacity];

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

template <typename V_Lib>
V_Lib Vector_Lib<V_Lib>::front() {
    if (Capacity == 0) {
        throw out_of_range("Index out of range!");
    }

    return arr[0];
}

template <typename V_Lib>
V_Lib Vector_Lib<V_Lib>::back() {
    if (Capacity == 0) {
        throw out_of_range("Index out of range!");
    }

    return arr[current - 1];
}

template <typename V_Lib> 
bool Vector_Lib<V_Lib>::empty() const {
    if (current == 0) {
        return true;
    } else {
        return false;
    }
}

template class Vector_Lib<int>;
template class Vector_Lib<char>;
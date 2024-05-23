//#include "includes.h"
#include "Vector_Lib.h"

/*Lines of code that are commeted out is code that the program supposedly has no reference for so it was integrated in the Vecor_Lib.h file to solve the issue.
As for why the issue is a thing in the first place i have no idea.*/

// template <typename V_Lib>
// void Vector_Lib<V_Lib>::push_back(V_Lib data) {
//     if (current == Capacity) {
//         V_Lib* temp = new V_Lib[2 * Capacity];

//         for (int i = 0; i < Capacity; i++) {
//             temp[i] = arr[i];
//         }

//         delete[] arr;
//         Capacity *= 2;
//         arr = temp;
//     }

//     arr[current] = data;
//     current++;
// }

// template <typename V_Lib>
// int Vector_Lib<V_Lib>::size() const {
//     return current;
// }

template <typename V_Lib>
int Vector_Lib<V_Lib>::capacity() const {
    return Capacity;
}

// template <typename V_Lib>
// void Vector_Lib<V_Lib>::pop_back() {
//     current--;
// }

template <typename V_Lib>
void Vector_Lib<V_Lib>::clear() {
    delete[] arr;
    arr = new V_Lib[1];
    current = 0;
}

template <typename V_Lib>
V_Lib Vector_Lib<V_Lib>::front() const{
    if (Capacity == 0) {
        throw out_of_range("Index out of range!");
    }

    return arr[0];
}

// template <typename V_Lib>
// V_Lib Vector_Lib<V_Lib>::back() const{
//     if (Capacity == 0) {
//         throw out_of_range("Index out of range!");
//     }

//     return arr[current - 1];
// }

template <typename V_Lib> 
bool Vector_Lib<V_Lib>::empty() const {
    if (current == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename V_Lib>
V_Lib& Vector_Lib<V_Lib>::at(int index) {
    if (index < 0 || index > current) {
        throw out_of_range("Index out of range!");
    } else {
        return arr[index];
    }
}

template <typename V_Lib>
const V_Lib& Vector_Lib<V_Lib>::at(int index) const {
    if (index < 0 || index > current) {
        throw out_of_range("Index out of range!");
    } else {
        return arr[index];
    }
}

// template <typename V_Lib>
// V_Lib& Vector_Lib<V_Lib>::operator[](int index) {
//     if (index < 0 || index >= current) {
//         throw out_of_range("Index out of range!");
//     } else {
//         return arr[index];
//     }
// }

// template <typename V_Lib>
// Vector_Lib<V_Lib>::Vector_Lib(const Vector_Lib& Adata) : Capacity(Adata.Capacity), current(Adata.current) {
//     arr = new V_Lib[Capacity];

//     for (int i = 0; i < current; i++) {
//         arr[i] = Adata.arr[i];
//     }
// }

template <typename V_Lib>
Vector_Lib<V_Lib>& Vector_Lib<V_Lib>::operator=(const Vector_Lib& Adata) {
    if (this == &Adata) {
        return *this;
    }

    delete[] arr;

    Capacity = Adata.Capacity;
    current = Adata.current;
    arr = new V_Lib[Capacity];

    for (int i = 0; i < current; i++) {
        arr[i] = Adata.arr[i];
    }

    return *this;
}

template <typename V_Lib>
Vector_Lib<V_Lib>::Vector_Lib(Vector_Lib&& Adata) noexcept : arr(Adata.arr), Capacity(Adata.Capacity), current(Adata.current) {
   Adata.arr = nullptr;
   Adata.Capacity = 1;
   Adata.current = 0;
}

template <typename V_Lib>
Vector_Lib<V_Lib>& Vector_Lib<V_Lib>::operator=(Vector_Lib&& Adata) noexcept {
    if (this != &Adata) {
        delete[] arr;

        arr = Adata.arr;
        Capacity = Adata.Capacity;
        current = Adata.current;

        Adata.arr = nullptr;
        Adata.Capacity = 1;
        Adata.current = 0;
    }

    return *this;
}

template <typename V_Lib>
void Vector_Lib<V_Lib>::reserve(int size) {
    if (size < 0 || size == 0) {
        throw out_of_range("Index out of range!");
    } else {
        Capacity = size;
    }
}

template <typename V_Lib>
void Vector_Lib<V_Lib>::shrink_to_fit() {
    if (current == 0) {
        Capacity = 1;
    }
    else if (current > 0) {
        Capacity = current;
    }
}

template <typename V_Lib>
size_t  Vector_Lib<V_Lib>::max_size() {
    return numeric_limits<size_t>::max() / sizeof(V_Lib);
}

template <typename V_Lib>
V_Lib* Vector_Lib<V_Lib>::data() const {
    return arr;
}

template <typename V_Lib>
void Vector_Lib<V_Lib>::erase(size_t pos) {
    if (pos < 0 || pos > current) {
        throw out_of_range("Index out of range!");
    } else {
        V_Lib* temp = new V_Lib[Capacity];
        for (size_t i = 0; i < pos; i++) {
            temp[i] = arr[i];
        }

        for (size_t i = pos + 1; i < current; i++) {
            temp[i - 1] = arr[i];
        }

        delete[] arr;
        arr = temp;
        current--;
    }

}

template <typename V_Lib>
void Vector_Lib<V_Lib>::insert(size_t pos, const V_Lib& stuff) {
    if (pos < 0 || pos > current) {
        throw out_of_range("Index out of range!");
    } else {
        size_t new_cap = current + 1;

        V_Lib* temp = new V_Lib[new_cap];

        for (size_t i = 0; i < pos; i++) {
            temp[i] = arr[i];
        }

        temp[pos] = stuff;

        for (size_t i = pos; i < current; i ++) {
            temp[i + 1] = arr[i];
        }

        delete[] arr;
        arr = temp;
        Capacity = new_cap;
        current = new_cap;
    }
}// no bueno

template <typename V_Lib>
void Vector_Lib<V_Lib>::insert(size_t pos, int number, const V_Lib& stuff) {
    if (pos < 0 || pos > current || number < 0) {
        throw out_of_range("Index out of range!");
    } else {
        size_t new_cap = current + number;

        V_Lib* temp = new V_Lib[new_cap];

        for (size_t i = 0; i < pos; i++) {
            temp[i] = arr[i];
        }

        for (size_t i = pos; i < number + pos; i++) {
            temp[i] = stuff;
        }

        for (size_t i = pos; i < current; i ++) {
            temp[i + number] = arr[i];
        }

        delete[] arr;
        arr = temp;
        Capacity = new_cap;
        current = new_cap;
    }

    
}

template <typename V_Lib>
void Vector_Lib<V_Lib>::resize(int size) {
    if (size < 0) {
        throw out_of_range("Index out of range!");
    } else {
        int new_capacity = size;

        V_Lib* temp = new V_Lib[new_capacity];

        if (new_capacity > Capacity) {
            for (int i = 0; i < current; i++) {
                temp[i] = arr[i];
            }

            for (int i = current; i < new_capacity; i++) {
                temp[i] = 0;
            }

            delete[] arr;
            arr = temp;
            Capacity = new_capacity;
            current = new_capacity;
        } else {
            for (int i = 0; i < new_capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = temp;
            Capacity = new_capacity;
            current = new_capacity;
        }
    }
}

template <typename V_Lib>
void Vector_Lib<V_Lib>::resize(int size, int filler) {
    if (size < 0) {
        throw out_of_range("Index out of range!");
    } else {
        int new_capacity = size;

        V_Lib* temp = new V_Lib[new_capacity];

        if (new_capacity > Capacity) {
            for (int i = 0; i < current; i++) {
                temp[i] = arr[i];
            }

            for (int i = current; i < new_capacity; i++) {
                temp[i] = filler;
            }

            delete[] arr;
            arr = temp;
            Capacity = new_capacity;
            current = new_capacity;
        } else {
            for (int i = 0; i < new_capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = temp;
            Capacity = new_capacity;
            current = new_capacity;
        }
    }
}

template <typename V_Lib>
void Vector_Lib<V_Lib>::swap(Vector_Lib<V_Lib>& vector) {
    std::swap(arr, vector.arr);
    std::swap(Capacity, vector.Capacity);
    std::swap(current, vector.current);
}

template class Vector_Lib<int>;
template class Vector_Lib<char>;
template class Vector_Lib<double>;
template class Vector_Lib<long>;
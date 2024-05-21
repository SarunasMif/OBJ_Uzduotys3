#ifndef VECTOR_LIB_H
#define VECTOR_LIB_H

#include "includes.h"
#include <limits>
#include <algorithm>

using namespace std;

template <typename V_Lib> 

class Vector_Lib {
    V_Lib* arr;
    int Capacity;
    int current;

public:
    Vector_Lib(){arr = new V_Lib[1]; Capacity = 1; current = 0;} // Constructor
    ~Vector_Lib() { delete[] arr; } // Deconstructor
    Vector_Lib(const Vector_Lib& Adata); // Copy constructor
    Vector_Lib<V_Lib>& operator=(const Vector_Lib& Adata); // Copy assignment
    Vector_Lib(Vector_Lib&& Adata) noexcept; // Move constructor
    Vector_Lib<V_Lib>& operator=(Vector_Lib&& Adata) noexcept; //Move assignment

    // int Le_Capacity() const { return Capacity;}
    // int Le_current() const { return current;}
    // V_Lib Le_arr() const { return arr;}
    // Getters

    // Modifiers functions ---------------------------------------------------- 4/11
    void push_back(V_Lib data);
    void pop_back();
    void clear();
    void erase(size_t pos);
    void erase(size_t start, size_t end);
    // Capacity functions ----------------------------------------------------- 6/6
    int size();
    int capacity();
    bool empty() const;
    void reserve(int size);
    void shrink_to_fit();
    static size_t max_size();
    // Element access --------------------------------------------------------- 5/5
    V_Lib front();
    V_Lib back();
    V_Lib& at(int index);
    V_Lib& operator[](int index);
    V_Lib* data() const;
    // Iterators -------------------------------------------------------------- 4/4
    class Iterator {
        private:
            V_Lib* ptr;
        public:
            Iterator(V_Lib* p) : ptr(p) {} // Constructor

            V_Lib& operator*() const {
                return *ptr;
            }

            Iterator& operator++() {
                ++ptr;
                return *this;
            }

            bool operator==(const Iterator& other) const {
                return ptr == other.ptr;
            }

            bool operator!=(const Iterator& other) const {
                return ptr != other.ptr;
            }
    };

    Iterator begin() const {
        return Iterator(arr);
    }

    Iterator end() const {
        return Iterator(arr + current);
    }

    Iterator rbegin() const {
        return Iterator(arr + current - 1);
    }

    Iterator rend() const {
        return Iterator(arr - 1);
    }

    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }// delete later 
};

#endif
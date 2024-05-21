#ifndef VECTOR_LIB_H
#define VECTOR_LIB_H

#include "includes.h"

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

    // Modifiers functions ----------------------------------------------------
    void push_back(V_Lib data);
    void pop_back();
    void clear();
    // Capacity functions -----------------------------------------------------
    int size();
    int capacity();
    bool empty() const;
    // Element access ---------------------------------------------------------
    V_Lib front();
    V_Lib back();
    V_Lib at(int index);
    V_Lib& operator[](int index);
    // data functions kai issiaikinsiu ka ji daro

    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }// delete later 
};

#endif
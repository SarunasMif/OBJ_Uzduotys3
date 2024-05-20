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

    // int Le_Capacity() const { return Capacity;}
    // int Le_current() const { return current;}
    // V_Lib Le_arr() const { return arr;}
    // Getters

    // Modifiers functions ----------------------------------------------------
    void push_back(V_Lib data);
    void pop_back();
    // Capacity functions -----------------------------------------------------
    int size();
    int capacity();
    bool empty() const;
    // Element access ---------------------------------------------------------
    V_Lib front();
    V_Lib back();
    V_Lib at(int index);
    V_Lib& operator[](int index);
    V_Lib b();

    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }// delete later 
};

#endif
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

    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }// delete later 
};

#endif
#ifndef VECTOR_LIB_H
#define VECTOR_LIB_H

#include "includes.h"
#include <limits>
#include <algorithm>
//#include <iterator>


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

    // Modifiers functions ---------------------------------------------------- 6/11
    void push_back(V_Lib data);
    void pop_back();
    void clear();
    void erase(size_t pos); // 1/2
    void erase(size_t start, size_t end); // 2/2
    void insert(size_t pos, const V_Lib& stuff); // 1/3
    void insert(size_t pos, int number, const V_Lib& stuff);  // 2/3

    template <class InputIt>
    void insert(const size_t pos, InputIt first, InputIt last) {
        if (pos < 0 || pos > current) {
            throw out_of_range("Index out of range!");
        } else {
            size_t size = distance(first, last);
            size_t new_cap = current + size;

            V_Lib* temp = new V_Lib[new_cap];

            for (size_t i = 0; i < pos; i++) {
                temp[i] = arr[i];
            }

            size_t index = pos;
            for (auto i = first; i != last; i++) {
                temp[index++] = *i;
            }

            for (size_t i = pos; i < current; i ++) {
                temp[i + size] = arr[i];
            }

            delete[] arr;
            arr = temp;
            Capacity = new_cap;
            current = new_cap;
        }
    }; // Ikisau cia, nes man kroniskai mete "undefined reference" nor ir buvo defined // 3/3

    void resize(int size);
    void resize(int size, int filler);

    template <class InputIt>
    void append_range(InputIt first, InputIt last) {

        size_t size = distance(first, last);
        size_t new_cap = current + size;

        V_Lib* temp = new V_Lib[new_cap];

        for (size_t i = 0; i < current; i++) {
            temp[i] = arr[i];
        }

        size_t index = current;
        for (auto i = first; i != last; i++) {
            temp[index++] = *i;
        }

        delete[] arr;
        arr = temp;
        Capacity = new_cap;
        current = new_cap;

    } // reference ptsd

    void swap(Vector_Lib& vector);
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
    using iterator = V_Lib*;

    iterator begin() {return arr;}
    iterator end() {return arr + current;}
    iterator rbegin() {return arr + current;}
    iterator rend() {return arr;}

    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }// delete later 
};

#endif
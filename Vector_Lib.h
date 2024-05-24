#ifndef VECTOR_LIB_H
#define VECTOR_LIB_H

#include <iostream>
#include <limits>
#include <algorithm>
#include <memory>
#include <iterator>

using namespace std;

template <typename V_Lib> 

class Vector_Lib {
    V_Lib* arr;
    int Capacity;
    int current;

public:
    using iterator = V_Lib*;
    using const_iterator = const V_Lib*;

    // Member Types -------------------------------------------------------------
    typedef V_Lib value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;

    Vector_Lib(){arr = new V_Lib[1]; Capacity = 1; current = 0;} // Constructor
    explicit Vector_Lib(int capacity) : arr(new V_Lib[capacity]), Capacity(capacity), current(0) {}
    ~Vector_Lib() { delete[] arr; } // Deconstructor
    Vector_Lib(const Vector_Lib& Adata) : Capacity(Adata.Capacity), current(Adata.current) {
        arr = new V_Lib[Capacity];

        for (int i = 0; i < current; i++) {
            arr[i] = Adata.arr[i];
        }
    }; // Copy constructor
    Vector_Lib<V_Lib>& operator=(const Vector_Lib& Adata); // Copy assignment
    Vector_Lib(Vector_Lib&& Adata) noexcept; // Move constructor
    Vector_Lib<V_Lib>& operator=(Vector_Lib&& Adata) noexcept; //Move assignment

    // Modifiers functions ---------------------------------------------------- 8/11
    void push_back(V_Lib data) {      
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

    };
    void pop_back() {current--;};
    void clear() {
        delete[] arr;
        arr = new V_Lib[1];
        current = 0;
    };
    void erase(size_t pos); // 1/2

    template <typename InputIt>
    void erase(InputIt first, InputIt last) {
        iterator first_value = first;
        iterator last_value = last;

        if (first_value >= arr && last_value <= arr + current) {
            copy(last_value, arr + current, first_value);
            current -= (last_value - first_value);
        }
    } // 2/2

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
    }; // Ikisau cia, nes man kroniskai mete "undefined reference" nors ir buvo defined // 3/3

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
    int size() const {
        return current;
    };
    int capacity() const;
    bool empty() const;
    void reserve(int size);
    void shrink_to_fit();
    static size_t max_size();
    // Element access --------------------------------------------------------- 5/5
    V_Lib front() const;
    V_Lib back() const {
        if (Capacity == 0) {
            throw out_of_range("Index out of range!");
        }

        return arr[current - 1];
    };
    V_Lib& at(int index);
    const V_Lib& at(int index) const;
    V_Lib& operator[](int index) {
        if (index < 0 || index >= current) {
            throw out_of_range("Index out of range!");
        } else {
            return arr[index];
        }
    };
    V_Lib* data() const;
    // Iterators -------------------------------------------------------------- 4/4

    iterator begin() {return arr;}
    const_iterator begin() const {return arr;}
    iterator end() {return arr + current;}
    const_iterator end() const {return arr + current;}
    iterator rbegin() {return arr + current - 1;}
    iterator rend() {return arr - 1;}
    const_iterator cbegin() const {return arr;}
    const_iterator cend() const {return arr + current;}

    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }// delete later 

};

#endif
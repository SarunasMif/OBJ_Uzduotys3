# Obj_Uzduotys3

# Spartos analizė 1

| Test 1 |
| Elementu skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 10000 | 0.0001812 s | 0.000102 s |
| 100000 | 0.0014087 s | 0.000753 s |
| 1000000 | 0.0082862 s | 0.0060813 s|
| 10000000 | 0.0751286 s| 0.0632606 s|
| 100000000 | 0.714488 s| 0.0545918 s|

| Test 2 |
| Elementu skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 10000 | 0.0001056 s | 0.0001116 s |
| 100000 | 0.0009402 s| 0.0006627 s|
| 1000000 | 0.0074966 s | 0.0054467 s |
| 10000000 | 0.0734579 s| 0.0617664 s|
| 100000000 | 0.70871 s | 0.541075 s|

| Test3 |
| Elementu skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 10000 | 0.0001346 s | 0.000109 s|
| 100000 | 0.000992 s| 0.0007352 s|
| 1000000 | 0.0074966 s| 0.0054467 s|
| 10000000 | 0.0738471 s | 0.0616216 s|
| 100000000 | 0.699923 s | 0.543998 s|

# Spartos analizė 2
### Failo nuskaitymas
| Test 1|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.005047 s | 0.004853 s |
| 1.000.000 | 0.041024 s | 0.047944 s |
| 10.000.000 | 0.393229 s | 0.440238 s |

| Test 2|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.005278 s | 0.004612 s |
| 1.000.000 | 0.041093 s | 0.051630 s |
| 10.000.000 | 0.390727 s | 0.409186 s |


| Test 3|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.006231 s | 0.006952 s |
| 1.000.000 | 0.045362 s | 0.044390 s |
| 10.000.000 | 0.388422 s | 0.435645 s |

### Studentų rūšiavimas į dvi grupes

| Test 1|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.042480 s | 0.055253 s |
| 1.000.000 | 0.400612 s | 0.556447 s |
| 10.000.000 | 4.133181 s | 5.320045 s |

| Test 2|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.040898 s | 0.056640 s|
| 1.000.000 | 0.401288 s | 0.555743 s |
| 10.000.000 | 4.057258 s | 5.279137 s|


| Test 3|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.041255 s | 0.055249 s |
| 1.000.000 | 0.400448 s | 0.557170 s |
| 10.000.000 | 4.072259 s | 5.268330 s |

### Studentų išvedimas į failą

| Test 1|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.824902 s | 0.684435 s |
| 1.000.000 | 9.990556 s | 7.903053 s|
| 10.000.000 | 111.325708 s | 89.824931 s |

| Test 2|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.812058 s | 0.705150 s|
| 1.000.000 | 10.026291 s | 8.043667 s |
| 10.000.000 | 111.077281 s | 90.445027 s |


| Test 3|
| Studentų skaičius | std::vector | Vector_Lib |
| :---: | :---: | :---: |
| 100.000 | 0.827169 s | 0.682701 s |
| 1.000.000 | 10.082943 s | 7.949102 s |
| 10.000.000 | 110.856787 s | 92.131147 s |

# System specs
Test were run on a system with these specs: `ryzen 5 5600x`, `32gb ddr4 3600mhz`, `rtx 3060 ti`, `250gb Kingston ssd`.

# Vector_Lib functions
Examples for functions `push_back()`, `at()`, `operator[]`, `erase()`, `size()` used in Vector_Lib.

## 1. `push_back()`

```cpp
#include "Vector_Lib.h"
#include "Studentas.h"

int main() {
    Vector_Lib<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec.print();


    system("pause");
}
```
```
Output:
1 2 3
```

## 2. `at()`

```cpp
#include "Vector_Lib.h"
#include "Studentas.h"

int main() {
    Vector_Lib<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << vec.at(1) << endl;


    system("pause");
}
```
```
Output:
2
```

```cpp
#include "Vector_Lib.h"
#include "Studentas.h"

int main() {
    Vector_Lib<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Original vector: " << endl;
    vec.print();

    vec.at(1) = 8;

    std::cout << "Vector after at(1) = 8; : " << endl;
    vec.print();

    system("pause");
}
```

```
Output:
Original vector:
1 2 3
Vector after at(1) = 8; :
1 8 3
```

## 3. `operator[]`

```cpp
#include "Vector_Lib.h"
#include "Studentas.h"

int main() {
    Vector_Lib<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Original vector: ";
    vec.print();
    std::cout << endl;

    std::cout << "Vector value at 3rd position : " << vec[2] << endl;


    system("pause");
}
```
```
Output:
Original vector: 1 2 3
```

## 4. `erase()`

```cpp
#include "Vector_Lib.h"
#include "Studentas.h"

int main() {
    Vector_Lib<int> vec;
    
    for (int i = 0; i < 15; i++) {
        vec.push_back(i);
    }

    std::cout << "Original vector: ";
    vec.print();
    std::cout << endl;

    vec.erase(2);
    std::cout << "Vector after erasing the 3rd member: ";
    vec.print();
    std::cout << endl;

    vec.erase(vec.begin() + 4, vec.end() - 1);
    std::cout << "Vector after erasing all members accept the first four and the last: ";
    vec.print();
    std::cout << endl;


    system("pause");
}
```
```
Output:
Original vector: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

Vector after erasing the 3rd member: 0 1 3 4 5 6 7 8 9 10 11 12 13 14

Vector after erasing all members accept the first four and the last: 0 1 3 4 14
```

## 5. `size`

```cpp
#include "Vector_Lib.h"
#include "Studentas.h"

int main() {
    Vector_Lib<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << vec.size() << endl;


    system("pause");
}
```
```
Output:
3
```
cmake_minimum_required(VERSION 3.29.2)

set(This Main_CMake)

project(Program)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(googletest)

set(Headers 
    Vector_Lib.h
    Studentas.h
    headers_vector.h
)

set(Source 
    Vector_Lib.cpp
    Studentas.cpp
    main_vector.cpp
    
)

add_library(${This} STATIC ${Source} ${Headers})

add_subdirectory(Unit_Tests)

add_executable(Program main_vector.cpp Studentas.cpp)
cmake_minimum_required(VERSION 3.29.2)

set(This Test_CMake)

set(Source 
    Unit_Tests_Vector_Lib.cpp
)

add_executable(${This} ${Source})

target_link_libraries(${This} PUBLIC 
    gtest_main
    Main_CMake
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

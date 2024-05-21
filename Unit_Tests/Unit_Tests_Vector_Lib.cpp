#include "../Vector_Lib.h"
#include <gtest/gtest.h>

TEST(Unit_Tests_VecLib_1, El_acc_Test) {
    Vector_Lib<int> t1;
    t1.push_back(1);
    t1.push_back(2);

    EXPECT_EQ(t1.front(), 1);
    EXPECT_EQ(t1.back(), 2);

    t1.clear();

    EXPECT_EQ(t1.capacity(), 2);
    EXPECT_EQ(t1.size(), 0);
    EXPECT_TRUE(t1.empty());

    for (int i = 0; i < 5; i++) {
        t1.push_back(i + 1);
    }

    int* t_arr = t1.data();

    ASSERT_NE(t_arr, nullptr);
    for (int y = 0; y < 5; y++) {
        EXPECT_EQ(t_arr[y], y + 1);
    }
}

TEST(Unit_Tests_VecLib_2, Cap_Test) {
    Vector_Lib<int> t1;
    EXPECT_EQ(t1.size(), 0);
    EXPECT_EQ(t1.capacity(), 1);
    EXPECT_TRUE(t1.empty());
    // Correctly allocates memory with no elements

    for (int i = 0; i < 3; i++) {
        t1.push_back(i + 2);
    }

    EXPECT_EQ(t1.size(), 3);
    EXPECT_EQ(t1.capacity(), 4);
    EXPECT_FALSE(t1.empty());
    // Correctly allocates memory with elements

    t1.reserve(10);
    EXPECT_EQ(t1.capacity(), 10);

    Vector_Lib<int> t2;

    t2.reserve(3);
    t2.push_back(1);
    t2.push_back(2);
    t2.shrink_to_fit();

    EXPECT_EQ(t2.capacity(), 2);

    t2.clear();
    t2.shrink_to_fit();

    EXPECT_EQ(t2.capacity(), 1);

    t2.push_back(1);

    EXPECT_EQ(t2.capacity(), 1);

}

TEST(Unit_Tests_VecLib_3, Mod_Test) {
    Vector_Lib<int> t1;
    t1.push_back(3);
    EXPECT_EQ(t1.at(0), 3);

    EXPECT_EQ(t1[0], 3);

    t1.push_back(2);
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(t1[i], 3 - i);
    }

    t1.at(0) = 10;
    EXPECT_EQ(t1[0], 10);
    
    Vector_Lib<int> t2;

    for (int i = 0; i < 5; i++) {
        t2.push_back(i + 1);
    }

    t2.erase(4);

    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(t2[i], i + 1);
    }

    t2.erase(1, 3);

    EXPECT_EQ(t2[0], 1);
}

TEST(Unit__Test_VecLib_4, CopCon_Test) {
    Vector_Lib<int> t1;
    
    for (int i = 0; i < 5; i++) {
        t1.push_back(i + 2);
    }

    Vector_Lib<int> t2;

    t2 = t1;

    for (int y = 0; y < 5; y++) {
        EXPECT_EQ(t1[y], t2[y]);
    }
}

TEST(Unit_Test_VecLib5, MovCon_Test) {
    Vector_Lib<int> t1;

    for (int i = 0; i < 5; i++) {
        t1.push_back(i + 2);
    }

    Vector_Lib<int> t2;

    t2 = move(t1);

    for (int y = 0; y < 5; y++) {
        EXPECT_EQ(t2[y], y + 2);
    }

    EXPECT_TRUE(t1.empty());
    EXPECT_EQ(t1.capacity(), 1);

}

TEST(Unite_Test_VecLib6, Iter_Test) {
    Vector_Lib<int> t1;

    for (int i = 0; i < 5; i++) {
        t1.push_back(i + 1);
    }

    int y = 1;
    for (int value : t1) {
        EXPECT_EQ(value, y);
        y++;
    }
    
}

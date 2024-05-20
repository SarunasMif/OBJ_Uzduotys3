#include "../Vector_Lib.h"
#include <gtest/gtest.h>

TEST(Unit_Tests_VecLib_1, El_acc_Test) {
    Vector_Lib<int> t1;
    t1.push_back(1);
    t1.push_back(2);

    EXPECT_EQ(t1.front(), 1);
    EXPECT_EQ(t1.back(), 2);
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
    // TODO: ad opperators to change values at specific indexes (copy, move, set)
}
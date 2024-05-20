#include "../Vector_Lib.h"
#include <gtest/gtest.h>

TEST(Unit_Tests_Class_1, PB_Test) {
    Vector_Lib<int> t1;
    t1.push_back(2);

    EXPECT_EQ(true, true);
}


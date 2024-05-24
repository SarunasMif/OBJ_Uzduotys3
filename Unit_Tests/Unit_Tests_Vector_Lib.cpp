#include "../Vector_Lib.h"
#include <gtest/gtest.h>
#include "../Studentas.h"

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

    t2.erase(t2.begin(), t2.begin() + 3);

    EXPECT_EQ(t2[0], 4);

    Vector_Lib<int> t3;

    t3.insert(0, 3);

    EXPECT_EQ(t3[0], 3);

    t3.insert(1, 2, 3);

    EXPECT_EQ(t3[0], 3) << "test 1" << endl;
    EXPECT_EQ(t3[1], 3) << "test 2" << endl;
    EXPECT_EQ(t3[2], 3) << "test 3" << endl;

    Vector_Lib<int> in;

    for (int i = 0; i < 3; i++) {
        in.push_back(i + 1);
    }

    t3.insert(0, in.begin(), in.end());

    EXPECT_EQ(t3[0], 1);
    EXPECT_EQ(t3[1], 2);

    Vector_Lib<int> t4;

    for (int i = 0; i < 3; i++) {
        t4.push_back(i + 1);
    }

    t4.resize(5);

    EXPECT_EQ(t4.capacity(), 5);
    EXPECT_EQ(t4.size(), 5);
    EXPECT_EQ(t4[3], 0);
    EXPECT_EQ(t4[4], 0);

    t4.resize(2);

    EXPECT_EQ(t4.capacity(), 2);
    EXPECT_EQ(t4.size(), 2);
    EXPECT_EQ(t4[0], 1);
    EXPECT_EQ(t4[1], 2);

    t4.resize(6, 4);

    EXPECT_EQ(t4.capacity(), 6);
    EXPECT_EQ(t4.size(), 6);
    EXPECT_EQ(t4[2], 4);
    EXPECT_EQ(t4[3], 4);
    EXPECT_EQ(t4[4], 4);
    EXPECT_EQ(t4[5], 4);
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

TEST(Unit_Test_VecLib_0, Char_test) {
    Vector_Lib<char> t2;

    t2.push_back('C');
    t2.push_back('D');

    EXPECT_EQ(t2[0], 'C');
    EXPECT_EQ(t2[1], 'D');

    t2.pop_back();

    EXPECT_EQ(t2[0], 'C');

    t2.clear();

    EXPECT_EQ(t2.capacity(), 2);
    EXPECT_EQ(t2.size(), 0);
    EXPECT_TRUE(t2.empty());

}

TEST(Unit_Tests_VecLib_1, El_acc_Test) {
    Vector_Lib<int> t1;
    t1.push_back(1);
    t1.push_back(2);

    EXPECT_EQ(t1.front(), 1);
    EXPECT_EQ(t1.back(), 2);

    t1.pop_back();

    EXPECT_EQ(t1[0], 1);

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

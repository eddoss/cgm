

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrices/Matrix.hpp>


using namespace std;
using Mat22 = Matrix<2,2,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat44 = Matrix<4,4,int>;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_Iterators, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it_01 = input.begin() + Mat33::rows;
    auto it_11 = input.begin() + Mat33::rows + 1;
    auto it_21 = input.begin() + Mat33::rows + 2;

    ASSERT_EQ(*it_01, 2);
    ASSERT_EQ(*it_11, 5);
    ASSERT_EQ(*it_21, 8);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Minus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it_02 = input.end() - 3;
    auto it_12 = input.end() - 2;
    auto it_22 = input.end() - 1;

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*it_12, 6);
    ASSERT_EQ(*it_22, 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.begin();

    ASSERT_EQ(*it, 1);
    ASSERT_EQ(*(++it), 4);
    ASSERT_EQ(*(++it), 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.begin();

    ASSERT_EQ(*(it++), 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, PreDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.end();

    ASSERT_EQ(*(--it), 9);
    ASSERT_EQ(*(--it), 6);
    ASSERT_EQ(*(--it), 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, PostDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    ASSERT_EQ((input.begin()), input.begin());
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, RowsColumns_FirstComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    auto it {input.begin()};
    ASSERT_EQ(it.row(), 0);
    ASSERT_EQ(it.column(), 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, RowsColumns_MidComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    auto it {input.begin() + 5};
    ASSERT_EQ(it.row(), 2);
    ASSERT_EQ(it.column(), 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, RowsColumns_LastComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    auto it {input.begin() + Mat33::size-1};
    ASSERT_EQ(it.row(), 2);
    ASSERT_EQ(it.column(), 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Difference)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto a {input.begin()};
    auto b {input.begin() + 3};

    ASSERT_EQ(b-a, 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Comparison_Equal)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto it_00 = input.begin();
    auto it_same = input.begin();
    auto it_10 = input.begin() + 1;

    ASSERT_TRUE(it_00 == it_same);
    ASSERT_FALSE(it_00 == it_10);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Comparison_NotEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto it_00 = input.begin();
    auto it_same = input.begin();
    auto it_10 = input.begin() + 1;

    ASSERT_TRUE(it_00 != it_10);
    ASSERT_FALSE(it_00 != it_same);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Comparison_Less)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto it_00 = input.begin();
    auto it_10 = input.begin() + 1;

    ASSERT_TRUE(it_00 < it_10);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Comparison_LessOrEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto it_00 = input.begin();
    auto it_same = input.begin();

    ASSERT_TRUE(it_00 <= it_same);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Comparison_Greater)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto it_00 = input.begin();
    auto it_10 = input.begin() + 1;

    ASSERT_TRUE(it_10 > it_00);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Comparison_GreaterOrEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto it_00 = input.begin();
    auto it_same = input.begin();

    ASSERT_TRUE(it_00 >= it_same);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Reverse)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto it_11 = input.rbegin();
    auto it_10 = input.rbegin() + 1;
    auto it_01 = input.rbegin() + 2;
    auto it_00 = input.rbegin() + 3;

    ASSERT_EQ(*it_00, 1);
    ASSERT_EQ(*it_01, 4);
    ASSERT_EQ(*it_10, 2);
    ASSERT_EQ(*it_11, 5);
}
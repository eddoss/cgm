

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Matrices/Matrix.hpp>
#include <Math3D/Core/Structs/Matrices/Operators.hpp>


using namespace std;
using Mat22 = Matrix<2,2,int>;
using Mat23 = Matrix<2,3,int>;
using Mat24 = Matrix<2,4,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat42 = Matrix<4,2,int>;
using Mat43 = Matrix<4,3,int>;
using Mat44 = Matrix<4,4,int>;
using Mat55 = Matrix<5,5,int>;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_Iterator, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.begin() + 1;
    auto it1 = input.begin() + 2;
    auto it2 = input.begin() + 3;

    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        ASSERT_EQ(*it0, 2);
        ASSERT_EQ(*it1, 3);
        ASSERT_EQ(*it2, 4);
    #else
        ASSERT_EQ(*it0, 4);
        ASSERT_EQ(*it1, 7);
        ASSERT_EQ(*it2, 2);
    #endif

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterator, Minus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.end() - 1;
    auto it1 = input.end() - 2;
    auto it2 = input.end() - 3;

    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        ASSERT_EQ(*it0, 9);
        ASSERT_EQ(*it1, 8);
        ASSERT_EQ(*it2, 7);
    #else
        ASSERT_EQ(*it0, 9);
        ASSERT_EQ(*it1, 6);
        ASSERT_EQ(*it2, 3);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterator, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.begin();

    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        ASSERT_EQ(*(++it), 2);
        ASSERT_EQ(*(++it), 3);
    #else
        ASSERT_EQ(*(++it), 4);
        ASSERT_EQ(*(++it), 7);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterator, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.begin();
    it++;

    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        ASSERT_EQ(*(it++), 2);
        ASSERT_EQ(*(it++), 3);
    #else
        ASSERT_EQ(*(it++), 4);
        ASSERT_EQ(*(it++), 7);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterator, PreDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.end();

    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        ASSERT_EQ(*(--it), 9);
        ASSERT_EQ(*(--it), 8);
    #else
        ASSERT_EQ(*(--it), 9);
        ASSERT_EQ(*(--it), 6);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterator, PostDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.end();
    it--;

    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        ASSERT_EQ(*(it--), 9);
        ASSERT_EQ(*(it--), 8);
    #else
        ASSERT_EQ(*(it--), 9);
        ASSERT_EQ(*(it--), 6);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterator, RowsColumns_FirstComponent)
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

TEST(Matrix_Iterator, RowsColumns_MidComponent)
{
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.begin() + 5};

    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        ASSERT_EQ(*it, 6);
        ASSERT_EQ(it.row(), 1);
        ASSERT_EQ(it.column(), 1);
    #else
        ASSERT_EQ(*it, 7);
        ASSERT_EQ(it.row(), 1);
        ASSERT_EQ(it.column(), 2);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterator, RowsColumns_LastComponent)
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

TEST(Matrix_Iterator, Difference)
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

TEST(Matrix_Iterator, Comparison_Equal)
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

TEST(Matrix_Iterator, Comparison_NotEqual)
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

TEST(Matrix_Iterator, Comparison_Less)
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

TEST(Matrix_Iterator, Comparison_LessOrEqual)
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

TEST(Matrix_Iterator, Comparison_Greater)
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

TEST(Matrix_Iterator, Comparison_GreaterOrEqual)
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

TEST(Matrix_Iterator, Reverse)
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
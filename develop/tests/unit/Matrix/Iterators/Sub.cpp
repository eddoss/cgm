

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

TEST(Matrix_SubIterator, Plus)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{0,0},{3,0}};

    auto it_00 = input.beginSub(rect) + 0;
    auto it_10 = input.beginSub(rect) + 1;
    auto it_20 = input.beginSub(rect) + 2;
    auto it_30 = input.beginSub(rect) + 3;

    ASSERT_EQ(*it_00, 11);
    ASSERT_EQ(*it_10, 21);
    ASSERT_EQ(*it_20, 31);
    ASSERT_EQ(*it_30, 41);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Minus)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it_00 = input.endSub(rect) - 4;
    auto it_10 = input.endSub(rect) - 3;
    auto it_01 = input.endSub(rect) - 2;
    auto it_11 = input.endSub(rect) - 1;

    ASSERT_EQ(*it_00, 22);
    ASSERT_EQ(*it_10, 32);
    ASSERT_EQ(*it_01, 23);
    ASSERT_EQ(*it_11, 33);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, PreIncrement)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it = input.beginSub(rect);

    ASSERT_EQ(*(++it), 32);
    ASSERT_EQ(*(++it), 23);
    ASSERT_EQ(*(++it), 33);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, PostIncrement)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it = input.beginSub(rect);

    ASSERT_EQ(*(it++), 22);
    ASSERT_EQ(*(it++), 32);
    ASSERT_EQ(*(it++), 23);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, PreDecrement)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it = input.endSub(rect);

    ASSERT_EQ(*(--it), 33);
    ASSERT_EQ(*(--it), 23);
    ASSERT_EQ(*(--it), 32);
    ASSERT_EQ(*(--it), 22);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, PostDecrement)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it = input.endSub(rect);
    it--;

    ASSERT_EQ(*(it--), 33);
    ASSERT_EQ(*(it--), 23);
    ASSERT_EQ(*(it--), 32);
    ASSERT_EQ(*(it--), 22);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, RowsColumns_FirstComponent)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it = input.beginSub(rect);

    ASSERT_EQ(it.row(), 1);
    ASSERT_EQ(it.column(), 1);
    ASSERT_EQ(it.subRow(), 0);
    ASSERT_EQ(it.subColumn(), 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, RowsColumns_MidComponent)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it = input.beginSub(rect) + 2;

    ASSERT_EQ(it.row(), 1);
    ASSERT_EQ(it.column(), 2);
    ASSERT_EQ(it.subRow(), 0);
    ASSERT_EQ(it.subColumn(), 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, RowsColumns_LastComponent)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it = --input.endSub(rect);

    ASSERT_EQ(it.row(), 2);
    ASSERT_EQ(it.column(), 2);
    ASSERT_EQ(it.subRow(), 1);
    ASSERT_EQ(it.subColumn(), 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Difference)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto a {input.beginSub(rect)};
    auto b {input.beginSub(rect) + 3};

    ASSERT_EQ(b-a, 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Comparison_Equal)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{0,0},{2,2}};

    auto it_00 = input.beginSub(rect);
    auto it_same = input.beginSub(rect);
    auto it_10 = input.beginSub(rect) + 1;

    ASSERT_TRUE(it_00 == it_same);
    ASSERT_FALSE(it_00 == it_10);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Comparison_NotEqual)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{0,0},{2,2}};

    auto it_00 = input.beginSub(rect);
    auto it_same = input.beginSub(rect);
    auto it_10 = input.beginSub(rect) + 1;

    ASSERT_TRUE(it_00 != it_10);
    ASSERT_FALSE(it_00 != it_same);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Comparison_Less)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{0,0},{2,2}};

    auto it_00 = input.beginSub(rect);
    auto it_10 = input.beginSub(rect) + 1;

    ASSERT_TRUE(it_00 < it_10);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Comparison_LessOrEqual)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{0,0},{2,2}};

    auto it_00 = input.beginSub(rect);
    auto it_same = input.beginSub(rect);

    ASSERT_TRUE(it_00 <= it_same);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Comparison_Greater)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{0,0},{2,2}};

    auto it_00 = input.beginSub(rect);
    auto it_10 = input.beginSub(rect) + 1;

    ASSERT_TRUE(it_10 > it_00);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Comparison_GreaterOrEqual)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{0,0},{2,2}};

    auto it_00 = input.beginSub(rect);
    auto it_same = input.beginSub(rect);

    ASSERT_TRUE(it_00 >= it_same);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_SubIterator, Reverse)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{0,0},{3,0}};

    auto it_00 = input.rendSub(rect) - 1;
    auto it_10 = input.rendSub(rect) - 2;
    auto it_20 = input.rendSub(rect) - 3;
    auto it_30 = input.rendSub(rect) - 4;

    ASSERT_EQ(*it_00, 11);
    ASSERT_EQ(*it_10, 21);
    ASSERT_EQ(*it_20, 31);
    ASSERT_EQ(*it_30, 41);
}
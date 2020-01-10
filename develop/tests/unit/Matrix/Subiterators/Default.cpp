

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrices/Matrix.hpp>


using namespace std;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat44 = Matrix<4,4,int>;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_Subiterators, Plus)
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

TEST(Matrix_Subiterators, Minus)
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

TEST(Matrix_Subiterators, PreIncrement)
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

TEST(Matrix_Subiterators, PostIncrement)
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

TEST(Matrix_Subiterators, PreDecrement)
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

TEST(Matrix_Subiterators, PostDecrement)
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

TEST(Matrix_Subiterators, RowsColumns_FirstComponent)
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

TEST(Matrix_Subiterators, RowsColumns_MidComponent)
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

TEST(Matrix_Subiterators, RowsColumns_LastComponent)
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

TEST(Matrix_Subiterators, Difference)
{
    Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto a      {input.beginSub(rect)};
    auto b      {input.beginSub(rect) + 3};
    auto diff   {a - b};

    ASSERT_EQ(diff, 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Subiterators, Reverse)
{
Mat44 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44
    };

    Mat44::SubRect rect {{1,1},{2,2}};

    auto it_00 = input.rendSub(rect) + 0;
    auto it_10 = input.rendSub(rect) + 1;
    auto it_20 = input.rendSub(rect) + 2;
//    auto it_30 = input.r(rect) + 3;

//    ASSERT_EQ(*it_00, 11);
//    ASSERT_EQ(*it_10, 21);
//    ASSERT_EQ(*it_20, 31);
//    ASSERT_EQ(*it_30, 41);
//
//    ASSERT_EQ(*it_00, 1);
//    ASSERT_EQ(*it_01, 4);
//    ASSERT_EQ(*it_10, 2);
//    ASSERT_EQ(*it_11, 5);
}
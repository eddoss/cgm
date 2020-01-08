

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrices/Matrix.hpp>


using namespace std;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;

TEST(Matrix_RowSubiterators, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it_02 = input.beginRow(0) + 2;
    auto it_12 = input.beginRow(1) + 2;
    auto it_22 = input.beginRow(2) + 2;

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*it_12, 6);
    ASSERT_EQ(*it_22, 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowSubiterators, Minus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    auto it_01 = input.endRow(0) - 1;
    auto it_10 = input.endRow(1) - 2;
    auto it_20 = input.endRow(2) - 2;

    ASSERT_EQ(*it_01, 2);
    ASSERT_EQ(*it_10, 4);
    ASSERT_EQ(*it_20, 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowSubiterators, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRow(1);

    ASSERT_EQ(*it, 4);
    ASSERT_EQ(*(++it), 5);
    ASSERT_EQ(*(++it), 6);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowSubiterators, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginRow(0);

    ASSERT_EQ(*(it++), 1);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowSubiterators, PreDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    auto it = input.endRow(2);

    ASSERT_EQ(*(--it), 8);
    ASSERT_EQ(*(--it), 7);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowSubiterators, PostDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    ASSERT_EQ((input.endRow(1))--, input.endRow(1));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowSubiterators, Difference)
{
    Mat34 input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto a = input.beginRow(0) + 0;   // (0,0)
    auto b = input.beginRow(0) + 2;   // (0,2)
    ASSERT_EQ(b - a, 2);

    a = input.beginRow(0) + 0;   // (0,0)
    b = input.beginRow(1) + 3;   // (1,3)
    ASSERT_EQ(b - a, 7);

    a = input.beginRow(0) + 1;   // (0,1)
    b = input.beginRow(2) + 3;   // (2,3)
    ASSERT_EQ(b - a, 10);
}


/* --------------------------------------------------------------------------------------- */

TEST(Matrix_RowSubiterators, Reverse)
{
    Mat34 input
    {
        1, 2, 3, 6,
        4, 5, 6, 8,
        7, 8, 9, 5
    };

    auto it_00 = input.rbeginRow(1) + 3;
    auto it_01 = input.rbeginRow(1) + 2;
    auto it_02 = input.rbeginRow(1) + 1;
    auto it_03 = input.rbeginRow(1);

    ASSERT_EQ(*it_00, 4);
    ASSERT_EQ(*it_01, 5);
    ASSERT_EQ(*it_02, 6);
    ASSERT_EQ(*it_03, 8);
}
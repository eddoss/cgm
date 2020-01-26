

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Matrices/Matrix.hpp>


using namespace std;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;

TEST(Matrix_Direct, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Mat33::size_type column = 2;
    auto it_02 = input.beginColumn(column);
    auto it_12 = input.beginColumn(column) + 1;
    auto it_22 = input.beginColumn(column) + 2;

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*it_12, 6);
    ASSERT_EQ(*it_22, 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Minus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_22 = input.endColumn(column) - 1;
    auto it_12 = input.endColumn(column) - 2;
    auto it_02 = input.endColumn(column) - 3;

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*it_12, 6);
    ASSERT_EQ(*it_22, 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.beginColumn(column);

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*(++it_02), 6);
    ASSERT_EQ(*(++it_02), 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.beginColumn(column);

    ASSERT_EQ(*(it_02++), 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PreDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Mat33::size_type column = 2;
    auto it_22 = input.endColumn(column);

    ASSERT_EQ(*(--it_22), 9);
    ASSERT_EQ(*(--it_22), 6);
    ASSERT_EQ(*(--it_22), 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, PostDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;

    ASSERT_EQ((input.beginColumn(column))--, input.beginColumn(column));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Difference)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it_01  {input.beginColumn(0)};
    auto it_11  {input.beginColumn(1)};
    auto diff   {it_11 - it_01};

    ASSERT_EQ(diff, (Matrix<3,3,int>::rows));
}


/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterator, Reverse)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    auto it_00 = input.rbeginColumn(0) + 2;
    auto it_10 = input.rbeginColumn(0) + 1;
    auto it_20 = input.rbeginColumn(0);

    ASSERT_EQ(*it_00, 1);
    ASSERT_EQ(*it_10, 4);
    ASSERT_EQ(*it_20, 7);
}
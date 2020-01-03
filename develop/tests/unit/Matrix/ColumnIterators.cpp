

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix.hpp>


using namespace std;
using Mat = Matrix<2,2>;

TEST(Matrix_ColumnIterators, Plus)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.column_begin(column);
    auto it_12 = input.column_begin(column) + 1;
    auto it_22 = input.column_begin(column) + 2;

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*it_12, 6);
    ASSERT_EQ(*it_22, 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterators, Minus)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_22 = input.column_end(column) - 1;
    auto it_12 = input.column_end(column) - 2;
    auto it_02 = input.column_end(column) - 3;

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*it_12, 6);
    ASSERT_EQ(*it_22, 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterators, PreIncrement)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.column_begin(column);

    ASSERT_EQ(*it_02, 3);
    ASSERT_EQ(*(++it_02), 6);
    ASSERT_EQ(*(++it_02), 9);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterators, PostIncrement)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_02 = input.column_begin(column);

    ASSERT_EQ(*(it_02++), 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterators, PreDecrement)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;
    auto it_22 = input.column_end(column);

    ASSERT_EQ(*(--it_22), 9);
    ASSERT_EQ(*(--it_22), 6);
    ASSERT_EQ(*(--it_22), 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterators, PostDecrement)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<3,3,int>::size_type column = 2;

    ASSERT_EQ((input.column_begin(column))--, input.column_begin(column));
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ColumnIterators, Difference)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it_01  {input.column_begin(0)};
    auto it_11  {input.column_begin(1)};
    auto diff   {it_11 - it_01};

    ASSERT_EQ(diff, (Matrix<3,3,int>::rows));
}
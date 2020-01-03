

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix.hpp>


using namespace std;
using Mat = Matrix<2,2>;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_Iterators, Plus)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it_01 = input.begin() + Matrix<3,3,int>::rows;
    auto it_11 = input.begin() + Matrix<3,3,int>::rows + 1;
    auto it_21 = input.begin() + Matrix<3,3,int>::rows + 2;

    ASSERT_EQ(*it_01, 2);
    ASSERT_EQ(*it_11, 5);
    ASSERT_EQ(*it_21, 8);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Minus)
{
    Matrix<3,3,int> input
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
    Matrix<3,3,int> input
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
    Matrix<3,3,int> input
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
    Matrix<3,3,int> input
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
    Matrix<3,3,int> input
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
    Matrix<3,3,int> input
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
    Matrix<3,3,int> input
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
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    auto it {input.begin() + Matrix<3,3,int>::size-1};
    ASSERT_EQ(it.row(), 2);
    ASSERT_EQ(it.column(), 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Iterators, Difference)
{
    Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto a      {input.begin()};
    auto b      {input.begin() + 3};
    auto diff   {a - b};

    ASSERT_EQ(diff, 3);
}
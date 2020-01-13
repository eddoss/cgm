

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Matrices/Matrix.hpp>
#include <Math3D/Core/Structs/Matrices/Operators.hpp>


using namespace std;
using Mat = Matrix<2,2>;

TEST(Matrix_ComparisonWithOther, Equal_PositiveTest)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat other
    {
        1,2,
        3,4
    };

    ASSERT_TRUE(input == other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, Equal_NegativeTest)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat other
    {
        1,1,
        3,4
    };

    ASSERT_FALSE(input == other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, NotEqual_PositiveTest)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat other
    {
        1,1,
        3,4
    };

    ASSERT_TRUE(input != other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, NotEqual_NegativeTest)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat other
    {
        1,2,
        3,4
    };

    ASSERT_FALSE(input != other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, Less_PositiveTest)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat other
    {
        2,3,
        4,5
    };

    ASSERT_TRUE(input < other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, Less_NegativeTest)
{
    Mat input
    {
        2,2,
        3,4
    };
    Mat other
    {
        2,3,
        4,5
    };

    ASSERT_FALSE(other < input);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, LessOrEqual_PositiveTest)
{
    Mat input
    {
        2,2,
        3,4
    };
    Mat other
    {
        2,3,
        4,5
    };

    ASSERT_TRUE(input <= other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, LessOrEqual_NegativeTest)
{
    Mat input
    {
        4,2,
        3,4
    };
    Mat other
    {
        2,3,
        4,5
    };

    ASSERT_FALSE(other <= input);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, Greater_PositiveTest)
{
    Mat input
    {
        2,3,
        4,5
    };
    Mat other
    {
        1,2,
        3,4
    };

    ASSERT_TRUE(input > other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, Greater_NegativeTest)
{
    Mat input
    {
        1,3,
        4,5
    };
    Mat other
    {
        1,2,
        3,4
    };

    ASSERT_FALSE(other > input);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, GreaterOrEqual_PositiveTest)
{
    Mat input
    {
        1,3,
        4,5
    };
    Mat other
    {
        1,2,
        3,4
    };

    ASSERT_TRUE(input >= other);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithOther, GreaterOrEqual_NegativeTest)
{
    Mat input
    {
        0,3,
        4,5
    };
    Mat other
    {
        1,2,
        3,4
    };

    ASSERT_FALSE(other >= input);
}
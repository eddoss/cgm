

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix.hpp>


using namespace std;
using Mat = Matrix<2,2>;

TEST(Matrix, Assignment_Scalar)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat::value_type scalar = 4;
    input = scalar;

    for (const auto& val : input) ASSERT_EQ(val, scalar);
}

TEST(Matrix, Assignment_Other)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat other
    {
        5,6,
        7,8
    };
    input = other;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], other[i]);
}

TEST(Matrix, UnaryMinus)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        -1,-2,
        -3,-4
    };
    input = -input;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, PreIncrement)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        2,3,
        4,5
    };
    ++input;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, PostIncrement)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        2,3,
        4,5
    };
    input++;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, PreDecrement)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        0,1,
        2,3
    };
    --input;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, PostDecrement)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        0,1,
        2,3
    };
    input--;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, InplaceMinus_Scalar)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        -1,0,
        1,2
    };
    input -= 2;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, InplaceMinus_Other)
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
    Mat expec
    {
        0,0,
        0,0
    };
    input -= other;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, InplacePlus_Scalar)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        3,4,
        5,6
    };
    input += 2;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, InplacePlus_Other)
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
    Mat expec
    {
        3,5,
        7,9
    };
    input += other;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, InplacePerComponentMultiplication_Scalar)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        2,4,
        6,8
    };
    input *= 2;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, InplacePerComponentDivision_Scalar)
{
    Mat input
    {
        2,4,
        6,8
    };
    Mat expec
    {
        1,2,
        3,4
    };
    input /= 2;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Matrix, Compares_Equal_Other_PositiveTest)
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

TEST(Matrix, Compares_Equal_Other_NegativeTest)
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

TEST(Matrix, Compares_NotEqual_Other_PositiveTest)
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

TEST(Matrix, Compares_NotEqual_Other_NegativeTest)
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

TEST(Matrix, Compares_Greater_Other_PositiveTest)
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

TEST(Matrix, Compares_Greater_Other_NegativeTest)
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

TEST(Matrix, Compares_GreaterOrEqual_Other_PositiveTest)
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

TEST(Matrix, Compares_GreaterOrEqual_Other_NegativeTest)
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

TEST(Matrix, Compares_Less_Other_PositiveTest)
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

TEST(Matrix, Compares_Less_Other_NegativeTest)
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

TEST(Matrix, Compares_LessOrEqual_Other_PositiveTest)
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

TEST(Matrix, Compares_LessOrEqual_Other_NegativeTest)
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
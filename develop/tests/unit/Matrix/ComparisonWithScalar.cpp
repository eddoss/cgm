

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Matrices/Matrix.hpp>
#include <Math3D/Core/Structs/Matrices/Operators.hpp>


using namespace std;
using Mat = Matrix<2,2>;

TEST(Matrix_ComparisonWithScalar, Equal_PositiveTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar
    };

    ASSERT_TRUE(input == scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, Equal_NegativeTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar + 2
    };

    ASSERT_FALSE(input == scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, NotEqual_PositiveTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar + 1
    };

    ASSERT_TRUE(input != scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, NotEqual_NegativeTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar
    };

    ASSERT_FALSE(input != scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, Less_PositiveTest)
{
Mat::value_type scalar {5};
    Mat input
    {
        scalar-1, scalar-1,
        scalar-1, scalar-1
    };

    ASSERT_TRUE(input < scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, Less_NegativeTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar
    };

    ASSERT_FALSE(input < scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, LessOrEqual_PositiveTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar-1
    };

    ASSERT_TRUE(input <= scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, LessOrEqual_NegativeTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar+1
    };

    ASSERT_FALSE(input <= scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, Greater_PositiveTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar+1, scalar+1,
        scalar+1, scalar+1
    };

    ASSERT_TRUE(input > scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, Greater_NegativeTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar
    };

    ASSERT_FALSE(input > scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, GreaterOrEqual_PositiveTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, scalar+1
    };

    ASSERT_TRUE(input >= scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_ComparisonWithScalar, GreaterOrEqual_NegativeTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, 0
    };

    ASSERT_FALSE(input >= scalar);
}
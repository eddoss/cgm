

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrix.hpp>


using namespace std;
using Mat = Matrix<2,2>;

/* ####################################################################################### */
/* Assignment operator */
/* ####################################################################################### */

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

/* --------------------------------------------------------------------------------------- */

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

/* ####################################################################################### */
/* Unary minus */
/* ####################################################################################### */

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

/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

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

/* --------------------------------------------------------------------------------------- */

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

/* --------------------------------------------------------------------------------------- */

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

/* --------------------------------------------------------------------------------------- */

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

/* ####################################################################################### */
/* Arithmetic operators: minus */
/* ####################################################################################### */

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

/* --------------------------------------------------------------------------------------- */

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

/* ####################################################################################### */
/* Arithmetic operators: binary plus */
/* ####################################################################################### */

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

/* --------------------------------------------------------------------------------------- */

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

/* ####################################################################################### */
/* Arithmetic operators: multiplication */
/* ####################################################################################### */

TEST(Matrix, InplacePerComponentMultiplication_On_Scalar)
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

/* --------------------------------------------------------------------------------------- */

TEST(Matrix, OutplacePerComponentMultiplication_On_Scalar)
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
    input = input * 2;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Arithmetic operators: division */
/* ####################################################################################### */

TEST(Matrix, InplacePerComponentDivision_By_Scalar)
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

/* --------------------------------------------------------------------------------------- */

TEST(Matrix, OutplacePerComponentDivision_By_Scalar)
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
    input = input / 2;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Comparison with scalar */
/* ####################################################################################### */

TEST(Matrix, ComparesWithScalar_Equal_PositiveTest)
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

TEST(Matrix, ComparesWithScalar_Equal_NegativeTest)
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

TEST(Matrix, ComparesWithScalar_NotEqual_PositiveTest)
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

TEST(Matrix, ComparesWithScalar_NotEqual_NegativeTest)
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

TEST(Matrix, ComparesWithScalar_Less_PositiveTest)
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

TEST(Matrix, ComparesWithScalar_Less_NegativeTest)
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

TEST(Matrix, ComparesWithScalar_LessOrEqual_PositiveTest)
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

TEST(Matrix, ComparesWithScalar_LessOrEqual_NegativeTest)
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

TEST(Matrix, ComparesWithScalar_Greater_PositiveTest)
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

TEST(Matrix, ComparesWithScalar_Greater_NegativeTest)
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

TEST(Matrix, ComparesWithScalar_GreaterOrEqual_PositiveTest)
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

TEST(Matrix, ComparesWithScalar_GreaterOrEqual_NegativeTest)
{
    Mat::value_type scalar {5};
    Mat input
    {
        scalar, scalar,
        scalar, 0
    };

    ASSERT_FALSE(input >= scalar);
}

/* ####################################################################################### */
/* Comparison with other */
/* ####################################################################################### */

TEST(Matrix, ComparesWithOther_Equal_PositiveTest)
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

TEST(Matrix, ComparesWithOther_Equal_NegativeTest)
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

TEST(Matrix, ComparesWithOther_NotEqual_PositiveTest)
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

TEST(Matrix, ComparesWithOther_NotEqual_NegativeTest)
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

TEST(Matrix, ComparesWithOther_Less_PositiveTest)
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

TEST(Matrix, ComparesWithOther_Less_NegativeTest)
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

TEST(Matrix, ComparesWithOther_LessOrEqual_PositiveTest)
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

TEST(Matrix, ComparesWithOther_LessOrEqual_NegativeTest)
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

TEST(Matrix, ComparesWithOther_Greater_PositiveTest)
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

TEST(Matrix, ComparesWithOther_Greater_NegativeTest)
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

TEST(Matrix, ComparesWithOther_GreaterOrEqual_PositiveTest)
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

TEST(Matrix, ComparesWithOther_GreaterOrEqual_NegativeTest)
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
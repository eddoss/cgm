

#ifndef MATH3D_VECTOR_TEST_HPP
#define MATH3D_VECTOR_TEST_HPP


#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Vector.hpp>


using namespace std;
using Vec = Vector<3>;

TEST(Vector, Assignment_Scalar)
{
    Vec::value_type scalar = 4;
    Vec input {1,2,3};
    input = scalar;

    for (const auto& val : input) ASSERT_EQ(val, scalar);
}

TEST(Vector, Assignment_Other)
{
    Vec input {1,2,3};
    Vec other {4,5,6};
    input = other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], other[i]);
}

TEST(Vector, UnaryMinus)
{
    Vec input {1,2,3};
    Vec expec {-1,-2,-3};
    input = -input;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, PreIncrement)
{
    Vec input {1,2,3};
    Vec expec {2,3,4};
    ++input;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, PostIncrement)
{
    Vec input {1,2,3};
    Vec expec {2,3,4};
    input++;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, PreDecrement)
{
    Vec input {1,2,3};
    Vec expec {0,1,2};
    --input;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, PostDecrement)
{
    Vec input {1,2,3};
    Vec expec {0,1,2};
    input--;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, InplaceMinus_Scalar)
{
    Vec input {1,2,3};
    Vec expec {-1,0,1};
    input -= 2;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, InplaceMinus_Other)
{
    Vec input {1,2,3};
    Vec other {2,3,4};
    Vec expec {-1,-1,-1};
    input -= other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, InplacePlus_Scalar)
{
    Vec input {1,2,3};
    Vec expec {3,4,5};
    input += 2;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, InplacePlus_Other)
{
    Vec input {1,2,3};
    Vec other {2,3,4};
    Vec expec {3,5,7};
    input += other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, InplacePerComponentMultiplication_Scalar)
{
    Vec input {1,2,3};
    Vec expec {2,4,6};
    input *= 2;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, InplacePerComponentMultiplication_Other)
{
    Vec input {1,2,3};
    Vec other {2,3,4};
    Vec expec {2,6,12};
    input *= other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, InplaceDivision_Scalar)
{
    Vec input {4,6,10};
    Vec expec {2,3,5};
    input /= 2;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, InplaceDivision_Other)
{
    Vec input {10,20,30};
    Vec other {2,10,6};
    Vec expec {5,2,5};
    input /= other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

TEST(Vector, Compares_Equal_Other_PositiveTest)
{
    Vec input {1,2,3};
    Vec other {1,2,3};

    ASSERT_TRUE(input == other);
}

TEST(Vector, Compares_Equal_Other_NegativeTest)
{
    Vec input {1,2,3};
    Vec other {1,2,4};

    ASSERT_FALSE(input == other);
}

TEST(Vector, Compares_NotEqual_Other_PositiveTest)
{
    Vec input {1,2,3};
    Vec other {1,2,4};

    ASSERT_TRUE(input != other);
}

TEST(Vector, Compares_NotEqual_Other_NegativeTest)
{
    Vec input {1,2,3};
    Vec other {1,2,3};

    ASSERT_FALSE(input != other);
}

TEST(Vector, Compares_Greater_Other_PositiveTest)
{
    Vec input {2,3,4};
    Vec other {1,2,3};

    ASSERT_TRUE(input > other);
}

TEST(Vector, Compares_Greater_Other_NegativeTest)
{
    Vec input {2,3,4};
    Vec other {1,2,3};

    ASSERT_FALSE(other > input);
}

TEST(Vector, Compares_GreaterOrEqual_Other_PositiveTest)
{
    Vec input {2,3,4};
    Vec other {1,3,4};

    ASSERT_TRUE(input >= other);
}

TEST(Vector, Compares_GreaterOrEqual_Other_NegativeTest)
{
    Vec input {2,3,4};
    Vec other {1,3,4};

    ASSERT_FALSE(other >= input);
}

TEST(Vector, Compares_Less_Other_PositiveTest)
{
    Vec input {1,2,3};
    Vec other {2,3,4};

    ASSERT_TRUE(input < other);
}

TEST(Vector, Compares_Less_Other_NegativeTest)
{
    Vec input {1,2,3};
    Vec other {1,3,4};

    ASSERT_FALSE(other < input);
}

TEST(Vector, Compares_LessOrEqual_Other_PositiveTest)
{
    Vec input {1,2,3};
    Vec other {1,2,4};

    ASSERT_TRUE(input <= other);
}

TEST(Vector, Compares_LessOrEqual_Other_NegativeTest)
{
    Vec input {1,2,3};
    Vec other {1,2,4};

    ASSERT_FALSE(other <= input);
}

TEST(Vector, Compares_Equal_Scalar_PositiveTest)
{
    Vec::value_type scalar = 3;
    Vec input(scalar);

    ASSERT_TRUE(input == scalar);
}

TEST(Vector, Compares_Equal_Scalar_NegativeTest)
{
    Vec::value_type scalar = 3;
    Vec input(scalar);

    ASSERT_FALSE(input == scalar-1);
}

TEST(Vector, Compares_NotEqual_Scalar_PositiveTest)
{
    Vec::value_type scalar = 3;
    Vec input(scalar*2);

    ASSERT_TRUE(input != scalar);
}

TEST(Vector, Compares_NotEqual_Scalar_NegativeTest)
{
    Vec::value_type scalar = 3;
    Vec input(scalar);

    ASSERT_FALSE(input != scalar);
}

#endif // MATH3D_VECTOR_TEST_HPP

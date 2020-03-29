

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Core/Quaternion/Operators.hpp>


using namespace MATH3D_NAMESPACE;

using namespace std;

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

TEST(Quaternion_Operators, UnaryMinus)
{
    Quaternion<int> qat { 1, 2, 3, 4 };
    Quaternion<int> exp {-1,-2,-3,-4 };
    ASSERT_TRUE(-qat == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, OutplaceMinus)
{
    Quaternion<int> a { 1, 2, 3, 4 };
    Quaternion<int> b { 1, 1, 2, 2 };
    Quaternion<int> e { 0, 1, 1, 2 };

    a = a - b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceMinus)
{
    Quaternion<int> a { 1, 2, 3, 4 };
    Quaternion<int> b { 1, 1, 2, 2 };
    Quaternion<int> e { 0, 1, 1, 2 };

    a -= b;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

TEST(Quaternion_Operators, OutplacePlus)
{
    Quaternion<int> a { 1, 2, 3, 4 };
    Quaternion<int> b { 1, 1, 2, 2 };
    Quaternion<int> e { 2, 3, 5, 6 };

    a = a + b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplacePlus)
{
    Quaternion<int> a { 1, 2, 3, 4 };
    Quaternion<int> b { 1, 1, 2, 2 };
    Quaternion<int> e { 2, 3, 5, 6 };

    a += b;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

TEST(Quaternion_Operators, OutplaceScalarMultiplication)
{
    Quaternion<int> a { 1, 2, 3, 4 };
    Quaternion<int> e { 2, 4, 6, 8 };

    a = a * 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, OutplaceOtherMultiplication)
{
    Quaternion<int> a { 2, 3, 1, 5 };
    Quaternion<int> b { 7, 9, 1, 3 };
    Quaternion<int> e { -29,37,45,35 };

    a = a * b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceScalarMultiplication)
{
    Quaternion<int> a { 1, 2, 3, 4 };
    Quaternion<int> e { 2, 4, 6, 8 };

    a *= 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceOtherMultiplication)
{
    Quaternion<int> a { 2, 3, 1, 5 };
    Quaternion<int> b { 7, 9, 1, 3 };
    Quaternion<int> e { -29,37,45,35 };

    a *= b;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

TEST(Quaternion_Operators, OutplaceScalarDivision)
{
    Quaternion<int> a { 2, 4, 6, 8 };
    Quaternion<int> e { 1, 2, 3, 4 };

    a = a / 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceScalarDivision)
{
    Quaternion<int> a { 2, 4, 6, 8 };
    Quaternion<int> e { 1, 2, 3, 4 };

    a /= 2;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

TEST(Quaternion_Operators, ComparisonEqual)
{
    Quaternion<int> a { 2, 4, 6, 8 };
    Quaternion<int> b { 2, 4, 6, 8 };

    ASSERT_TRUE(a == b);

    Quaternion<int> c { 2, 4, 6, 8 };
    Quaternion<int> d { 1, 4, 6, 8 };

    ASSERT_FALSE(c == d);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, ComparisonNotEqual)
{
    Quaternion<int> a { 2, 4, 6, 8 };
    Quaternion<int> b { 1, 4, 6, 8 };

    ASSERT_TRUE(a != b);

    Quaternion<int> c { 2, 4, 6, 8 };
    Quaternion<int> d { 2, 4, 6, 8 };

    ASSERT_FALSE(c != d);
}
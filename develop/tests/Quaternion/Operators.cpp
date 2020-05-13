

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Core/Operators/Quaternion.hpp>


using namespace MATH3D_NAMESPACE;

using namespace std;

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

TEST(Quaternion_Operators, UnaryMinus)
{
    Quaternion<double> qat { 1, 2, 3, 4 };
    Quaternion<double> exp {-1,-2,-3,-4 };
    ASSERT_TRUE(-qat == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, OutplaceMinus)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> b { 1, 1, 2, 2 };
    Quaternion<double> e { 0, 1, 1, 2 };

    a = a - b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceMinus)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> b { 1, 1, 2, 2 };
    Quaternion<double> e { 0, 1, 1, 2 };

    a -= b;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

TEST(Quaternion_Operators, OutplacePlus)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> b { 1, 1, 2, 2 };
    Quaternion<double> e { 2, 3, 5, 6 };

    a = a + b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplacePlus)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> b { 1, 1, 2, 2 };
    Quaternion<double> e { 2, 3, 5, 6 };

    a += b;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

TEST(Quaternion_Operators, OutplaceScalarMultiplication)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> e { 2, 4, 6, 8 };

    a = a * 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, OutplaceOtherMultiplication)
{
    Quaternion<double> a { 2, 3, 1, 5 };
    Quaternion<double> b { 7, 9, 1, 3 };
    Quaternion<double> e { -29,37,45,35 };

    a = a * b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceScalarMultiplication)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> e { 2, 4, 6, 8 };

    a *= 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceOtherMultiplication)
{
    Quaternion<double> a { 2, 3, 1, 5 };
    Quaternion<double> b { 7, 9, 1, 3 };
    Quaternion<double> e { -29,37,45,35 };

    a *= b;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

TEST(Quaternion_Operators, OutplaceScalarDivision)
{
    Quaternion<double> a { 2, 4, 6, 8 };
    Quaternion<double> e { 1, 2, 3, 4 };

    a = a / 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceScalarDivision)
{
    Quaternion<double> a { 2, 4, 6, 8 };
    Quaternion<double> e { 1, 2, 3, 4 };

    a /= 2;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

TEST(Quaternion_Operators, ComparisonEqual)
{
    Quaternion<double> a { 2, 4, 6, 8 };
    Quaternion<double> b { 2, 4, 6, 8 };

    ASSERT_TRUE(a == b);

    Quaternion<double> c { 2, 4, 6, 8 };
    Quaternion<double> d { 1, 4, 6, 8 };

    ASSERT_FALSE(c == d);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, ComparisonNotEqual)
{
    Quaternion<double> a { 2, 4, 6, 8 };
    Quaternion<double> b { 1, 4, 6, 8 };

    ASSERT_TRUE(a != b);

    Quaternion<double> c { 2, 4, 6, 8 };
    Quaternion<double> d { 2, 4, 6, 8 };

    ASSERT_FALSE(c != d);
}
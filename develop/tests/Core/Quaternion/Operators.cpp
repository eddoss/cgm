

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Quaternion.hpp>
#include <CGM/Modules/Core/Operators/Quaternion.hpp>


using namespace CGM;

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
    Quaternion<double> a { 3, 1, 5, 2 };
    Quaternion<double> b { 9, 1, 3, 7 };

    Quaternion<double> result = a * b;
#ifdef CGM_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    Quaternion<double> expect {41, -27, 47, -29};
#else
    Quaternion<double> expect {37, 45, 35, -29};
#endif

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Quaternion_Operators, InplaceScalarMultiplication)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> e { 2, 4, 6, 8 };

    a *= 2;

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
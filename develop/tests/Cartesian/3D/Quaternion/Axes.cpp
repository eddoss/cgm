

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/detail/Cartesian/3D/Operators/Quaternion.hpp>


using namespace CGM;

using namespace std;

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

TEST(Cartesian_3D_Operators_Quaternion, UnaryMinus)
{
    Quaternion<double> qat { 1, 2, 3, 4 };
    Quaternion<double> exp {-1,-2,-3,-4 };
    ASSERT_TRUE(-qat == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, OutplaceMinus)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> b { 1, 1, 2, 2 };
    Quaternion<double> e { 0, 1, 1, 2 };

    a = a - b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, InplaceMinus)
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

TEST(Cartesian_3D_Operators_Quaternion, OutplacePlus)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> b { 1, 1, 2, 2 };
    Quaternion<double> e { 2, 3, 5, 6 };

    a = a + b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, InplacePlus)
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

TEST(Cartesian_3D_Operators_Quaternion, OutplaceScalarMultiplication)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> e { 2, 4, 6, 8 };

    a = a * 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, OutplaceOtherMultiplication)
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

TEST(Cartesian_3D_Operators_Quaternion, InplaceScalarMultiplication)
{
    Quaternion<double> a { 1, 2, 3, 4 };
    Quaternion<double> e { 2, 4, 6, 8 };

    a *= 2;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

TEST(Cartesian_3D_Operators_Quaternion, OutplaceScalarDivision)
{
    Quaternion<double> a { 2, 4, 6, 8 };
    Quaternion<double> e { 1, 2, 3, 4 };

    a = a / 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, InplaceScalarDivision)
{
    Quaternion<double> a { 2, 4, 6, 8 };
    Quaternion<double> e { 1, 2, 3, 4 };

    a /= 2;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

TEST(Cartesian_3D_Operators_Quaternion, ComparisonEqual)
{
    Quaternion<double> a { 2, 4, 6, 8 };
    Quaternion<double> b { 2, 4, 6, 8 };

    ASSERT_TRUE(a == b);

    Quaternion<double> c { 2, 4, 6, 8 };
    Quaternion<double> d { 1, 4, 6, 8 };

    ASSERT_FALSE(c == d);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, ComparisonNotEqual)
{
    Quaternion<double> a { 2, 4, 6, 8 };
    Quaternion<double> b { 1, 4, 6, 8 };

    ASSERT_TRUE(a != b);

    Quaternion<double> c { 2, 4, 6, 8 };
    Quaternion<double> d { 2, 4, 6, 8 };

    ASSERT_FALSE(c != d);
}
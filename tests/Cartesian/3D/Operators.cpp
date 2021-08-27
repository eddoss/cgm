

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Operators/Quaternion.hpp>


using namespace std;

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

TEST(Cartesian_3D_Operators_Quaternion, UnaryMinus)
{
    CGM::Quaternion<double> qat { 1, 2, 3, 4 };
    CGM::Quaternion<double> exp {-1,-2,-3,-4 };
    ASSERT_TRUE(-qat == exp);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, OutplaceMinus)
{
    CGM::Quaternion<double> a { 1, 2, 3, 4 };
    CGM::Quaternion<double> b { 1, 1, 2, 2 };
    CGM::Quaternion<double> e { 0, 1, 1, 2 };

    a = a - b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, InplaceMinus)
{
    CGM::Quaternion<double> a { 1, 2, 3, 4 };
    CGM::Quaternion<double> b { 1, 1, 2, 2 };
    CGM::Quaternion<double> e { 0, 1, 1, 2 };

    a -= b;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

TEST(Cartesian_3D_Operators_Quaternion, OutplacePlus)
{
    CGM::Quaternion<double> a { 1, 2, 3, 4 };
    CGM::Quaternion<double> b { 1, 1, 2, 2 };
    CGM::Quaternion<double> e { 2, 3, 5, 6 };

    a = a + b;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, InplacePlus)
{
    CGM::Quaternion<double> a { 1, 2, 3, 4 };
    CGM::Quaternion<double> b { 1, 1, 2, 2 };
    CGM::Quaternion<double> e { 2, 3, 5, 6 };

    a += b;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

TEST(Cartesian_3D_Operators_Quaternion, OutplaceScalarMultiplication)
{
    CGM::Quaternion<double> a { 1, 2, 3, 4 };
    CGM::Quaternion<double> e { 2, 4, 6, 8 };

    a = a * 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, OutplaceOtherMultiplication)
{
    CGM::Quaternion<double> a { 3, 1, 5, 2 };
    CGM::Quaternion<double> b { 9, 1, 3, 7 };

    CGM::Quaternion<double> result = a * b;
#ifdef CGM_CFG_LHS
    CGM::Quaternion<double> expect {41, -27, 47, -29};
#else
    CGM::Quaternion<double> expect {37, 45, 35, -29};
#endif

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, InplaceScalarMultiplication)
{
    CGM::Quaternion<double> a { 1, 2, 3, 4 };
    CGM::Quaternion<double> e { 2, 4, 6, 8 };

    a *= 2;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

TEST(Cartesian_3D_Operators_Quaternion, OutplaceScalarDivision)
{
    CGM::Quaternion<double> a { 2, 4, 6, 8 };
    CGM::Quaternion<double> e { 1, 2, 3, 4 };

    a = a / 2;

    ASSERT_TRUE(a == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, InplaceScalarDivision)
{
    CGM::Quaternion<double> a { 2, 4, 6, 8 };
    CGM::Quaternion<double> e { 1, 2, 3, 4 };

    a /= 2;

    ASSERT_TRUE(a == e);
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

TEST(Cartesian_3D_Operators_Quaternion, ComparisonEqual)
{
    CGM::Quaternion<double> a { 2, 4, 6, 8 };
    CGM::Quaternion<double> b { 2, 4, 6, 8 };

    ASSERT_TRUE(a == b);

    CGM::Quaternion<double> c { 2, 4, 6, 8 };
    CGM::Quaternion<double> d { 1, 4, 6, 8 };

    ASSERT_FALSE(c == d);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Operators_Quaternion, ComparisonNotEqual)
{
    CGM::Quaternion<double> a { 2, 4, 6, 8 };
    CGM::Quaternion<double> b { 1, 4, 6, 8 };

    ASSERT_TRUE(a != b);

    CGM::Quaternion<double> c { 2, 4, 6, 8 };
    CGM::Quaternion<double> d { 2, 4, 6, 8 };

    ASSERT_FALSE(c != d);
}
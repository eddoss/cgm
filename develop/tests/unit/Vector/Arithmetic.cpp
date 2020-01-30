

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Vector/Vector.hpp>
#include <Math3D/Core/Structs/Vector/Operators.hpp>


using namespace std;
using Vec = Vector<3>;


/* ####################################################################################### */
/* Arithmetic operators: unary minus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, UnaryMinus)
{
    Vec input {1,2,3};
    Vec expec {-1,-2,-3};
    input = -input;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Arithmetic operators: inplace minus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplaceMinus_Scalar)
{
    Vec input {1,2,3};
    Vec expec {-1,0,1};
    input -= Vec::value_type(2);

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplaceMinus_Other)
{
    Vec input {1,2,3};
    Vec other {2,3,4};
    Vec expec {-1,-1,-1};
    input -= other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Arithmetic operators: inplace plus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplacePlus_Scalar)
{
    Vec input {1,2,3};
    Vec expec {3,4,5};
    input += Vec::value_type(2);

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplacePlus_Other)
{
    Vec input {1,2,3};
    Vec other {2,3,4};
    Vec expec {3,5,7};
    input += other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Arithmetic operators: inplace per-component multiplication */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplacePerComponentMultiplication_Scalar)
{
    Vec input {1,2,3};
    Vec expec {2,4,6};
    input *= Vec::value_type(2);

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplacePerComponentMultiplication_Other)
{
    Vec input {1,2,3};
    Vec other {2,3,4};
    Vec expec {2,6,12};
    input *= other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Arithmetic operators: inplace per-component division */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplaceDivision_Scalar)
{
    Vec input {4,6,10};
    Vec expec {2,3,5};
    input /= Vec::value_type(2);

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplaceDivision_Other)
{
    Vec input {10,20,30};
    Vec other {2,10,6};
    Vec expec {5,2,5};
    input /= other;

    for (Vec::size_type i = 0; i < Vec::dimensions; ++i) ASSERT_EQ(input[i], expec[i]);
}
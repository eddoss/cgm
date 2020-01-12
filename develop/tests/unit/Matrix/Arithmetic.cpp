

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Matrices/Matrix.hpp>
#include <Math3D/Core/Structs/Matrices/Operators.hpp>


using namespace std;
using Mat = Matrix<2,2>;

/* ####################################################################################### */
/* Unary minus */
/* ####################################################################################### */

TEST(Matrix_Arithmetic, UnaryMinus)
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
/* Minus */
/* ####################################################################################### */

TEST(Matrix_Arithmetic, InplaceMinus_Scalar)
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
    input -= Mat::value_type(2);

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, InplaceMinus_Other)
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
/* Plus */
/* ####################################################################################### */

TEST(Matrix_Arithmetic, InplacePlus_Scalar)
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
    input += Mat::value_type(2);

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, InplacePlus_Other)
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
/* Multiplication */
/* ####################################################################################### */

TEST(Matrix_Arithmetic, InplacePerComponentMultiplication_On_Scalar)
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
    input *= Mat::value_type(2);

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, OutplacePerComponentMultiplication_On_Scalar)
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
    input = input * Mat::value_type(2);

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Division */
/* ####################################################################################### */

TEST(Matrix_Arithmetic, InplacePerComponentDivision_By_Scalar)
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
    input /= Mat::value_type(2);

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Arithmetic, OutplacePerComponentDivision_By_Scalar)
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
    input = input / Mat::value_type(2);

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}
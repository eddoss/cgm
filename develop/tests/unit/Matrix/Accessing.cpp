

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Matrices/Matrix.hpp>
#include <Math3D/Core/Structs/Matrices/Operators.hpp>


using namespace std;
using Mat22 = Matrix<2,2,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat44 = Matrix<4,4,int>;

/* ####################################################################################### */
/* ByIndex */
/* ####################################################################################### */

TEST(Matrix_Accessing, ByIndexFirst)
{
    Mat32 input
    {
        1,2,
        4,5,
        7,8
    };
    Mat32 expec
    {
       -1,2,
        4,5,
        7,8
    };
    input[0] *= -1;
    ASSERT_EQ(input, expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Accessing, ByIndexMid)
{
    Mat32 input
    {
        1,2,
        4,5,
        7,8
    };
    input[4] *= -1;
    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        Mat32 expec
        {
            1,2,
            4,5,
            -7,8
        };
    #else
        Mat32 expec
        {
            1,2,
            4,-5,
            7,8
        };
    #endif
    ASSERT_EQ(input, expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Accessing, ByIndexLast)
{
    Mat32 input
    {
        1,2,
        4,5,
        7,8
    };
    Mat32 expec
    {
        1,2,
        4,5,
        7,-8
    };
    input[5] *= -1;

    ASSERT_EQ(input, expec);
}

/* ####################################################################################### */
/* By row and column */
/* ####################################################################################### */

TEST(Matrix_Accessing, ByRowColumnFirst)
{
    Mat32 input
    {
        1,2,
        4,5,
        7,8
    };
    Mat32 expec
    {
        -1,2,
        4,5,
        7,8
    };
    input(0,0) *= -1;

    ASSERT_EQ(input, expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Accessing, ByRowColumnMid)
{
    Mat32 input
    {
        1,2,
        4,5,
        7,8
    };
    Mat32 expec
    {
        1,2,
        4,-5,
        7,8
    };
    input(1,1) *= -1;

    ASSERT_EQ(input, expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Accessing, ByRowColumnLast)
{
    Mat32 input
    {
        1,2,
        4,5,
        7,8
    };
    Mat32 expec
    {
        1,2,
        4,5,
        7,-8
    };
    input(2,1) *= -1;

    ASSERT_EQ(input, expec);
}
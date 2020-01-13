

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

TEST(Matrix_MatrixMultiplication, Mat22_x_Mat22)
{
    Mat22 a
    {
        2,3,
        4,5
    };
    Mat22 b
    {
        5,4,
        3,2
    };
    Mat22 e
    {
        19,14,
        35,26
    };

    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _33_x_33)
{
    Mat33 a
    {
        1,2,3,
        4,5,6,
        7,8,9
    };
    Mat33 b
    {
        9,8,7,
        6,5,4,
        3,2,1
    };
    Mat33 e
    {
        30,24,18,
        84,69,54,
        138,114,90
    };
    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _44_x_44)
{
    Mat44 a
    {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10,11,12,
        13,14,15,16
    };
    Mat44 b
    {
        16,15,14,13,
        12,11,10, 9,
         8, 7, 6, 5,
         4, 3, 2, 1
    };
    Mat44 e
    {
        80,70,60,50,
        240,214,188, 162,
        400,358,316,274,
        560,502,444,386
    };
    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _55_x_55)
{
//    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _23_x_32)
{
//    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _24_x_42)
{
//    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _32_x_23)
{
//    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _34_x_43)
{
//    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _42_x_24)
{
//    ASSERT_EQ(a * b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication, _43_x_34)
{
//    ASSERT_EQ(a * b, e);
}
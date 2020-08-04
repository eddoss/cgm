

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Operators/Matrix.hpp>


using namespace CGM;

using namespace std;
using Mat12 = Matrix<1,2,int>;
using Mat13 = Matrix<1,3,int>;
using Mat14 = Matrix<1,4,int>;
using Mat15 = Matrix<1,5,int>;
using Mat21 = Matrix<2,1,int>;
using Mat22 = Matrix<2,2,int>;
using Mat23 = Matrix<2,3,int>;
using Mat24 = Matrix<2,4,int>;
using Mat25 = Matrix<2,5,int>;
using Mat31 = Matrix<3,1,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat35 = Matrix<3,5,int>;
using Mat41 = Matrix<4,1,int>;
using Mat42 = Matrix<4,2,int>;
using Mat43 = Matrix<4,3,int>;
using Mat44 = Matrix<4,4,int>;
using Mat45 = Matrix<4,5,int>;
using Mat51 = Matrix<5,1,int>;
using Mat55 = Matrix<5,5,int>;

TEST(Matrix_MatrixMultiplication_1NxN1, Size_2)
{
    Mat12 a
    {
        3,6
    };

    Mat21 b
    {
        2,
        4
    };

    ASSERT_TRUE((a * b) == 30);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication_1NxN1, Size_3)
{
    Mat13 a
    {
        3,6,7
    };

    Mat31 b
    {
        2,
        4,
        5
    };

    ASSERT_TRUE((a * b) == 65);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication_1NxN1, Size_4)
{
    Mat14 a
    {
        3,6,7,8
    };

    Mat41 b
    {
        2,
        4,
        5,
        6
    };

    ASSERT_TRUE((a * b) == 113);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication_1NxN1, Size_5)
{
    Mat15 a
    {
        3,6,7,8,3
    };
    Mat51 b
    {
        2,
        4,
        5,
        6,
        9
    };

    ASSERT_EQ((a * b), 140);
}
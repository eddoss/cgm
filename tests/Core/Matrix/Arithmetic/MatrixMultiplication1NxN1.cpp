

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Core/Operators/Matrix.hpp>


using namespace std;

TEST(Matrix_MatrixMultiplication_1NxN1, Size_2)
{
    CGM::Matrix<1,2,int> a
    {
        3,6
    };

    CGM::Matrix<2,1,int> b
    {
        2,
        4
    };

    ASSERT_TRUE((a * b) == 30);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_MatrixMultiplication_1NxN1, Size_3)
{
    CGM::Matrix<1,3,int> a
    {
        3,6,7
    };

    CGM::Matrix<3,1,int> b
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
    CGM::Matrix<1,4,int> a
    {
        3,6,7,8
    };

    CGM::Matrix<4,1,int> b
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
    CGM::Matrix<1,5,int> a
    {
        3,6,7,8,3
    };
    CGM::Matrix<5,1,int> b
    {
        2,
        4,
        5,
        6,
        9
    };

    ASSERT_EQ((a * b), 140);
}


#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Matrices/Matrix.hpp>


using namespace std;
using Mat = Matrix<2,2>;

/* ####################################################################################### */
/* Increment */
/* ####################################################################################### */

TEST(Matrix, PreIncrement)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        2,3,
        4,5
    };
    ++input;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix, PostIncrement)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        2,3,
        4,5
    };
    input++;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* ####################################################################################### */
/* Decrement */
/* ####################################################################################### */

TEST(Matrix, PreDecrement)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        0,1,
        2,3
    };
    --input;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix, PostDecrement)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat expec
    {
        0,1,
        2,3
    };
    input--;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], expec[i]);
}

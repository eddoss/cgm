

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Matrices/Matrix.hpp>

using namespace std;
using Mat = Matrix<2,2>;

TEST(Matrix_Assignment, Scalar)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat::value_type scalar = 4;
    input = scalar;
    for (const auto& val : input) ASSERT_EQ(val, scalar);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Assignment, Other)
{
    Mat input
    {
        1,2,
        3,4
    };
    Mat other
    {
        5,6,
        7,8
    };
    input = other;

    for (Mat::size_type i = 0; i < Mat::size; ++i) ASSERT_EQ(input[i], other[i]);
}
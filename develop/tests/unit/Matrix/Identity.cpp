

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Matrix/Matrix.hpp>
#include <Math3D/Core/Structs/Matrix/Operators.hpp>


using namespace std;
using Mat22 = Matrix<2,2>;
using Mat33 = Matrix<3,3>;
using Mat44 = Matrix<4,4>;
using Mat55 = Matrix<5,5>;

TEST(Matrix_Identity, Reference)
{
    {
        Mat22 ident
        {
            1, 0,
            0, 1
        };
        ASSERT_EQ(Mat22::identity(), ident);
    }

    {
        Mat33 ident
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };
        ASSERT_EQ(Mat33::identity(), ident);
    }

    {
        Mat44 ident
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
        ASSERT_EQ(Mat44::identity(), ident);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_Identity, Value)
{
    {
        Mat22 ident
        {
            1, 0,
            0, 1
        };
        ASSERT_EQ(Mat22::makeIdentity(), ident);
    }

    {
        Mat33 ident
        {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };
        ASSERT_EQ(Mat33::makeIdentity(), ident);
    }

    {
        Mat44 ident
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
        ASSERT_EQ(Mat44::makeIdentity(), ident);
    }
}

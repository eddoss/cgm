

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Common.hpp>
#include <CGM/detail/Core/Operators/Vector.hpp>
#include <CGM/detail/Core/Operators/Matrix.hpp>
#include <CGM/detail/Core/Functions/Matrix.hpp>
#include <CGM/detail/Cartesian/3D/Functions/Utils.hpp>


using namespace std;
using namespace CGM;

TEST(Cartesian_3D_InternalFunctions, multiply_matrix4x4_on_vector3)
{
    {
        Vector<3,int> vec {2,3,4};
        Matrix<4,4,int> mat
        {
            3,2,4,1,
            2,1,3,2,
            5,1,1,3,
            0,0,0,1
        };

        auto res = CGM_XYZ::detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Point>(mat, vec);
        Vector<3,int> exp {29,21,20};
        ASSERT_TRUE(res == exp);
    }

    {
        Vector<3,int> vec {2,3,4};
        Matrix<4,4,int> mat
        {
            3,2,4,1,
            2,1,3,2,
            5,1,1,3,
            0,0,0,1
        };

        auto res = CGM_XYZ::detail::multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(mat, vec);
        Vector<3,int> exp {28,19,17};
        ASSERT_TRUE(res == exp);
    }

}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, multiply_vector3_on_matrix4x4)
{
    {
        Vector<3,int> vec {2,3,4};
        Matrix<4,4,int> mat
        {
            3,2,5,0,
            2,1,1,0,
            4,3,1,0,
            1,2,3,1
        };

        auto res = CGM_XYZ::detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Point>(vec, mat);
        Vector<3,int> exp {29,21,20};
        ASSERT_TRUE(res == exp);
    }

    {
        Vector<3,int> vec {2,3,4};
        Matrix<4,4,int> mat
        {
            3,2,5,0,
            2,1,1,0,
            4,3,1,0,
            1,2,3,1
        };

        auto res = CGM_XYZ::detail::multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vec, mat);
        Vector<3,int> exp {28,19,17};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, multiply_matrix3x3_on_matrix4x4_res3x3)
{
    Matrix<3,3,int> expect
    {
         58,  37,   39,
         99,  62,   48,
        121,  66,   76
    };

    Matrix<3,3,int> mat3
    {
        4,2,5,
        3,6,7,
        9,8,5
    };

    Matrix<4,4,int> mat4
    {
        3,1,5,5,
        8,4,2,9,
        6,5,3,8,
        2,4,7,3
    };

    auto result = CGM_XYZ::detail::multiply_matrix3x3_on_matrix4x4_res3x3(mat3, mat4);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, multiply_matrix3x3_on_matrix4x4_res4x4)
{
    Matrix<4,4,int> expect
    {
         58,  37,   39,   78,
         99,  62,   48,  125,
        121,  66,   76,  157,
          2,   4,    7,    3
    };

    Matrix<3,3,int> mat3
    {
        4,2,5,
        3,6,7,
        9,8,5
    };

    Matrix<4,4,int> mat4
    {
        3,1,5,5,
        8,4,2,9,
        6,5,3,8,
        2,4,7,3
    };

    auto result = CGM_XYZ::detail::multiply_matrix3x3_on_matrix4x4_res4x4(mat3, mat4);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, multiply_matrix4x4_on_matrix3x3_res3x3)
{
    Matrix<3,3,int> expect
    {
        60,  52,  47,
        62,  56,  78,
        66,  66,  80
    };

    Matrix<3,3,int> mat3
    {
        4,2,5,
        3,6,7,
        9,8,5
    };

    Matrix<4,4,int> mat4
    {
        3,1,5,5,
        8,4,2,9,
        6,5,3,8,
        2,4,7,3
    };

    auto result = CGM_XYZ::detail::multiply_matrix4x4_on_matrix3x3_res3x3(mat4, mat3);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, multiply_matrix4x4_on_matrix3x3_res4x4)
{
    Matrix<4,4,int> expect
    {
        60,  52,  47,  5,
        62,  56,  78,  9,
        66,  66,  80,  8,
        83,  84,  73,  3
    };

    Matrix<3,3,int> mat3
    {
        4,2,5,
        3,6,7,
        9,8,5
    };

    Matrix<4,4,int> mat4
    {
        3,1,5,5,
        8,4,2,9,
        6,5,3,8,
        2,4,7,3
    };

    auto result = CGM_XYZ::detail::multiply_matrix4x4_on_matrix3x3_res4x4(mat4, mat3);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, fast_inverse_matrix4x4)
{
    Vector<3,double> x { 0.910683,  0.333334, -0.244017};
    Vector<3,double> y {-0.244017,  0.910683,  0.333334};
    Vector<3,double> z { 0.333334, -0.244017,  0.910683};
    Vector<3,double> p {      0.2,     -0.53,      0.91};

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    Matrix<4,4,double> input
    {
        x.x, x.y, x.z, p.x,
        y.x, y.y, y.z, p.y,
        z.x, z.y, z.z, p.z,
        0.0, 0.0, 0.0, 1.0
    };
#else
    Matrix<4,4,double> input
    {
        x.x, y.x, z.x, 0.0,
        x.y, y.y, z.y, 0.0,
        x.z, y.z, z.z, 0.0,
        p.x, p.y, p.z, 1.0
    };
#endif

    auto res = CGM_XYZ::detail::fast_inverse_matrix4x4(input);
    auto exp = inverseForce(input);

    ASSERT_TRUE(CGM::eq(res, exp, 0.00001));
}
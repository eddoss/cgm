

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Common.hpp>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Core/Functions/Matrix.hpp>
#include <CGM/Core/Functions/Quaternion.hpp>
#include <CGM/Core/Operators/Quaternion.hpp>
#include <CGM/Cartesian/3D/Functions/Utils.hpp>
#include <private/CGM/Cartesian/3D/InternalUtils.hpp>


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

        auto res = CGM_XYZ::_internal_multiply_matrix4x4_on_vector3<EVectorRepresentation::Point>(mat, vec);
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

        auto res = CGM_XYZ::_internal_multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(mat, vec);
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

        auto res = CGM_XYZ::_internal_multiply_vector3_on_matrix4x4<EVectorRepresentation::Point>(vec, mat);
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

        auto res = CGM_XYZ::_internal_multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vec, mat);
        Vector<3,int> exp {28,19,17};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_InternalFunctions, fast_inverse_matrix4x4)
{
    Vector<3,double> x { 0.910683,  0.333334, -0.244017};
    Vector<3,double> y {-0.244017,  0.910683,  0.333334};
    Vector<3,double> z { 0.333334, -0.244017,  0.910683};
    Vector<3,double> p {      0.2,     -0.53,      0.91};

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto res = CGM_XYZ::_internal_fast_inverse_matrix4x4(input);
    auto exp = inverseForce(input);

    ASSERT_TRUE(CGM::eq(res, exp, 0.00001));
}
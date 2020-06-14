

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Core/Operators/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>
#include <private/Math3D/Cartesian/3D/InternalUtils.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;


TEST(Cartesian_3D_InternalFunctions, rotate_vector3_by_quaternion)
{
    // axis = normalized(1,1,1), angle = 30 (deg)
    Quaternion<double> quat {0.965926, 0.149429, 0.149429, 0.149429};

    Vector<3,double> vec {1.0, 0.0, 0.0};
    Vector<3,double> exp {0.910683, 0.333334, -0.244017};

    MATH3D_XYZ_NAMESPACE::_internal_rotate_vector3_by_quaternion(vec, quat);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(vec, exp, 0.00001));
}

/* --------------------------------------------------------------------------------------- */

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

        auto res = MATH3D_XYZ_NAMESPACE::_internal_multiply_matrix4x4_on_vector3<EVectorRepresentation::Point>(mat, vec);
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

        auto res = MATH3D_XYZ_NAMESPACE::_internal_multiply_matrix4x4_on_vector3<EVectorRepresentation::Direction>(mat, vec);
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

        auto res = MATH3D_XYZ_NAMESPACE::_internal_multiply_vector3_on_matrix4x4<EVectorRepresentation::Point>(vec, mat);
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

        auto res = MATH3D_XYZ_NAMESPACE::_internal_multiply_vector3_on_matrix4x4<EVectorRepresentation::Direction>(vec, mat);
        Vector<3,int> exp {28,19,17};
        ASSERT_TRUE(res == exp);
    }
}
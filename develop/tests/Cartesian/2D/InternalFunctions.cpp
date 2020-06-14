

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <private/Math3D/Cartesian/2D/InternalUtils.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_2D_InternalFunctions, multiply_matrix3x3_on_vector2)
{
    Vector<2,int> vec {2,3};
    Matrix<3,3,int> mat
    {
        1,3,4,
        4,5,3,
        0,0,1,
    };

    {
        auto res = MATH3D_XY_NAMESPACE::_internal_multiply_matrix3x3_on_vector2<EVectorRepresentation::Point>(mat, vec);
        auto exp = Vector<2,int> {15,26};
        ASSERT_TRUE(res == exp);
    }

    {
        auto res = MATH3D_XY_NAMESPACE::_internal_multiply_matrix3x3_on_vector2<EVectorRepresentation::Direction>(mat, vec);
        auto exp = Vector<2,int> {11,23};
        ASSERT_TRUE(res == exp);
    }

}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_InternalFunctions, multiply_vector2_on_matrix3x3)
{
    Vector<2,int> vec {2,3};
    Matrix<3,3,int> mat
    {
        1,4,0,
        3,5,0,
        4,3,1
    };

    {
        auto res = MATH3D_XY_NAMESPACE::_internal_multiply_vector2_on_matrix3x3<EVectorRepresentation::Point>(vec, mat);
        auto exp = Vector<2,int> {15,26};
        ASSERT_TRUE(res == exp);
    }

    {
        auto res = MATH3D_XY_NAMESPACE::_internal_multiply_vector2_on_matrix3x3<EVectorRepresentation::Direction>(vec, mat);
        auto exp = Vector<2,int> {11,23};
        ASSERT_TRUE(res == exp);
    }
}
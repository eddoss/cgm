

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>
#include <Math3D/Cartesian/2D/Functions/Space.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_2D_Functions_Space, XYZ)
{
    Vector<2,int> X {2,1};
    Vector<2,int> Y {4,3};
    Vector<2,int> P {1,2};

    auto basis = MATH3D_XY_NAMESPACE::space(X,Y,P);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,int> expec
    {
        2,1,1,
        4,3,2,
        0,0,1
    };
#else
    Matrix<3,3,int> expec
    {
        2,4,0,
        1,3,0,
        1,2,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Space, Matrix2)
{
    Vector<2,int> position {5,1};
    Matrix<2,2,int> orientation
    {
        2,1,
        4,3
    };

    auto basis = MATH3D_XY_NAMESPACE::space(orientation, position);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,int> expec
    {
        2,1,5,
        4,3,1,
        0,0,1
    };
#else
    Matrix<3,3,int> expec
    {
        2,1,0,
        4,3,0,
        5,1,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}


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
#include <Math3D/Cartesian/3D/Functions/Space.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_3D_Functions_Space, XYZ)
{
    Vector<3,int> X {2,1,3};
    Vector<3,int> Y {4,3,6};
    Vector<3,int> Z {7,9,2};
    Vector<3,int> P {1,2,3};

    auto basis = MATH3D_XYZ_NAMESPACE::space(X,Y,Z,P);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<4,4,int> expec
    {
        2,1,3,1,
        4,3,6,2,
        7,9,2,3,
        0,0,0,1
    };
#else
    Matrix<4,4,int> expec
    {
        2,4,7,0,
        1,3,9,0,
        3,6,2,0,
        1,2,3,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Space, Matrix3)
{
    Vector<3,int> position {5,1,8};
    Matrix<3,3,int> orientation
    {
        2,1,3,
        4,3,6,
        7,9,2
    };

    auto basis = MATH3D_XYZ_NAMESPACE::space(orientation, position);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<4,4,int> expec
    {
        2,1,3,5,
        4,3,6,1,
        7,9,2,8,
        0,0,0,1
    };
#else
    Matrix<4,4,int> expec
    {
        2,4,7,0,
        1,3,9,0,
        3,6,2,0,
        5,1,8,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Space, Quaternion)
{
    Quaternion<double> quaternion {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> position {0.7, 1.3, 4.0};

    auto basis = MATH3D_XYZ_NAMESPACE::space(quaternion, position);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<4,4,double> expec
    {
         0.910683,  0.333334, -0.244017, 0.7,
        -0.244017,  0.910683,  0.333334, 1.3,
         0.333334, -0.244017,  0.910683, 4.0,
              0.0,       0.0,       0.0, 1.0
    };
#else
    Matrix<4,4,double> expec
    {
         0.910683, -0.244017,  0.333334, 0.0,
         0.333334,  0.910683, -0.244017, 0.0,
        -0.244017,  0.333334,  0.910683, 0.0,
              0.7,       1.3,       4.0, 1.0
    };
#endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(basis, expec, 0.0001));
}
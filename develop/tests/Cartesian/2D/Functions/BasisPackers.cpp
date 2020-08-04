

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Common.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/BasisPackers.hpp>


using namespace std;
using namespace CGM;

TEST(Cartesian_2D_Functions_BasisPackers, XYZ)
{
    Vector<2,int> X {2,1};
    Vector<2,int> Y {4,3};
    Vector<2,int> P {1,2};

    auto basis = CGM_XY::packBasis(X,Y,P);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

TEST(Cartesian_2D_Functions_BasisPackers, Matrix2)
{
    Vector<2,int> position {5,1};
    Matrix<2,2,int> orientation
    {
        2,1,
        4,3
    };

    auto basis = CGM_XY::packBasis(orientation, position);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_BasisPackers, UnpackSpace)
{
    Matrix<3,3,int> basis
    {
        2,1,3,
        4,3,6,
        0,0,1
    };

    auto [x,y,p] = CGM_XY::unpackBasis(basis);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<2,int> expec_x {2,1};
    Vector<2,int> expec_y {4,3};
    Vector<2,int> expec_p {3,6};
#else
    Vector<2,int> expec_x {2,4};
    Vector<2,int> expec_y {1,3};
    Vector<2,int> expec_p {0,0};
#endif

    ASSERT_TRUE(x == expec_x);
    ASSERT_TRUE(y == expec_y);
    ASSERT_TRUE(p == expec_p);
}
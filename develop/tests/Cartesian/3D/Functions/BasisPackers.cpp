

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
#include <CGM/Cartesian/3D/Functions/BasisPackers.hpp>
#include <CGM/IO.hpp>

using namespace std;
using namespace CGM;

TEST(Cartesian_3D_Functions_BasisPackers, FromXYZP)
{
    Vector<3,int> X {2,1,3};
    Vector<3,int> Y {4,3,6};
    Vector<3,int> Z {7,9,2};
    Vector<3,int> P {1,2,3};

    auto basis = CGM_XYZ::packBasis(X,Y,Z,P);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

TEST(Cartesian_3D_Functions_BasisPackers, FromMatrix3AndPosition)
{
    Vector<3,int> position {5,1,8};
    Matrix<3,3,int> orientation
    {
        2,1,3,
        4,3,6,
        7,9,2
    };

    auto basis = CGM_XYZ::packBasis(orientation, position);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
        2,1,3,0,
        4,3,6,0,
        7,9,2,0,
        5,1,8,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_BasisPackers, FromQuaternionAndPosition)
{
    Quaternion<double> quaternion {-0.006227,0.435855,0.174342,0.882948};
    Vector<3,double> position {0.7, 1.3, 4.0};

    auto result = CGM_XYZ::packBasis(quaternion, position);

    Vector<3,double> ex {0.559270,0.302442,-0.771846};
    Vector<3,double> ey {-0.313298,0.939132,0.140980};
    Vector<3,double> ez {0.767503,0.162971,0.619983};

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<4,4,double> expec
    {
        ex.x, ex.y, ex.z, position.x,
        ey.x, ey.y, ey.z, position.y,
        ez.x, ez.y, ez.z, position.z,
        0.0, 0.0, 0.0, 1.0
    };
#else
    Matrix<4,4,double> expec
    {
        ex.x, ey.x, ez.x, 0.0,
        ex.y, ey.y, ez.y, 0.0,
        ex.z, ey.z, ez.z, 0.0,
        position.x, position.y, position.z, 1.0
    };
#endif

    ASSERT_TRUE(CGM::equal(result, expec, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_BasisPackers, Unpack)
{
    Matrix<4,4,int> basis
    {
        2,1,3,1,
        4,3,6,2,
        7,9,2,3,
        0,0,0,1
    };

    auto [x,y,z,p] = CGM_XYZ::unpackBasis(basis);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,int> expec_x {2,1,3};
    Vector<3,int> expec_y {4,3,6};
    Vector<3,int> expec_z {7,9,2};
    Vector<3,int> expec_p {1,2,3};
#else
    Vector<3,int> expec_x {2,4,7};
    Vector<3,int> expec_y {1,3,9};
    Vector<3,int> expec_z {3,6,2};
    Vector<3,int> expec_p {0,0,0};
#endif

    ASSERT_TRUE(x == expec_x);
    ASSERT_TRUE(y == expec_y);
    ASSERT_TRUE(z == expec_z);
    ASSERT_TRUE(p == expec_p);
}
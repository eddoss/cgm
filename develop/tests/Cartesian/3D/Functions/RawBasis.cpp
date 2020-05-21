

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Cartesian/3D/Functions/RawBasis.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_3D_Functions_RawBasis, XYZ)
{
    Vector<3,int> X {2,1,3};
    Vector<3,int> Y {4,3,6};
    Vector<3,int> Z {7,9,2};

    auto basis = MATH3D_XYZ_NAMESPACE::rawBasis(X,Y,Z);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,int> expec
    {
        2,1,3,
        4,3,6,
        7,9,2
    };
#else
    Matrix<3,3,int> expec
    {
        2,4,7,
        1,3,9,
        3,6,2
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_RawBasis, XYZPos)
{
    Vector<3,int> X {2,1,3};
    Vector<3,int> Y {4,3,6};
    Vector<3,int> Z {7,9,2};
    Vector<3,int> P {5,1,8};

    auto basis = MATH3D_XYZ_NAMESPACE::rawBasis(X,Y,Z,P);

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

TEST(Cartesian_3D_Functions_RawBasis, Matix3Pos)
{
    Vector<3,int> pos {5,1,8};
    Matrix<3,3,int> orient
    {
        2,1,3,
        4,3,6,
        7,9,2
    };

    auto basis = MATH3D_XYZ_NAMESPACE::rawBasis(orient, pos);

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
        2,1,3,0,
        4,3,6,0,
        7,9,2,0,
        5,1,8,1
    };
#endif

    ASSERT_TRUE(basis == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_RawBasis, Quat)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};

    auto basis = MATH3D_XYZ_NAMESPACE::rawBasis(Q);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,double> expec
    {
         0.910683,  0.333334, -0.244017,
        -0.244017,  0.910683,  0.333334,
         0.333334, -0.244017,  0.910683
    };
#else
    Matrix<3,3,double> expec
    {
         0.910683, -0.244017,  0.333334,
         0.333334,  0.910683, -0.244017,
        -0.244017,  0.333334,  0.910683
    };
#endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(basis, expec, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_RawBasis, QuatPos)
{
    Vector<3,double> P {0.7, 1.3, 4.0};
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};

    auto basis = MATH3D_XYZ_NAMESPACE::rawBasis(Q, P);

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


#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Cartesian/Enums.hpp>
#include <Math3D/Cartesian/2D/Basis.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>
#include <Math3D/Cartesian/2D/Functions/Space.hpp>
#include <Math3D/Cartesian/2D/Functions/Orientation.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_2D_Basis, Matrix2)
{
    Vector<2,double> X {0.798635, 0.601815};
    Vector<2,double> Y {-0.601815, 0.798635};
    Vector<2,double> P {0.7, 1.3};

    MATH3D_XY_NAMESPACE::Basis<MATH3D_XY_NAMESPACE::EBasisBase::Matrix2,double> basis {X,Y,P};

    ASSERT_TRUE(equal(basis.x(), X, 0.0001));
    ASSERT_TRUE(equal(basis.y(), Y, 0.0001));
    ASSERT_TRUE(equal(basis.position(), P, 0.0001));
    ASSERT_TRUE(equal(basis.spaceMatrix(), MATH3D_XY_NAMESPACE::space(X,Y,P), 0.0001));
    ASSERT_TRUE(equal(basis.orientationMatrix(), MATH3D_XY_NAMESPACE::orientationMatrix(X,Y), 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Basis, Matrix3)
{
    Vector<2,double> X {0.798635, 0.601815};
    Vector<2,double> Y {-0.601815, 0.798635};
    Vector<2,double> P {0.7, 1.3};

    MATH3D_XY_NAMESPACE::Basis<MATH3D_XY_NAMESPACE::EBasisBase::Matrix3,double> basis {X,Y,P};

    ASSERT_TRUE(equal(basis.x(), X, 0.0001));
    ASSERT_TRUE(equal(basis.y(), Y, 0.0001));
    ASSERT_TRUE(equal(basis.position(), P, 0.0001));
    ASSERT_TRUE(equal(basis.spaceMatrix(), MATH3D_XY_NAMESPACE::space(X,Y,P), 0.0001));
    ASSERT_TRUE(equal(basis.orientationMatrix(), MATH3D_XY_NAMESPACE::orientationMatrix(X,Y), 0.0001));
}
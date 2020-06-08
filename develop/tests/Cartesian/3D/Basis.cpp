

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Core/Operators/Quaternion.hpp>
#include <Math3D/Cartesian/Enums.hpp>
#include <Math3D/Cartesian/3D/Basis.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>

using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_3D_Basis, Matrix3)
{
    Vector<3,double> X {0.910683, 0.333334, -0.244017};
    Vector<3,double> Y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> Z {0.333334, -0.244017, 0.910683};
    Vector<3,double> P {0.7, 1.3, 4.0};

    MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis {X,Y,Z,P};

    ASSERT_TRUE(equal(basis.x(), X, 0.0001));
    ASSERT_TRUE(equal(basis.y(), Y, 0.0001));
    ASSERT_TRUE(equal(basis.z(), Z, 0.0001));

#ifdef MATH3D_CARTESIAN_UP_X
    ASSERT_TRUE(equal(basis.up(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    ASSERT_TRUE(equal(basis.up(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    ASSERT_TRUE(equal(basis.up(), Z, 0.0001));
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_RIGHT_X
    ASSERT_TRUE(equal(basis.right(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    ASSERT_TRUE(equal(basis.right(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    ASSERT_TRUE(equal(basis.right(), Z, 0.0001));
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_FORWARD_X
    ASSERT_TRUE(equal(basis.forward(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    ASSERT_TRUE(equal(basis.forward(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    ASSERT_TRUE(equal(basis.forward(), Z, 0.0001));
#endif

    ASSERT_TRUE(basis.position() == P);
    ASSERT_TRUE(equal(basis.spaceMatrix(), MATH3D_XYZ_NAMESPACE::space(X,Y,Z,P), 0.0001));
    ASSERT_TRUE(equal(basis.orientationMatrix(), MATH3D_XYZ_NAMESPACE::orientationMatrix(X,Y,Z), 0.0001));
    ASSERT_TRUE(equal(basis.orientationQuaternion(), {0.965926, 0.149429, 0.149429, 0.149429}, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Basis, Matrix4)
{
    Vector<3,double> X {0.910683, 0.333334, -0.244017};
    Vector<3,double> Y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> Z {0.333334, -0.244017, 0.910683};
    Vector<3,double> P {0.7, 1.3, 4.0};

    MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix4,double> basis {X,Y,Z,P};

    ASSERT_TRUE(equal(basis.x(), X, 0.0001));
    ASSERT_TRUE(equal(basis.y(), Y, 0.0001));
    ASSERT_TRUE(equal(basis.z(), Z, 0.0001));

#ifdef MATH3D_CARTESIAN_UP_X
    ASSERT_TRUE(equal(basis.up(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    ASSERT_TRUE(equal(basis.up(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    ASSERT_TRUE(equal(basis.up(), Z, 0.0001));
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_RIGHT_X
    ASSERT_TRUE(equal(basis.right(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    ASSERT_TRUE(equal(basis.right(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    ASSERT_TRUE(equal(basis.right(), Z, 0.0001));
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_FORWARD_X
    ASSERT_TRUE(equal(basis.forward(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    ASSERT_TRUE(equal(basis.forward(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    ASSERT_TRUE(equal(basis.forward(), Z, 0.0001));
#endif

    ASSERT_TRUE(basis.position() == P);
    ASSERT_TRUE(equal(basis.spaceMatrix(), MATH3D_XYZ_NAMESPACE::space(X,Y,Z,P), 0.0001));
    ASSERT_TRUE(equal(basis.orientationMatrix(), MATH3D_XYZ_NAMESPACE::orientationMatrix(X,Y,Z), 0.0001));
    ASSERT_TRUE(equal(basis.orientationQuaternion(), {0.965926, 0.149429, 0.149429, 0.149429}, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Basis, Quaternion)
{
    Vector<3,double> X {0.910683, 0.333334, -0.244017};
    Vector<3,double> Y {-0.244017, 0.910683, 0.333334};
    Vector<3,double> Z {0.333334, -0.244017, 0.910683};
    Vector<3,double> P {0.7, 1.3, 4.0};

    MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Quaternion,double> basis {X,Y,Z,P};

    ASSERT_TRUE(equal(basis.x(), X, 0.0001));
    ASSERT_TRUE(equal(basis.y(), Y, 0.0001));
    ASSERT_TRUE(equal(basis.z(), Z, 0.0001));

#ifdef MATH3D_CARTESIAN_UP_X
    ASSERT_TRUE(equal(basis.up(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    ASSERT_TRUE(equal(basis.up(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    ASSERT_TRUE(equal(basis.up(), Z, 0.0001));
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_RIGHT_X
    ASSERT_TRUE(equal(basis.right(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    ASSERT_TRUE(equal(basis.right(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    ASSERT_TRUE(equal(basis.right(), Z, 0.0001));
#endif

// ------------------------------

#ifdef MATH3D_CARTESIAN_FORWARD_X
    ASSERT_TRUE(equal(basis.forward(), X, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    ASSERT_TRUE(equal(basis.forward(), Y, 0.0001));
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    ASSERT_TRUE(equal(basis.forward(), Z, 0.0001));
#endif

    ASSERT_TRUE(basis.position() == P);
    ASSERT_TRUE(equal(basis.spaceMatrix(), MATH3D_XYZ_NAMESPACE::space(X,Y,Z,P), 0.0001));
    ASSERT_TRUE(equal(basis.orientationMatrix(), MATH3D_XYZ_NAMESPACE::orientationMatrix(X,Y,Z), 0.0001));
    ASSERT_TRUE(equal(basis.orientationQuaternion(), {0.965926, 0.149429, 0.149429, 0.149429}, 0.0001));
}
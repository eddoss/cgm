

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Basis.hpp>
#include <Math3D/Cartesian/3D/Functions/Converters.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>
#include <private/Math3D/Cartesian/3D/InternalUtils.hpp>

using namespace std;
using namespace MATH3D_NAMESPACE;

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Vec3_Mat3)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::orientationMatrix(Q);
    auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, basis);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec = inverseForce(basis) * coord;
#else
    Vector<3,double> expec = coord * inverseForce(basis);
#endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Vec3_Mat3WithPos)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::orientationMatrix(Q);
    auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, basis, P);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec = inverseForce(basis) * coord + P;
#else
    Vector<3,double> expec = coord * inverseForce(basis) + P;
#endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Vec3_Mat4)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::space(Q,P);
    auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, basis);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec = (inverseForce(basis) * Vector<4,double>(coord,1.0)).xyz();
#else
    Vector<3,double> expec = (Vector<4,double>(coord,1.0) * inverseForce(basis)).xyz();
#endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Vec3_Quat)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, Q);
    auto expec = coord;

    MATH3D_XYZ_NAMESPACE::_internal_rotate_vector3_by_quaternion(expec, inverseForce(Q));

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Vec3_QuatWithPos)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, Q, P);
    auto expec = coord;

    MATH3D_XYZ_NAMESPACE::_internal_rotate_vector3_by_quaternion(expec, inverseForce(Q));
    expec += P;

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Vec3_Basis)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};
    Vector<3,double> coord {1.2, 2.2, 1.7};

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis(Q,P);
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, basis);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        auto expec = inverseForce(basis.orientationMatrix()) * coord + basis.position();
#else
        auto expec = coord * inverseForce(basis.orientationMatrix()) + basis.position();
#endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(reslt, expec, 0.0001));
    }

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix4,double> basis(Q,P);
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, basis);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        auto expec = (inverseForce(basis.spaceMatrix()) * Vector<4,double>(coord,1.0)).xyz();
#else
        auto expec = (Vector<4,double>(coord,1.0) * inverseForce(basis.spaceMatrix())).xyz();
#endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Quaternion,double> basis(Q,P);

        auto expec = coord;
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, basis);
        MATH3D_XYZ_NAMESPACE::_internal_rotate_vector3_by_quaternion(expec, inverseForce(basis.orientationQuaternion()));
        expec += P;

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Vec3_Mat3)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::orientationMatrix(Q);
    auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basis);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec = basis * coord;
#else
    Vector<3,double> expec = coord * basis;
#endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Vec3_Mat3WithPos)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::orientationMatrix(Q);
    auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basis, P);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec = basis * coord + P;
#else
    Vector<3,double> expec = coord * basis + P;
#endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Vec3_Mat4)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::space(Q,P);
    auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basis);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Vector<3,double> expec = (basis * Vector<4,double>(coord,1.0)).xyz();
#else
    Vector<3,double> expec = (Vector<4,double>(coord,1.0) * basis).xyz();
#endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Vec3_Quat)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, Q);
    auto expec = coord;

    MATH3D_XYZ_NAMESPACE::_internal_rotate_vector3_by_quaternion(expec, Q);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Vec3_QuatWithPos)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, Q, P);
    auto expec = coord;

    MATH3D_XYZ_NAMESPACE::_internal_rotate_vector3_by_quaternion(expec, Q);
    expec += P;

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Vec3_Basis)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};
    Vector<3,double> coord {1.2, 2.2, 1.7};

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis(Q,P);
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basis);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        auto expec = basis.orientationMatrix() * coord + basis.position();
#else
        auto expec = coord * basis.orientationMatrix() + basis.position();
#endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix4,double> basis(Q,P);
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basis);
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        auto expec = (basis.spaceMatrix() * Vector<4,double>(coord,1.0)).xyz();
#else
        auto expec = (Vector<4,double>(coord,1.0) * basis.spaceMatrix()).xyz();
#endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Quaternion,double> basis(Q,P);

        auto expec = coord;
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basis);
        MATH3D_XYZ_NAMESPACE::_internal_rotate_vector3_by_quaternion(expec, basis.orientationQuaternion());
        expec += P;

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}
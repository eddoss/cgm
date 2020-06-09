

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Basis.hpp>
#include <Math3D/Cartesian/3D/Functions/Converters.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>
#include <Math3D/Cartesian/Enums.hpp>
#include <private/Math3D/Cartesian/3D/InternalUtils.hpp>

using namespace std;
using namespace MATH3D_NAMESPACE;

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
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::orientationMatrix(Q);

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<POINT>(coord, basis, P);
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        Vector<3,double> expec = basis * coord + P;
    #else
        Vector<3,double> expec = coord * basis + P;
    #endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<DIRECTION>(coord, basis, P);
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        Vector<3,double> expec = basis * coord;
    #else
        Vector<3,double> expec = coord * basis;
    #endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Vec3_Mat4)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::space(Q,P);

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<POINT>(coord, basis);
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        Vector<3, double> expec = (basis * Vector<4, double>(coord, 1.0)).xyz();
    #else
        Vector<3,double> expec = (Vector<4,double>(coord,1.0) * basis).xyz();
    #endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<DIRECTION>(coord, basis);
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        Vector<3, double> expec = (basis * Vector<4, double>(coord, 0.0)).xyz();
    #else
        Vector<3,double> expec = (Vector<4,double>(coord,0.0) * basis).xyz();
    #endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
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
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<POINT>(coord, Q, P);
        auto expec = MATH3D_XYZ_NAMESPACE::_internal_rotated_vector3_by_quaternion(coord, Q) + P;
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<DIRECTION>(coord, Q, P);
        auto expec = MATH3D_XYZ_NAMESPACE::_internal_rotated_vector3_by_quaternion(coord, Q);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Vec3_Basis)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};
    Vector<3,double> coord {1.2, 2.2, 1.7};

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis(Q,P);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<POINT>(coord, basis);
        #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
            auto expec = basis.orientationMatrix() * coord + basis.position();
        #else
            auto expec = coord * basis.orientationMatrix() + basis.position();
        #endif
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<DIRECTION>(coord, basis);
        #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
            auto expec = basis.orientationMatrix() * coord;
        #else
            auto expec = coord * basis.orientationMatrix();
        #endif
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }
    }

    /* =================== */

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix4,double> basis(Q,P);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<POINT>(coord, basis);
        #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
            auto expec = (basis.spaceMatrix() * Vector<4,double>(coord,1.0)).xyz();
        #else
            auto expec = (Vector<4,double>(coord,1.0) * basis.spaceMatrix()).xyz();
        #endif
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<DIRECTION>(coord, basis);
        #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
            auto expec = (basis.spaceMatrix() * Vector<4,double>(coord,0.0)).xyz();
        #else
            auto expec = (Vector<4,double>(coord,0.0) * basis.spaceMatrix()).xyz();
        #endif
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }
    }

    /* =================== */

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Quaternion,double> basis(Q,P);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<POINT>(coord, basis);
            auto expec = MATH3D_XYZ_NAMESPACE::_internal_rotated_vector3_by_quaternion(coord, basis.orientationQuaternion()) + basis.position();
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToGlobal<DIRECTION>(coord, basis);
            auto expec = MATH3D_XYZ_NAMESPACE::_internal_rotated_vector3_by_quaternion(coord, basis.orientationQuaternion());
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }
    }
}
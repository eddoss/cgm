

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

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3)
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

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3WithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::orientationMatrix(Q);

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis, P);
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        Vector<3, double> expec = inverseForce(basis) * coord + P;
    #else
        Vector<3,double> expec = coord * inverseForce(basis) + P;
    #endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    /* ------- */

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis, P);
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        Vector<3, double> expec = inverseForce(basis) * coord;
    #else
        Vector<3,double> expec = coord * inverseForce(basis);
    #endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat4)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basis = MATH3D_XYZ_NAMESPACE::space(Q,P);

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis);
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        Vector<3,double> expec = (inverseForce(basis) * Vector<4,double>(coord,1.0)).xyz();
    #else
        Vector<3,double> expec = (Vector<4,double>(coord,1.0) * inverseForce(basis)).xyz();
    #endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    /* ------- */

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis);
    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        Vector<3,double> expec = (inverseForce(basis) * Vector<4,double>(coord,0.0)).xyz();
    #else
        Vector<3,double> expec = (Vector<4,double>(coord,0.0) * inverseForce(basis)).xyz();
    #endif
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Quat)
{
    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, Q);
    auto expec = coord;

    MATH3D_XYZ_NAMESPACE::_internal_rotate_vector3_by_quaternion(expec, inverseForce(Q));

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_QuatWithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, Q, P);
        auto expec = MATH3D_XYZ_NAMESPACE::_internal_rotated_vector3_by_quaternion(coord, inverseForce(Q)) + P;
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    /* ------- */

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, Q, P);
        auto expec = MATH3D_XYZ_NAMESPACE::_internal_rotated_vector3_by_quaternion(coord, inverseForce(Q));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Basis)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> Q {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> P {3.2, 6.3, 4.1};
    Vector<3,double> coord {1.2, 2.2, 1.7};

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis(Q,P);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis);
        #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
            auto expec = inverseForce(basis.orientationMatrix()) * coord + basis.position();
        #else
            auto expec = coord * inverseForce(basis.orientationMatrix()) + basis.position();
        #endif
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(reslt, expec, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis);
        #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
            auto expec = inverseForce(basis.orientationMatrix()) * coord;
        #else
            auto expec = coord * inverseForce(basis.orientationMatrix());
        #endif
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(reslt, expec, 0.0001));
        }
    }

    /* =================== */

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix4,double> basis(Q,P);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis);
        #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
            auto expec = (inverseForce(basis.spaceMatrix()) * Vector<4,double>(coord,1.0)).xyz();
        #else
            auto expec = (Vector<4,double>(coord,1.0) * inverseForce(basis.spaceMatrix())).xyz();
        #endif
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis);
        #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
            auto expec = (inverseForce(basis.spaceMatrix()) * Vector<4,double>(coord,0.0)).xyz();
        #else
            auto expec = (Vector<4,double>(coord,0.0) * inverseForce(basis.spaceMatrix())).xyz();
        #endif
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }
    }

    /* =================== */

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Quaternion,double> basis(Q,P);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis);
            auto expec = MATH3D_XYZ_NAMESPACE::_internal_rotated_vector3_by_quaternion(coord, inverseForce(Q)) + basis.position();
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis);
            auto expec = MATH3D_XYZ_NAMESPACE::_internal_rotated_vector3_by_quaternion(coord, inverseForce(Q));
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }
    }
}
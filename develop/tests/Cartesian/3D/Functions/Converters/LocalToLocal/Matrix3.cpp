

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

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat3)
{
    Quaternion<double> QA {0.965926, 0.149429, 0.149429, 0.149429};
    Quaternion<double> QB {0.095490, -0.143236, -0.477452, 0.861629};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basisA = MATH3D_XYZ_NAMESPACE::orientationMatrix(QA);
    auto basisB = MATH3D_XYZ_NAMESPACE::orientationMatrix(QB);

    auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal(coord, basisA, basisB);
    auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
    expec = MATH3D_XYZ_NAMESPACE::globalToLocal(expec, basisB);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat3WithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> QA {0.965926, 0.149429, 0.149429, 0.149429};
    Quaternion<double> QB {0.095490, -0.143236, -0.477452, 0.861629};
    Vector<3,double> PB {6.0, 3.1, 1.2};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basisA = MATH3D_XYZ_NAMESPACE::orientationMatrix(QA);
    auto basisB = MATH3D_XYZ_NAMESPACE::orientationMatrix(QB);

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<POINT>(coord, basisA, basisB, PB);
        auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
        expec = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(expec, basisB, PB);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<DIRECTION>(coord, basisA, basisB, PB);
        auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
        expec = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(expec, basisB, PB);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat4)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> QA {0.965926, 0.149429, 0.149429, 0.149429};
    Quaternion<double> QB {0.095490, -0.143236, -0.477452, 0.861629};
    Vector<3,double> PB {6.0, 3.1, 1.2};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basisA = MATH3D_XYZ_NAMESPACE::orientationMatrix(QA);
    auto basisB = MATH3D_XYZ_NAMESPACE::space(QB, PB);

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<POINT>(coord, basisA, basisB);
        auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
        expec = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(expec, basisB);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<DIRECTION>(coord, basisA, basisB);
        auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
        expec = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(expec, basisB);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Quat)
{
    Quaternion<double> QA {0.965926, 0.149429, 0.149429, 0.149429};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basisA = MATH3D_XYZ_NAMESPACE::orientationMatrix(QA);
    auto basisB = Quaternion<double> {0.095490, -0.143236, -0.477452, 0.861629};

    auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal(coord, basisA, basisB);
    auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
    expec = MATH3D_XYZ_NAMESPACE::globalToLocal(expec, basisB);
    ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_QuatWithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> QA {0.965926, 0.149429, 0.149429, 0.149429};
    Vector<3,double> PB {6.0, 3.1, 1.2};

    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto basisA = MATH3D_XYZ_NAMESPACE::orientationMatrix(QA);
    auto basisB = Quaternion<double> {0.095490, -0.143236, -0.477452, 0.861629};

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<POINT>(coord, basisA, basisB, PB);
        auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
        expec = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(expec, basisB, PB);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }

    {
        auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<DIRECTION>(coord, basisA, basisB, PB);
        auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
        expec = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(expec, basisB, PB);
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Basis)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    Quaternion<double> QA {0.965926, 0.149429, 0.149429, 0.149429};
    Quaternion<double> QB {0.095490, -0.143236, -0.477452, 0.861629};
    Vector<3,double> PB {6.0, 3.1, 1.2};
    Vector<3,double> coord {1.2, 2.2, 1.7};
    auto basisA = MATH3D_XYZ_NAMESPACE::orientationMatrix(QA);

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basisB(QB,PB);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<POINT>(coord, basisA, basisB);
            auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
            expec = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(expec, basisB);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<DIRECTION>(coord, basisA, basisB);
            auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
            expec = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(expec, basisB);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }
    }

    /* =================== */

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix4,double> basisB(QB,PB);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<POINT>(coord, basisA, basisB);
            auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
            expec = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(expec, basisB);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<DIRECTION>(coord, basisA, basisB);
            auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
            expec = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(expec, basisB);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }
    }

    /* =================== */

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Quaternion,double> basisB(QB,PB);

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<POINT>(coord, basisA, basisB);
            auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
            expec = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(expec, basisB);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }

        /* ------- */

        {
            auto reslt = MATH3D_XYZ_NAMESPACE::localToLocal<DIRECTION>(coord, basisA, basisB);
            auto expec = MATH3D_XYZ_NAMESPACE::localToGlobal(coord, basisA);
            expec = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(expec, basisB);
            ASSERT_TRUE(MATH3D_NAMESPACE::equal(expec, reslt, 0.0001));
        }
    }
}
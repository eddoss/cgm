

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Cartesian/3D/Types/Basis.hpp>
#include <Math3D/Cartesian/3D/Functions/Converters.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>
#include <Math3D/Cartesian/3D/Types/Enums.hpp>
#include <private/Math3D/Cartesian/3D/InternalUtils.hpp>

#include <Math3D/IO.hpp>

using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3)
{
    auto x = Vector<3,double> { +0.915889, +0.310965, +0.253868 };
    auto y = Vector<3,double> { +0.370337, -0.898572, -0.235413 };
    auto z = Vector<3,double> { +0.154913, +0.309629, -0.938153 };

    auto orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(x,y,z);
    auto coord = Vector<3,double> {1.2, 2.2, 1.7};

    auto expect = Vector<3,double> {2.17716, -1.07733, -1.80812};
    auto result = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, orientation);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3WithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto x = Vector<3,double> { +0.915889, +0.310965, +0.253868 };
    auto y = Vector<3,double> { +0.370337, -0.898572, -0.235413 };
    auto z = Vector<3,double> { +0.154913, +0.309629, -0.938153 };
    auto p = Vector<3,double> {3.2, 6.3, 4.1};

    auto orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(x,y,z);
    auto coord = Vector<3,double> {1.2, 2.2, 1.7};

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, orientation, p);
        auto expect = Vector<3,double> {-3.72195, 2.31910, 2.70902};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, orientation, p);
        auto expect = Vector<3,double> {2.17716, -1.07733, -1.80812};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat4)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto x = Vector<3,double> { +0.915889, +0.310965, +0.253868 };
    auto y = Vector<3,double> { +0.370337, -0.898572, -0.235413 };
    auto z = Vector<3,double> { +0.154913, +0.309629, -0.938153 };
    auto p = Vector<3,double> {3.2, 6.3, 4.1};

    auto basis = MATH3D_XYZ_NAMESPACE::packBasis(x,y,z,p);
    auto coord = Vector<3,double> {1.2, 2.2, 1.7};

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis);
        auto expect = Vector<3,double> {-3.72195, 2.31910, 2.70902};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis);
        auto expect = Vector<3,double> {2.17716, -1.07733, -1.80812};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Quat)
{
    auto orientation = Quaternion<double> {-0.14068, 0.96858, 0.17585, 0.10551};
    auto coord = Vector<3,double> {1.2, 2.2, 1.7};

    auto result = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, orientation);
    #ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
        Vector<3,double> expect {2.21477, -1.93267, -0.72779};
    #else
        Vector<3,double> expect {2.17716, -1.07734, -1.80814};
    #endif

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_QuatWithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto orientation = Quaternion<double> {-0.14068, 0.96858, 0.17585, 0.10551};
    auto position = Vector<3,double> {3.2, 6.3, 4.1};
    auto coord = Vector<3,double> {1.2, 2.2, 1.7};

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, orientation, position);
    #ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
        Vector<3,double> expect {-3.71602, 3.50850, 0.67227};
    #else
        Vector<3,double> expect {-3.72196, 2.31914, 2.70905};
    #endif

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, orientation, position);
    #ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
        Vector<3,double> expect {2.21477, -1.93267, -0.72779};
    #else
        Vector<3,double> expect {2.17716, -1.07734, -1.80814};
    #endif

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Basis)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto x = Vector<3,double> { +0.915889, +0.310965, +0.253868 };
    auto y = Vector<3,double> { +0.370337, -0.898572, -0.235413 };
    auto z = Vector<3,double> { +0.154913, +0.309629, -0.938153 };
    auto coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto position = Vector<3,double> {3.2, 6.3, 4.1};
    auto quatOrient = Quaternion<double> {-0.14068, 0.96858, 0.17585, 0.10551};
    auto expectPoint = Vector<3,double> {-3.72195, 2.31910, 2.70902};
    auto expectDirection = Vector<3,double> {2.17716, -1.07733, -1.80812};

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis(x, y, z, position);

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis), expectPoint, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis), expectDirection, 0.0001));
    }

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis(x, y, z, position);

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis), expectPoint, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis), expectDirection, 0.0001));
    }

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Quaternion,double> basis(quatOrient, position);
    #ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
        Vector<3,double> qexpectPoint {-3.71602, 3.50850, 0.67227};
        Vector<3,double> qexpectDirection {2.21477, -1.93267, -0.72779};
    #else
        Vector<3,double> qexpectPoint {-3.72196, 2.31914, 2.70905};
        Vector<3,double> qexpectDirection {2.17716, -1.07734, -1.80814};
    #endif

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis), qexpectPoint, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis), qexpectDirection, 0.0001));
    }
}
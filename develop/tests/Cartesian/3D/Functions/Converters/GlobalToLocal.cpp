

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
    auto x = Vector<3,double> { +0.559270, +0.302442, -0.77184 };
    auto y = Vector<3,double> { -0.313298, +0.939132, +0.14098 };
    auto z = Vector<3,double> { +0.767503, +0.162971, +0.61998 };
    auto coord = Vector<3,double>{ 3.13, 2.2, 1.7 };

    auto orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(x,y,z);

    auto expect = Vector<3,double> {+2.366018, +3.289785, -1.051749};
    auto result = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, orientation);

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat3WithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto x = Vector<3,double> { +0.559270, +0.302442, -0.77184 };
    auto y = Vector<3,double> { -0.313298, +0.939132, +0.14098 };
    auto z = Vector<3,double> { +0.767503, +0.162971, +0.61998 };
    auto p = Vector<3,double> { -1.200000, -0.600000, 4.400000 };
    auto coord = Vector<3,double>{ 3.13, 2.2, 1.7 };

    auto orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(x,y,z);

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, orientation, p);
        auto expect = Vector<3,double> {-0.527851, +3.499122, -4.621301};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, orientation, p);
        auto expect = Vector<3,double> {+2.366018, +3.289785, -1.051749};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Mat4)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto x = Vector<3,double> { +0.559270, +0.302442, -0.77184 };
    auto y = Vector<3,double> { -0.313298, +0.939132, +0.14098 };
    auto z = Vector<3,double> { +0.767503, +0.162971, +0.61998 };
    auto p = Vector<3,double> { -1.200000, -0.600000, 4.400000 };
    auto coord = Vector<3,double> { 3.13, 2.2, 1.7 };

    auto basis = MATH3D_XYZ_NAMESPACE::packBasis(x,y,z,p);

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis);
        auto expect = Vector<3,double> {-0.527851, +3.499122, -4.621301};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis);
        auto expect = Vector<3,double> {+2.366018, +3.289785, -1.051749};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Quat)
{
    auto orientation = Quaternion<double> {-0.006227,0.435855,0.174342,0.882948};
    auto coord = Vector<3,double> { 3.13, 2.2, 1.7 };

    auto result = MATH3D_XYZ_NAMESPACE::globalToLocal(coord, orientation);
    auto expect = Vector<3,double> {+2.366018, +3.289785, -1.051749};

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_QuatWithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto orientation = Quaternion<double> {-0.006227,0.435855,0.174342,0.882948};
    auto position = Vector<3,double> { -1.200000, -0.600000, 4.400000 };
    auto coord = Vector<3,double> { 3.13, 2.2, 1.7 };

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, orientation, position);
        auto expect = Vector<3,double> {-0.527851, +3.499122, -4.621301};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }

    {
        auto result = MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, orientation, position);
        auto expect = Vector<3,double> {+2.366018, +3.289785, -1.051749};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, GlobalToLocal_Basis)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto x = Vector<3,double>{ +0.559270, +0.302442, -0.77184 };
    auto y = Vector<3,double>{ -0.313298, +0.939132, +0.14098 };
    auto z = Vector<3,double>{ +0.767503, +0.162971, +0.61998 };
    auto p = Vector<3,double>{ -1.200000, -0.600000, +4.40000 };
    auto q = Quaternion<double>{ -0.006227, 0.435855, 0.174342, 0.882948 };

    auto coord = Vector<3,double>{ 3.13, 2.2, 1.7 };
    auto expectPoint = Vector<3,double>{ -0.527851, +3.499122, -4.621301 };
    auto expectDirection = Vector<3,double>{ +2.366018, +3.289785, -1.051749 };

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis(x,y,z,p);

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis), expectPoint, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis), expectDirection, 0.0001));
    }

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3,double> basis(x,y,z,p);

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis), expectPoint, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis), expectDirection, 0.0001));
    }

    {
        MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Quaternion,double> basis(q,p);

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<POINT>(coord, basis), expectPoint, 0.0001));
        ASSERT_TRUE(MATH3D_NAMESPACE::equal(MATH3D_XYZ_NAMESPACE::globalToLocal<DIRECTION>(coord, basis), expectDirection, 0.0001));
    }
}
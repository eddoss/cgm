

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/BasisPackers.hpp>


using namespace std;
using namespace CGM;

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Mat3)
{
    auto x = Vector<3,double> { +0.559270, +0.302442, -0.77184 };
    auto y = Vector<3,double> { -0.313298, +0.939132, +0.14098 };
    auto z = Vector<3,double> { +0.767503, +0.162971, +0.61998 };
    auto coord = Vector<3,double>{ 3.13, 2.2, 1.7 };

    auto orientation = CGM_XYZ::orientationMatrix(x,y,z);

    auto expect = Vector<3,double> {1.103751,1.325136,3.814793};
    auto result = CGM_XYZ::localToGlobal(coord, orientation);

    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Mat3WithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto x = Vector<3,double> { +0.559270, +0.302442, -0.77184 };
    auto y = Vector<3,double> { -0.313298, +0.939132, +0.14098 };
    auto z = Vector<3,double> { +0.767503, +0.162971, +0.61998 };
    auto p = Vector<3,double> { -1.200000, -0.600000, 4.400000 };
    auto coord = Vector<3,double>{ 3.13, 2.2, 1.7 };

    auto orientation = CGM_XYZ::orientationMatrix(x,y,z);

    {
        auto result = CGM_XYZ::localToGlobal<POINT>(coord, orientation, p);
        auto expect = Vector<3,double> {-0.096249, +0.725136, +8.214793};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToGlobal<DIRECTION>(coord, orientation, p);
        auto expect = Vector<3,double> {+1.103751, +1.325136, +3.814793};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Mat4)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto x = Vector<3,double> { +0.559270, +0.302442, -0.77184 };
    auto y = Vector<3,double> { -0.313298, +0.939132, +0.14098 };
    auto z = Vector<3,double> { +0.767503, +0.162971, +0.61998 };
    auto p = Vector<3,double> { -1.200000, -0.600000, 4.400000 };
    auto coord = Vector<3,double> { 3.13, 2.2, 1.7 };

    auto basis = CGM_XYZ::packBasis(x,y,z,p);

    {
        auto result = CGM_XYZ::localToGlobal<POINT>(coord, basis);
        auto expect = Vector<3,double> {-0.096249, +0.725136, +8.214793};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToGlobal<DIRECTION>(coord, basis);
        auto expect = Vector<3,double> {+1.103751, +1.325136, +3.814793};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_Quat)
{
    auto orientation = Quaternion<double> {-0.006227,0.435855,0.174342,0.882948};
    auto coord = Vector<3,double> { 3.13, 2.2, 1.7 };

    auto result = CGM_XYZ::localToGlobal(coord, orientation);
    auto expect = Vector<3,double> {+1.103751, +1.325136, +3.814793};

    ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToGlobal_QuatWithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto orientation = Quaternion<double> {-0.006227,0.435855,0.174342,0.882948};
    auto position = Vector<3,double> { -1.200000, -0.600000, 4.400000 };
    auto coord = Vector<3,double> { 3.13, 2.2, 1.7 };

    {
        auto result = CGM_XYZ::localToGlobal<POINT>(coord, orientation, position);
        auto expect = Vector<3,double> {-0.096249, +0.725136, +8.214793};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }

    {
        auto result = CGM_XYZ::localToGlobal<DIRECTION>(coord, orientation, position);
        auto expect = Vector<3,double> {+1.103751, +1.325136, +3.814793};

        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
}
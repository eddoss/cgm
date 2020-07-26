

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

using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat3)
{
    auto a_x = Vector<3,double> { +0.980518, -0.102133, -0.167786 };
    auto a_y = Vector<3,double> { +0.097025, +0.994541, -0.038389 };
    auto a_z = Vector<3,double> { +0.170791, +0.021362, +0.985075 };

    auto b_x = Vector<3,double> { +0.962153, -0.054359, -0.267030 };
    auto b_y = Vector<3,double> { +0.022566, +0.992430, -0.120718 };
    auto b_z = Vector<3,double> { +0.271571, +0.110123, +0.956096 };

    auto a_orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(a_x, a_y, a_z);
    auto b_orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(b_x, b_y, b_z);

    auto a_coord = Vector<3,double> {1.2, 2.2, 1.7};
    auto b_coord = MATH3D_XYZ_NAMESPACE::localToLocal(a_coord, a_orientation, b_orientation);
    auto expect = Vector<3,double> {1.21519, 2.39812, 1.39365};

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(b_coord, expect, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat3WithPos)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto a_x = Vector<3,double> { +0.980518, -0.102133, -0.167786 };
    auto a_y = Vector<3,double> { +0.097025, +0.994541, -0.038389 };
    auto a_z = Vector<3,double> { +0.170791, +0.021362, +0.985075 };

    auto b_x = Vector<3,double> { +0.962153, -0.054359, -0.267030 };
    auto b_y = Vector<3,double> { +0.022566, +0.992430, -0.120718 };
    auto b_z = Vector<3,double> { +0.271571, +0.110123, +0.956096 };

//    auto a_position = Vector<3,double> {3.2, 6.3, 4.1};
    auto b_position = Vector<3,double> {-1.5, 3.0, -0.1};

    auto a_orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(a_x, a_y, a_z);
    auto b_orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(b_x, b_y, b_z);
//    auto a_orientation = Quaternion<double> {0.05004, 0.99500, 0.015013, -0.08507};
//    auto b_orientation = Quaternion<double> {0.01945, 0.98877, 0.058366, -0.13618};
//
//    auto a_basis = MATH3D_XYZ_NAMESPACE::space(a_x, a_y, a_z, a_position);
//    auto b_basis = MATH3D_XYZ_NAMESPACE::space(b_x, b_y, b_z, b_position);

//    auto a_basis = MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3>(a_x, a_y, a_z, a_position);
//    auto b_basis = MATH3D_XYZ_NAMESPACE::Basis<MATH3D_XYZ_NAMESPACE::EBasisBase::Matrix3>(b_x, b_y, b_z, b_position);

    auto a_coord = Vector<3,double> {1.2, 2.2, 1.7};

    {
        auto b_coord = MATH3D_XYZ_NAMESPACE::localToLocal<POINT>(a_coord, a_orientation, b_orientation, b_position);
        auto expect = Vector<3,double> {2.61787, -0.64968, 1.45087};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(b_coord, expect, 0.0001));
    }

    {
        auto b_coord = MATH3D_XYZ_NAMESPACE::localToLocal<DIRECTION>(a_coord, a_orientation, b_orientation, b_position);
        auto expect = Vector<3,double> {1.21519, 2.39812, 1.39365};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(b_coord, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Mat4)
{
    constexpr EVectorRepresentation POINT = EVectorRepresentation::Point;
    constexpr EVectorRepresentation DIRECTION = EVectorRepresentation::Direction;

    auto a_x = Vector<3,double> { +0.980518, -0.102133, -0.167786 };
    auto a_y = Vector<3,double> { +0.097025, +0.994541, -0.038389 };
    auto a_z = Vector<3,double> { +0.170791, +0.021362, +0.985075 };

    auto b_x = Vector<3,double> { +0.962153, -0.054359, -0.267030 };
    auto b_y = Vector<3,double> { +0.022566, +0.992430, -0.120718 };
    auto b_z = Vector<3,double> { +0.271571, +0.110123, +0.956096 };

    auto b_position = Vector<3,double> {-1.5, 3.0, -0.1};

    auto a_orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(a_x, a_y, a_z);
    auto b_basis = MATH3D_XYZ_NAMESPACE::packBasis(b_x, b_y, b_z, b_position);

    auto a_coord = Vector<3,double> {1.2, 2.2, 1.7};

    {
        auto b_coord = MATH3D_XYZ_NAMESPACE::localToLocal<POINT>(a_coord, a_orientation, b_basis);
        auto expect = Vector<3,double> {2.61787, -0.64968, 1.45087};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(b_coord, expect, 0.0001));
    }

    {
        auto b_coord = MATH3D_XYZ_NAMESPACE::localToLocal<DIRECTION>(a_coord, a_orientation, b_basis);
        auto expect = Vector<3,double> {1.21519, 2.39812, 1.39365};

        ASSERT_TRUE(MATH3D_NAMESPACE::equal(b_coord, expect, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Converters, LocalToLocal_Mat3_Quat)
{
    auto a_x = Vector<3,double> { +0.980518, -0.102133, -0.167786 };
    auto a_y = Vector<3,double> { +0.097025, +0.994541, -0.038389 };
    auto a_z = Vector<3,double> { +0.170791, +0.021362, +0.985075 };

    auto a_orientation = MATH3D_XYZ_NAMESPACE::orientationMatrix(a_x, a_y, a_z);
    auto b_orientation = Quaternion<double> {0.01945, 0.98877, 0.058366, -0.13618};
    auto m = MATH3D_XYZ_NAMESPACE::orientationMatrix(Quaternion<double>{0.01945, 0.98877, 0.058366, -0.13618});
//    std::cout << a_orientation << std::endl;
//    std::cout << MATH3D_XYZ_NAMESPACE::orientationMatrix(b_orientation) << std::endl;

    auto a_coord = Vector<3,double> {1.2, 2.2, 1.7};

    auto b_coord = MATH3D_XYZ_NAMESPACE::localToLocal(a_coord, a_orientation, b_orientation);
    auto expect = Vector<3,double> {1.21519, 2.39812, 1.39365};

    ASSERT_TRUE(MATH3D_NAMESPACE::equal(b_coord, expect, 0.0001));
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
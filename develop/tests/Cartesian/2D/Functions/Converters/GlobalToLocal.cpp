

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Core/Functions/Matrix.hpp>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Cartesian/2D/Types/Basis.hpp>
#include <CGM/Cartesian/2D/Functions/Converters.hpp>


using namespace std;
using namespace CGM;

constexpr EVectorRepresentation G2L2DMAT3_POINT = EVectorRepresentation::Point;
constexpr EVectorRepresentation G2L2DMAT3_DIRECTION = EVectorRepresentation::Direction;

static const auto G2L2DMAT2_COORD = Vector<2,double>{ 3.13, 2.2 };
static const auto G2L2DMAT2_EXPEC_PT = Vector<2,double>{ +3.811012, +1.483250 };
static const auto G2L2DMAT2_EXPEC_DIR = Vector<2,double>{ +3.590997, +1.319710 };

static const auto G2L2DMAT2_X = Vector<2,double>{ +0.966269, +0.257534 };
static const auto G2L2DMAT2_Y = Vector<2,double>{ -0.257534, +0.966269 };
static const auto G2L2DMAT2_P = Vector<2,double>{ +0.220015, +0.163540 };
static const auto G2L2DMAT2_MAT2 = CGM_XY::orientationMatrix(G2L2DMAT2_X, G2L2DMAT2_Y);
static const auto G2L2DMAT2_MAT3 = CGM_XY::packBasis(G2L2DMAT2_X, G2L2DMAT2_Y, G2L2DMAT2_P);
static const auto G2L2DMAT2_BASIS_M2 = CGM_XY::Basis<CGM_XY::EBasisBase::Matrix2,double>(G2L2DMAT2_MAT3);
static const auto G2L2DMAT2_BASIS_M3 = CGM_XY::Basis<CGM_XY::EBasisBase::Matrix3,double>(G2L2DMAT2_MAT3);


TEST(Cartesian_2D_Functions_Converters, LocalToGlobal_Mat3_Mat3)
{
    auto result = CGM_XY::localToGlobal(G2L2DMAT2_COORD, G2L2DMAT2_MAT2);
    ASSERT_TRUE(CGM::eq(result, G2L2DMAT2_EXPEC_DIR, 0.0001));
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToGlobal_Mat2_Mat2WithPos)
{
    {
        auto result = CGM_XY::localToGlobal<G2L2DMAT3_POINT>(G2L2DMAT2_COORD, G2L2DMAT2_MAT2, G2L2DMAT2_P);
        ASSERT_TRUE(CGM::eq(result, G2L2DMAT2_EXPEC_PT, 0.0001));
    }

    {
        auto result = CGM_XY::localToGlobal<G2L2DMAT3_DIRECTION>(G2L2DMAT2_COORD, G2L2DMAT2_MAT2, G2L2DMAT2_P);
        ASSERT_TRUE(CGM::eq(result, G2L2DMAT2_EXPEC_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToGlobal_Mat2_Mat3)
{
    {
        auto result = CGM_XY::localToGlobal<G2L2DMAT3_POINT>(G2L2DMAT2_COORD, G2L2DMAT2_MAT3);
        ASSERT_TRUE(CGM::eq(result, G2L2DMAT2_EXPEC_PT, 0.0001));
    }

    {
        auto result = CGM_XY::localToGlobal<G2L2DMAT3_DIRECTION>(G2L2DMAT2_COORD, G2L2DMAT2_MAT3);
        ASSERT_TRUE(CGM::eq(result, G2L2DMAT2_EXPEC_DIR, 0.0001));
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Converters, LocalToGlobal_Mat2_Basis)
{
    {
        auto result_p = CGM_XY::localToGlobal<G2L2DMAT3_POINT>(G2L2DMAT2_COORD, G2L2DMAT2_BASIS_M2);
        auto result_d = CGM_XY::localToGlobal<G2L2DMAT3_DIRECTION>(G2L2DMAT2_COORD, G2L2DMAT2_BASIS_M2);
        ASSERT_TRUE(CGM::eq(result_p, G2L2DMAT2_EXPEC_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, G2L2DMAT2_EXPEC_DIR, 0.0001));
    }

    {
        auto result_p = CGM_XY::localToGlobal<G2L2DMAT3_POINT>(G2L2DMAT2_COORD, G2L2DMAT2_BASIS_M3);
        auto result_d = CGM_XY::localToGlobal<G2L2DMAT3_DIRECTION>(G2L2DMAT2_COORD, G2L2DMAT2_BASIS_M3);
        ASSERT_TRUE(CGM::eq(result_p, G2L2DMAT2_EXPEC_PT, 0.0001));
        ASSERT_TRUE(CGM::eq(result_d, G2L2DMAT2_EXPEC_DIR, 0.0001));
    }
}
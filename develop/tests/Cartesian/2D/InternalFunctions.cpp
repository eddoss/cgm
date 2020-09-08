

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Common.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/detail/Modules/Cartesian/2D/InternalUtils.hpp>


using namespace std;
using namespace CGM;

TEST(Cartesian_2D_InternalFunctions, multiply_matrix3x3_on_vector2)
{
    Vector<2,int> vec {2,3};
    Matrix<3,3,int> mat
    {
        1,3,4,
        4,5,3,
        0,0,1,
    };

    {
        auto res = CGM_XY::detail::multiply_matrix3x3_on_vector2<EVectorRepresentation::Point>(mat, vec);
        auto exp = Vector<2,int> {15,26};
        ASSERT_TRUE(res == exp);
    }

    {
        auto res = CGM_XY::detail::multiply_matrix3x3_on_vector2<EVectorRepresentation::Direction>(mat, vec);
        auto exp = Vector<2,int> {11,23};
        ASSERT_TRUE(res == exp);
    }

}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_InternalFunctions, multiply_vector2_on_matrix3x3)
{
    Vector<2,int> vec {2,3};
    Matrix<3,3,int> mat
    {
        1,4,0,
        3,5,0,
        4,3,1
    };

    {
        auto res = CGM_XY::detail::multiply_vector2_on_matrix3x3<EVectorRepresentation::Point>(vec, mat);
        auto exp = Vector<2,int> {15,26};
        ASSERT_TRUE(res == exp);
    }

    {
        auto res = CGM_XY::detail::multiply_vector2_on_matrix3x3<EVectorRepresentation::Direction>(vec, mat);
        auto exp = Vector<2,int> {11,23};
        ASSERT_TRUE(res == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_InternalFunctions, multiply_matrix2x2_on_matrix3x3_res2x2)
{
    Matrix<2,2,int> expect
    {
        28,  12,
        57,  27
    };

    Matrix<2,2,int> mat2
    {
        4,2,
        3,6
    };

    Matrix<3,3,int> mat3
    {
        3,1,5,
        8,4,2,
        6,5,3
    };

    auto result = CGM_XY::detail::multiply_matrix2x2_on_matrix3x3_res2x2(mat2, mat3);
    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_InternalFunctions, multiply_matrix2x2_on_matrix3x3_res3x3)
{
    Matrix<3,3,int> expect
    {
        28,  12,  24,
        57,  27,  27,
         6,   5,   3
    };

    Matrix<2,2,int> mat2
    {
        4,2,
        3,6
    };

    Matrix<3,3,int> mat3
    {
        3,1,5,
        8,4,2,
        6,5,3
    };

    auto result = CGM_XY::detail::multiply_matrix2x2_on_matrix3x3_res3x3(mat2, mat3);
    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_InternalFunctions, multiply_matrix3x3_on_matrix2x2_res2x2)
{
    Matrix<2,2,int> expect
    {
        15,  12,
        44,  40
    };

    Matrix<2,2,int> mat2
    {
        4,2,
        3,6
    };

    Matrix<3,3,int> mat3
    {
        3,1,5,
        8,4,2,
        6,5,3
    };

    auto result = CGM_XY::detail::multiply_matrix3x3_on_matrix2x2_res2x2(mat3, mat2);
    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_InternalFunctions, multiply_matrix3x3_on_matrix2x2_res3x3)
{
    Matrix<3,3,int> expect
    {
        15,  12,  5,
        44,  40,  2,
        39,  42,  3
    };

    Matrix<2,2,int> mat2
    {
        4,2,
        3,6
    };

    Matrix<3,3,int> mat3
    {
        3,1,5,
        8,4,2,
        6,5,3
    };

    auto result = CGM_XY::detail::multiply_matrix3x3_on_matrix2x2_res3x3(mat3, mat2);
    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_InternalFunctions, fast_inverse_matrix3x3)
{
    Vector<2,double> x {0.798635, -0.601815};
    Vector<2,double> y {0.601815,  0.798635};
    Vector<2,double> p {     0.2,     -0.53};

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    Matrix<3,3,double> input
    {
        x.x, x.y, p.x,
        y.x, y.y, p.y,
        0.0, 0.0, 1.0
    };
#else
    Matrix<3,3,double> input
    {
        x.x, y.x, 0.0,
        x.y, y.y, 0.0,
        p.x, p.y, 1.0
    };
#endif

    auto res = CGM_XY::detail::fast_inverse_matrix3x3(input);
    auto exp = inverseForce(input);

    ASSERT_TRUE(CGM::eq(res, exp, 0.00001));
}
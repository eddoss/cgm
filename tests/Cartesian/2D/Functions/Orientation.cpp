

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Utils/Functions/Numbers.hpp>
#include <CGM/Modules/Utils/Functions/Comparison.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Orientation.hpp>


using namespace std;

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_OrientationAxes, FromXY)
{
    CGM::Vector<2,int> x {1, 2};
    CGM::Vector<2,int> y {4, 5};

    auto axes = CGM_2D::orientationAxes(x, y);

    ASSERT_TRUE(CGM_2D::x(axes) == x);
    ASSERT_TRUE(CGM_2D::y(axes) == y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationAxes, FromMatrix2x2)
{
    CGM::Vector<2,int> in_x {1, 2};
    CGM::Vector<2,int> in_y {4, 5};
    CGM::Vector<2,int> in_z {7, 8};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<2,2,int> mat
    {
        in_x.x, in_y.x,
        in_x.y, in_y.y
    };
#else
    CGM::Matrix<2,2,int> mat
    {
        in_x.x, in_x.y,
        in_y.x, in_y.y
    };
#endif

    auto [x, y] = CGM_2D::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationAxes, FromMatrix3x3)
{
    CGM::Vector<2,int> in_x {1, 2};
    CGM::Vector<2,int> in_y {4, 5};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<3,3,int> mat
    {
        in_x.x, in_y.x, 0,
        in_x.y, in_y.y, 0,
        0, 0, 1
    };
#else
    CGM::Matrix<3,3,int> mat
    {
        in_x.x, in_x.y, 0,
        in_y.x, in_y.y, 0,
        0, 0, 1
    };
#endif

    auto [x, y] = CGM_2D::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
}

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_OrientationMatrix, FromXY)
{
    CGM::Vector<2,int> x {1, 2};
    CGM::Vector<2,int> y {4, 5};

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<2,2,int> expect
    {
        x.x, y.x,
        x.y, y.y
    };
#else
    CGM::Matrix<2,2,int> expect
    {
        x.x, x.y,
        y.x, y.y
    };
#endif

    auto result = CGM_2D::orientationMatrix(x, y);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationMatrix, FromAxesTuple)
{
    CGM::Vector<2,int> x {1, 2};
    CGM::Vector<2,int> y {4, 5};

    auto axes = CGM_2D::orientationAxes(x,y);

#ifdef CGM_CFG_MATRIX_POSTMULT
    CGM::Matrix<2,2,int> expect
    {
        x.x, y.x,
        x.y, y.y
    };
#else
    CGM::Matrix<2,2,int> expect
    {
        x.x, x.y,
        y.x, y.y
    };
#endif

    auto result = CGM_2D::orientationMatrix(axes);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationMatrix, FromMatrix3x3)
{
    int a = 2;
    int b = 3;
    int c = 4;
    int d = 5;

    CGM::Matrix<3,3,int> mat
    {
        a, b, 0,
        c, d, 0,
        0, 0, 1
    };

    CGM::Matrix<2,2,int> expect
    {
        a, b,
        c, d
    };

    auto result = CGM_2D::orientationMatrix(mat);

    ASSERT_TRUE(result == expect);
}
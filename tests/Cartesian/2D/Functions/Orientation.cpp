

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Common.hpp>
#include <CGM/detail/Core/Operators/Vector.hpp>
#include <CGM/detail/Core/Operators/Matrix.hpp>
#include <CGM/detail/Cartesian/2D/Functions/Utils.hpp>
#include <CGM/detail/Cartesian/2D/Functions/Orientation.hpp>


using namespace std;
using namespace CGM;

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_OrientationAxes, FromXY)
{
    Vector<2,int> x {1, 2};
    Vector<2,int> y {4, 5};

    auto axes = CGM_XY::orientationAxes(x, y);

    ASSERT_TRUE(CGM_XY::x(axes) == x);
    ASSERT_TRUE(CGM_XY::y(axes) == y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationAxes, FromMatrix2x2)
{
    Vector<2,int> in_x {1, 2};
    Vector<2,int> in_y {4, 5};
    Vector<2,int> in_z {7, 8};

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    Matrix<2,2,int> mat
    {
        in_x.x, in_x.y,
        in_y.x, in_y.y
    };
#else
    Matrix<2,2,int> mat
    {
        in_x.x, in_y.x,
        in_x.y, in_y.y
    };
#endif

    auto [x, y] = CGM_XY::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationAxes, FromMatrix3x3)
{
    Vector<2,int> in_x {1, 2};
    Vector<2,int> in_y {4, 5};

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    Matrix<3,3,int> mat
    {
        in_x.x, in_x.y, 0,
        in_y.x, in_y.y, 0,
        0, 0, 1
    };
#else
    Matrix<3,3,int> mat
    {
        in_x.x, in_y.x, 0,
        in_x.y, in_y.y, 0,
        0, 0, 1
    };
#endif

    auto [x, y] = CGM_XY::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
}

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_OrientationMatrix, FromXY)
{
    Vector<2,int> x {1, 2};
    Vector<2,int> y {4, 5};

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    Matrix<2,2,int> expect
    {
        x.x, x.y,
        y.x, y.y,
    };
#else
    Matrix<2,2,int> expect
    {
        x.x, y.x,
        x.y, y.y
    };
#endif

    auto result = CGM_XY::orientationMatrix(x, y);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationMatrix, FromAxesTuple)
{
    Vector<2,int> x {1, 2};
    Vector<2,int> y {4, 5};

    auto axes = CGM_XY::orientationAxes(x,y);

#ifdef CGM_MATRIX_POST_MULTIPLICATION
    Matrix<2,2,int> expect
    {
        x.x, x.y,
        y.x, y.y
    };
#else
    Matrix<2,2,int> expect
    {
        x.x, y.x,
        x.y, y.y
    };
#endif

    auto result = CGM_XY::orientationMatrix(axes);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationMatrix, FromMatrix3x3)
{
    Vector<2,int> x {1, 2};
    Vector<2,int> y {4, 5};

    Matrix<3,3,int> mat
    {
        x.x, y.x, 0,
        x.y, y.y, 0,
        0, 0, 1
    };

    Matrix<2,2,int> expect
    {
        x.x, y.x,
        x.y, y.y
    };

    auto result = CGM_XY::orientationMatrix(mat);

    ASSERT_TRUE(result == expect);
}
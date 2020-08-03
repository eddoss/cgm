

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>
#include <Math3D/Cartesian/2D/Functions/Orientation.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

TEST(Cartesian_2D_Functions_OrientationAxes, FromXY)
{
    Vector<2,int> x {1, 2};
    Vector<2,int> y {4, 5};

    auto axes = MATH3D_XY_NAMESPACE::orientationAxes(x, y);

    ASSERT_TRUE(MATH3D_XY_NAMESPACE::x(axes) == x);
    ASSERT_TRUE(MATH3D_XY_NAMESPACE::y(axes) == y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationAxes, FromMatrix2x2)
{
    Vector<2,int> in_x {1, 2};
    Vector<2,int> in_y {4, 5};
    Vector<2,int> in_z {7, 8};

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto [x, y] = MATH3D_XY_NAMESPACE::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationAxes, FromMatrix3x3)
{
    Vector<2,int> in_x {1, 2};
    Vector<2,int> in_y {4, 5};

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto [x, y] = MATH3D_XY_NAMESPACE::orientationAxes(mat);

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

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto result = MATH3D_XY_NAMESPACE::orientationMatrix(x, y);

    ASSERT_TRUE(result == expect);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_OrientationMatrix, FromAxesTuple)
{
    Vector<2,int> x {1, 2};
    Vector<2,int> y {4, 5};

    auto axes = MATH3D_XY_NAMESPACE::orientationAxes(x,y);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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

    auto result = MATH3D_XY_NAMESPACE::orientationMatrix(axes);

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

    auto result = MATH3D_XY_NAMESPACE::orientationMatrix(mat);

    ASSERT_TRUE(result == expect);
}
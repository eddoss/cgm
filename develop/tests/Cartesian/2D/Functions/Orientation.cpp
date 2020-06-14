

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Matrix.hpp>
#include <Math3D/Cartesian/2D/Functions/Utils.hpp>
#include <Math3D/Cartesian/2D/Functions/Orientation.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_2D_Functions_Orientation, Axes_Matrix2)
{
    Vector<2,int> in_x {2, 4};
    Vector<2,int> in_y {3, 5};

    Matrix<2,2,int> mat {};

    MATH3D_XY_NAMESPACE::setX(mat, in_x);
    MATH3D_XY_NAMESPACE::setY(mat, in_y);

    auto [x,y] = MATH3D_XY_NAMESPACE::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Orientation, Axes_Matrix3)
{
    Vector<2,int> in_x {2,4};
    Vector<2,int> in_y {3,5};

    Matrix<3,3,int> mat {};

    MATH3D_XY_NAMESPACE::setX(mat, in_x);
    MATH3D_XY_NAMESPACE::setY(mat, in_y);

    auto [x,y] = MATH3D_XY_NAMESPACE::orientationAxes(mat);

    ASSERT_TRUE(in_x == x);
    ASSERT_TRUE(in_y == y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Orientation, Matrix2_XY)
{
    Vector<2,int> in_x {2,4};
    Vector<2,int> in_y {3,5};

    auto res = MATH3D_XY_NAMESPACE::orientationMatrix(in_x, in_y);
    auto x = MATH3D_XY_NAMESPACE::getX(res);
    auto y = MATH3D_XY_NAMESPACE::getY(res);

    ASSERT_TRUE(x == in_x);
    ASSERT_TRUE(y == in_y);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Orientation, Matrix2_Axes)
{
    Vector<2,int> in_x {2,4};
    Vector<2,int> in_y {3,5};

    auto res = MATH3D_XY_NAMESPACE::orientationMatrix(std::make_tuple(in_x, in_y));
    auto x = MATH3D_XY_NAMESPACE::getX(res);
    auto y = MATH3D_XY_NAMESPACE::getY(res);

    ASSERT_TRUE(x == in_x);
    ASSERT_TRUE(y == in_y);
}
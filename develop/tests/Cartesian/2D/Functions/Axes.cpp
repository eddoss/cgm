

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Cartesian/2D/Functions/Axes.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_2D_Functions_Axes, X)
{
    auto value = MATH3D_XY_NAMESPACE::x<int>();
    auto expec = Vector<2,int>(1,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Axes, Y)
{
    auto value = MATH3D_XY_NAMESPACE::y<int>();
    auto expec = Vector<2,int>(0,1);

    ASSERT_TRUE(value == expec);
}
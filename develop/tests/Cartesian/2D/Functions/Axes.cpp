

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Modules/Core/Operators/Vector.hpp>
#include <CGM/detail/Modules/Cartesian/2D/Functions/Axes.hpp>


using namespace std;
using namespace CGM;

TEST(Cartesian_2D_Functions_Axes, X)
{
    auto value = CGM_XY::x<int>();
    auto expec = Vector<2,int>(1,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Axes, Y)
{
    auto value = CGM_XY::y<int>();
    auto expec = Vector<2,int>(0,1);

    ASSERT_TRUE(value == expec);
}
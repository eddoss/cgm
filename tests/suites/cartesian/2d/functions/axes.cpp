

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/cartesian/2d/functions/axes.hpp>


using namespace std;

TEST(Cartesian_2D_Functions_Axes, X)
{
    auto value = CGM_2D::x<int>();
    auto expec = CGM::Vector<2,int>(1,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_2D_Functions_Axes, Y)
{
    auto value = CGM_2D::y<int>();
    auto expec = CGM::Vector<2,int>(0,1);

    ASSERT_TRUE(value == expec);
}
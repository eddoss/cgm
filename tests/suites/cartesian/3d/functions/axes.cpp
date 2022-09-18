

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/cartesian/3d/functions/axes.hpp>


using namespace std;

TEST(Cartesian_3D_Functions_Axes, X)
{
    auto value = CGM::x<int>();
    auto expec = CGM::Vector<3,int>(1,0,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Y)
{
    auto value = CGM::y<int>();
    auto expec = CGM::Vector<3,int>(0,1,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Z)
{
    auto value = CGM::z<int>();
    auto expec = CGM::Vector<3,int>(0,0,1);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Up)
{
    auto value = CGM::up<int>();

#ifdef CGM_CFG_UP_IS_X
    auto expec = CGM::Vector<3,int>(1,0,0);
#endif
#ifdef CGM_CFG_UP_IS_Y
    auto expec = CGM::Vector<3,int>(0,1,0);
#endif
#ifdef CGM_CFG_UP_IS_Z
    auto expec = CGM::Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Right)
{
    auto value = CGM::right<int>();

#ifdef CGM_CFG_RIGHT_IS_X
    auto expec = CGM::Vector<3,int>(1,0,0);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    auto expec = CGM::Vector<3,int>(0,1,0);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    auto expec = CGM::Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Forward)
{
    auto value = CGM::forward<int>();

#ifdef CGM_CFG_FORWARD_IS_X
    auto expec = CGM::Vector<3,int>(1,0,0);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    auto expec = CGM::Vector<3,int>(0,1,0);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    auto expec = CGM::Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Down)
{
    auto value = CGM::down<int>();

#ifdef CGM_CFG_UP_IS_X
    auto expec = CGM::Vector<3,int>(-1,0,0);
#endif
#ifdef CGM_CFG_UP_IS_Y
    auto expec = CGM::Vector<3,int>(0,-1,0);
#endif
#ifdef CGM_CFG_UP_IS_Z
    auto expec = CGM::Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Left)
{
    auto value = CGM::left<int>();

#ifdef CGM_CFG_RIGHT_IS_X
    auto expec = CGM::Vector<3,int>(-1,0,0);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    auto expec = CGM::Vector<3,int>(0,-1,0);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    auto expec = CGM::Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Backward)
{
    auto value = CGM::backward<int>();

#ifdef CGM_CFG_FORWARD_IS_X
    auto expec = CGM::Vector<3,int>(-1,0,0);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    auto expec = CGM::Vector<3,int>(0,-1,0);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    auto expec = CGM::Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}
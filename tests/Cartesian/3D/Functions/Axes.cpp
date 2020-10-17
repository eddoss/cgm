

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Cartesian/3D/Functions/Axes.hpp>


using namespace std;
using namespace CGM;

TEST(Cartesian_3D_Functions_Axes, X)
{
    auto value = CGM_XYZ::x<int>();
    auto expec = Vector<3,int>(1,0,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Y)
{
    auto value = CGM_XYZ::y<int>();
    auto expec = Vector<3,int>(0,1,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Z)
{
    auto value = CGM_XYZ::z<int>();
    auto expec = Vector<3,int>(0,0,1);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Up)
{
    auto value = CGM_XYZ::up<int>();

#ifdef CGM_CFG_UP_IS_X
    auto expec = Vector<3,int>(1,0,0);
#endif
#ifdef CGM_CFG_UP_IS_Y
    auto expec = Vector<3,int>(0,1,0);
#endif
#ifdef CGM_CFG_UP_IS_Z
    auto expec = Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Right)
{
    auto value = CGM_XYZ::right<int>();

#ifdef CGM_CFG_RIGHT_IS_X
    auto expec = Vector<3,int>(1,0,0);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    auto expec = Vector<3,int>(0,1,0);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    auto expec = Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Forward)
{
    auto value = CGM_XYZ::forward<int>();

#ifdef CGM_CFG_FORWARD_IS_X
    auto expec = Vector<3,int>(1,0,0);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    auto expec = Vector<3,int>(0,1,0);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    auto expec = Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Down)
{
    auto value = CGM_XYZ::down<int>();

#ifdef CGM_CFG_UP_IS_X
    auto expec = Vector<3,int>(-1,0,0);
#endif
#ifdef CGM_CFG_UP_IS_Y
    auto expec = Vector<3,int>(0,-1,0);
#endif
#ifdef CGM_CFG_UP_IS_Z
    auto expec = Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Left)
{
    auto value = CGM_XYZ::left<int>();

#ifdef CGM_CFG_RIGHT_IS_X
    auto expec = Vector<3,int>(-1,0,0);
#endif
#ifdef CGM_CFG_RIGHT_IS_Y
    auto expec = Vector<3,int>(0,-1,0);
#endif
#ifdef CGM_CFG_RIGHT_IS_Z
    auto expec = Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Backward)
{
    auto value = CGM_XYZ::backward<int>();

#ifdef CGM_CFG_FORWARD_IS_X
    auto expec = Vector<3,int>(-1,0,0);
#endif
#ifdef CGM_CFG_FORWARD_IS_Y
    auto expec = Vector<3,int>(0,-1,0);
#endif
#ifdef CGM_CFG_FORWARD_IS_Z
    auto expec = Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}
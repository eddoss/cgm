

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Cartesian/3D/Functions/Axes.hpp>


using namespace std;
using namespace MATH3D_NAMESPACE;

TEST(Cartesian_3D_Functions_Axes, X)
{
    auto value = MATH3D_XYZ_NAMESPACE::x<int>();
    auto expec = Vector<3,int>(1,0,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Y)
{
    auto value = MATH3D_XYZ_NAMESPACE::y<int>();
    auto expec = Vector<3,int>(0,1,0);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Z)
{
    auto value = MATH3D_XYZ_NAMESPACE::z<int>();
    auto expec = Vector<3,int>(0,0,1);

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Up)
{
    auto value = MATH3D_XYZ_NAMESPACE::up<int>();

#ifdef MATH3D_CARTESIAN_UP_X
    auto expec = Vector<3,int>(1,0,0);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    auto expec = Vector<3,int>(0,1,0);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    auto expec = Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Right)
{
    auto value = MATH3D_XYZ_NAMESPACE::right<int>();

#ifdef MATH3D_CARTESIAN_RIGHT_X
    auto expec = Vector<3,int>(1,0,0);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    auto expec = Vector<3,int>(0,1,0);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    auto expec = Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Forward)
{
    auto value = MATH3D_XYZ_NAMESPACE::forward<int>();

#ifdef MATH3D_CARTESIAN_FORWARD_X
    auto expec = Vector<3,int>(1,0,0);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    auto expec = Vector<3,int>(0,1,0);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    auto expec = Vector<3,int>(0,0,1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Down)
{
    auto value = MATH3D_XYZ_NAMESPACE::down<int>();

#ifdef MATH3D_CARTESIAN_UP_X
    auto expec = Vector<3,int>(-1,0,0);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    auto expec = Vector<3,int>(0,-1,0);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    auto expec = Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Left)
{
    auto value = MATH3D_XYZ_NAMESPACE::left<int>();

#ifdef MATH3D_CARTESIAN_RIGHT_X
    auto expec = Vector<3,int>(-1,0,0);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    auto expec = Vector<3,int>(0,-1,0);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    auto expec = Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}

/* --------------------------------------------------------------------------------------- */

TEST(Cartesian_3D_Functions_Axes, Backward)
{
    auto value = MATH3D_XYZ_NAMESPACE::backward<int>();

#ifdef MATH3D_CARTESIAN_FORWARD_X
    auto expec = Vector<3,int>(-1,0,0);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    auto expec = Vector<3,int>(0,-1,0);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    auto expec = Vector<3,int>(0,0,-1);
#endif

    ASSERT_TRUE(value == expec);
}
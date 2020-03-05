

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Vector/Vector.hpp>
#include <Math3D/Core/Structs/Vector/Operators.hpp>


using namespace std;
using Vec2 = Vector<2>;
using Vec3 = Vector<3>;
using Vec4 = Vector<4>;
using Vec5 = Vector<5>;


/* ####################################################################################### */
/* Arithmetic operators: unary minus */
/* ####################################################################################### */

TEST(Vector_DotAndCross, Dot)
{
    Vec3 a {2,3,4};
    Vec3 b {4,5,6};

    ASSERT_EQ(a | b, 47);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_DotAndCross, Cross_2Dx2D)
{
    Vec2 a {2,3};
    Vec2 b {4,5};

    ASSERT_EQ(a ^ b, -2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_DotAndCross, Cross_2Dx3D)
{
    Vec2 a {2,3};
    Vec3 b {4,5,6};
    Vec3 e {18.0f, -12.0f, -2.0f};

    ASSERT_EQ(a ^ b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_DotAndCross, Cross_2Dx4D)
{
    Vec2 a {2,3};
    Vec4 b {4,5,6,7};
    Vec4 e {18, -12, -2, 0};

    ASSERT_TRUE((a ^ b) == e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_DotAndCross, Cross_3Dx2D)
{
    Vec3 a {0,1,0};
    Vec2 b {1,0};
    Vec3 e {0,0,-1};

    ASSERT_EQ(a ^ b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_DotAndCross, Cross_3Dx3D)
{
    Vec3 a {0,1,0};
    Vec3 b {1,0,0};
    Vec3 e {0,0,-1};

    ASSERT_EQ(a ^ b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_DotAndCross, Cross_4Dx2D)
{
    Vec4 a {0,1,0,0};
    Vec2 b {1,0};
    Vec4 e {0,0,-1,0};

    ASSERT_EQ(a ^ b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_DotAndCross, Cross_4Dx3D)
{
    Vec4 a {0,1,0,0};
    Vec3 b {1,0,0};
    Vec4 e {0,0,-1,0};

    ASSERT_EQ(a ^ b, e);
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_DotAndCross, Cross_4Dx4D)
{
    Vec4 a {0,1,0,0};
    Vec4 b {1,0,0,0};
    Vec4 e {0,0,-1,0};

    ASSERT_EQ(a ^ b, e);
}
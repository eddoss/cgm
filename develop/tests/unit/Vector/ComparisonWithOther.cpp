

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Vector/Operators.hpp>


using namespace std;
using Vec2 = Vector<2>;
using Vec3 = Vector<3>;
using Vec4 = Vector<4>;
using Vec5 = Vector<5>;

TEST(Vector_ComparisonWithOther, Equal)
{
    {
        Vec2 vec { 2, 4 };
        Vec2 eql { 2, 4 };
        Vec2 neq { 1, 2 };
        ASSERT_TRUE(vec == eql);
        ASSERT_FALSE(vec == neq);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 6, 9 };
        Vec3 eql { 3, 6, 9 };
        Vec3 neq { 1, 2, 3 };
        ASSERT_TRUE(vec == eql);
        ASSERT_FALSE(vec == neq);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 eql { 2, 4, 6, 8 };
        Vec4 neq { 1, 2, 3, 4 };
        ASSERT_TRUE(vec == eql);
        ASSERT_FALSE(vec == neq);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 eql { 2, 4, 6, 8, 10 };
        Vec5 neq { 1, 2, 3, 4, 5 };
        ASSERT_TRUE(vec == eql);
        ASSERT_FALSE(vec == neq);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, NonEqual)
{
    {
        Vec2 vec { 2, 4 };
        Vec2 eql { 2, 4 };
        Vec2 neq { 1, 2 };
        ASSERT_TRUE(vec != neq);
        ASSERT_FALSE(vec != eql);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 6, 9 };
        Vec3 eql { 3, 6, 9 };
        Vec3 neq { 1, 2, 3 };
        ASSERT_TRUE(vec != neq);
        ASSERT_FALSE(vec != eql);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 eql { 2, 4, 6, 8 };
        Vec4 neq { 1, 2, 3, 4 };
        ASSERT_TRUE(vec != neq);
        ASSERT_FALSE(vec != eql);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 eql { 2, 4, 6, 8, 10 };
        Vec5 neq { 1, 2, 3, 4, 5 };
        ASSERT_TRUE(vec != neq);
        ASSERT_FALSE(vec != eql);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, Less)
{
    {
        Vec2 vec { 2, 4 };
        Vec2 les { 1, 1 };
        Vec2 mor { 2, 4 };
        ASSERT_TRUE(les < vec);
        ASSERT_FALSE(vec < mor);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 6, 9 };
        Vec3 les { 1, 2, 3 };
        Vec3 mor { 3, 6, 9 };
        ASSERT_TRUE(les < vec);
        ASSERT_FALSE(vec < mor);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 les { 1, 2, 3, 4 };
        Vec4 mor { 2, 4, 6, 8 };
        ASSERT_TRUE(les < vec);
        ASSERT_FALSE(vec < mor);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 les { 1, 2, 3, 4, 5 };
        Vec5 mor { 2, 4, 6, 8, 10 };
        ASSERT_TRUE(les < vec);
        ASSERT_FALSE(vec < mor);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, LessOrEqual)
{
    {
        Vec2 vec { 2, 4 };
        Vec2 leq { 2, 4 };
        Vec2 mor { 3, 5 };
        ASSERT_TRUE(vec <= leq);
        ASSERT_FALSE(mor <= vec);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 6, 9 };
        Vec3 leq { 3, 6, 9 };
        Vec3 mor { 4, 7, 10 };
        ASSERT_TRUE(vec <= leq);
        ASSERT_FALSE(mor <= vec);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 leq { 2, 4, 6, 8 };
        Vec4 mor { 3, 5, 7, 9 };
        ASSERT_TRUE(vec <= leq);
        ASSERT_FALSE(mor <= vec);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 leq { 2, 4, 6, 8, 10 };
        Vec5 mor { 3, 5, 7, 9, 11 };
        ASSERT_TRUE(vec <= leq);
        ASSERT_FALSE(mor <= vec);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, Greater)
{
    {
        Vec2 vec { 2, 4 };
        Vec2 les { 1, 1 };
        Vec2 eql { 2, 4 };
        ASSERT_TRUE(vec > les);
        ASSERT_FALSE(vec > eql);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 6, 9 };
        Vec3 les { 1, 2, 3 };
        Vec3 eql { 3, 6, 9 };
        ASSERT_TRUE(vec > les);
        ASSERT_FALSE(vec > eql);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 les { 1, 2, 3, 4 };
        Vec4 eql { 2, 4, 6, 8 };
        ASSERT_TRUE(vec > les);
        ASSERT_FALSE(vec > eql);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 les { 1, 2, 3, 4, 5 };
        Vec5 eql { 2, 4, 6, 8, 10 };
        ASSERT_TRUE(vec > les);
        ASSERT_FALSE(vec > eql);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithOther, GreaterOrEqual)
{
    {
        Vec2 vec { 3, 4 };
        Vec2 meq { 2, 4 };
        Vec2 les (100);
        ASSERT_TRUE(vec >= meq);
        ASSERT_FALSE(vec >= les);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 7, 9 };
        Vec3 meq { 3, 6, 9 };
        Vec3 les (100);
        ASSERT_TRUE(vec >= meq);
        ASSERT_FALSE(vec >= les);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 meq { 2, 4, 6, 8 };
        Vec4 les (100);
        ASSERT_TRUE(vec >= meq);
        ASSERT_FALSE(vec >= les);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 7, 8, 10 };
        Vec5 meq { 2, 4, 6, 8, 10 };
        Vec5 les (100);
        ASSERT_TRUE(vec >= meq);
        ASSERT_FALSE(vec >= les);
    }
}

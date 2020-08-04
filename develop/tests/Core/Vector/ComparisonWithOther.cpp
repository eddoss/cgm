

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>


using namespace CGM;

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

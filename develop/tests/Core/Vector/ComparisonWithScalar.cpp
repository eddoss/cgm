

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>


using namespace std;
using namespace CGM;

using Vec2 = Vector<2>;
using Vec3 = Vector<3>;
using Vec4 = Vector<4>;
using Vec5 = Vector<5>;

TEST(Vector_ComparisonWithScalar, Equal)
{
    {
        Vec2::value_type v = 2;
        Vec2 eql(v);
        Vec2 neq(v + 1);
        ASSERT_TRUE(eql == v);
        ASSERT_FALSE(neq == v);
    }

    /* -------------- */

    {
        Vec3::value_type v = 2;
        Vec3 eql(v);
        Vec3 neq(v + 1);
        ASSERT_TRUE(eql == v);
        ASSERT_FALSE(neq == v);
    }

    /* -------------- */

    {
        Vec4::value_type v = 2;
        Vec4 eql(v);
        Vec4 neq(v + 1);
        ASSERT_TRUE(eql == v);
        ASSERT_FALSE(neq == v);
    }

    /* -------------- */

    {
        Vec5::value_type v = 2;
        Vec5 eql(v);
        Vec5 neq(v + 1);
        ASSERT_TRUE(eql == v);
        ASSERT_FALSE(neq == v);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, NonEqual)
{
    {
        Vec2::value_type v = 2;
        Vec2 eql(v);
        Vec2 neq(v + 1);
        ASSERT_TRUE(neq != v);
        ASSERT_FALSE(eql != v);
    }

    /* -------------- */

    {
        Vec3::value_type v = 2;
        Vec3 eql(v);
        Vec3 neq(v + 1);
        ASSERT_TRUE(neq != v);
        ASSERT_FALSE(eql != v);
    }

    /* -------------- */

    {
        Vec4::value_type v = 2;
        Vec4 eql(v);
        Vec4 neq(v + 1);
        ASSERT_TRUE(neq != v);
        ASSERT_FALSE(eql != v);
    }

    /* -------------- */

    {
        Vec5::value_type v = 2;
        Vec5 eql(v);
        Vec5 neq(v + 1);
        ASSERT_TRUE(neq != v);
        ASSERT_FALSE(eql != v);
    }
}

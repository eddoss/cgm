

#include <iostream>
#include <gtest/gtest.h>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Vector/Operators.hpp>


using namespace std;
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

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, Less)
{
    {
        Vec2::value_type v = 2;
        Vec2 mor(v + 1);
        Vec2 les(v - 1);
        ASSERT_TRUE(les < v);
        ASSERT_FALSE(mor < v);
    }

    /* -------------- */

    {
        Vec3::value_type v = 2;
        Vec3 mor(v + 1);
        Vec3 les(v - 1);
        ASSERT_TRUE(les < v);
        ASSERT_FALSE(mor < v);
    }

    /* -------------- */

    {
        Vec4::value_type v = 2;
        Vec4 mor(v + 1);
        Vec4 les(v - 1);
        ASSERT_TRUE(les < v);
        ASSERT_FALSE(mor < v);
    }

    /* -------------- */

    {
        Vec5::value_type v = 2;
        Vec5 mor(v + 1);
        Vec5 les(v - 1);
        ASSERT_TRUE(les < v);
        ASSERT_FALSE(mor < v);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, LessOrEqual)
{
    {
        Vec2::value_type v = 2;
        Vec2 mor(v + 1);
        Vec2 leq{v, v-1};
        ASSERT_TRUE(leq <= v);
        ASSERT_FALSE(mor <= v);
    }

    /* -------------- */

    {
        Vec3::value_type v = 2;
        Vec3 mor(v + 1);
        Vec3 leq{v, v-1, v};
        ASSERT_TRUE(leq <= v);
        ASSERT_FALSE(mor <= v);
    }

    /* -------------- */

    {
        Vec4::value_type v = 2;
        Vec4 mor(v + 1);
        Vec4 leq{v, v-1, v, v};
        ASSERT_TRUE(leq <= v);
        ASSERT_FALSE(mor <= v);
    }

    /* -------------- */

    {
        Vec5::value_type v = 2;
        Vec5 mor(v + 1);
        Vec5 leq{v, v-1, v, v, v};
        ASSERT_TRUE(leq <= v);
        ASSERT_FALSE(mor <= v);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, Greater)
{
    {
        Vec2::value_type v = 2;
        Vec2 mor(v + 1);
        Vec2 les(v - 1);
        ASSERT_TRUE(mor > v);
        ASSERT_FALSE(les > v);
    }

    /* -------------- */

    {
        Vec3::value_type v = 2;
        Vec3 mor(v + 1);
        Vec3 les(v - 1);
        ASSERT_TRUE(mor > v);
        ASSERT_FALSE(les > v);
    }

    /* -------------- */

    {
        Vec4::value_type v = 2;
        Vec4 mor(v + 1);
        Vec4 les(v - 1);
        ASSERT_TRUE(mor > v);
        ASSERT_FALSE(les > v);
    }

    /* -------------- */

    {
        Vec5::value_type v = 2;
        Vec5 mor(v + 1);
        Vec5 les(v - 1);
        ASSERT_TRUE(mor > v);
        ASSERT_FALSE(les > v);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_ComparisonWithScalar, GreaterOrEqual)
{
    {
        Vec2::value_type v = 2;
        Vec2 les(v - 1);
        Vec2 meq{v, v+1};
        ASSERT_TRUE(meq >= v);
        ASSERT_FALSE(les >= v);
    }

    /* -------------- */

    {
        Vec3::value_type v = 2;
        Vec3 les(v - 1);
        Vec3 meq{v, v+1, v};
        ASSERT_TRUE(meq >= v);
        ASSERT_FALSE(les >= v);
    }

    /* -------------- */

    {
        Vec4::value_type v = 2;
        Vec4 les(v - 1);
        Vec4 meq{v, v+1, v, v};
        ASSERT_TRUE(meq >= v);
        ASSERT_FALSE(les >= v);
    }

    /* -------------- */

    {
        Vec5::value_type v = 2;
        Vec5 les(v - 1);
        Vec5 meq{v, v+1, v, v, v};
        ASSERT_TRUE(meq >= v);
        ASSERT_FALSE(les >= v);
    }
}
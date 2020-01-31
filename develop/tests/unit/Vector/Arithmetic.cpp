

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

TEST(Vector_Arithmetic, UnaryMinus)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp {-1,-2 };
        ASSERT_EQ(-vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp {-1,-2,-3 };
        ASSERT_EQ(-vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp {-1,-2,-3,-4 };
        ASSERT_EQ(-vec, exp);
    }


    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp {-1,-2,-3,-4,-5 };
        ASSERT_EQ(-vec, exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: inplace minus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplaceMinus_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 0, 1 };
        vec -= Vec2::value_type(1);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 0, 1, 2 };
        vec -= Vec3::value_type(1);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 0, 1, 2, 3 };
        vec -= Vec4::value_type(1);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 0, 1, 2, 3, 4 };
        vec -= Vec5::value_type(1);
        ASSERT_EQ(vec, exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplaceMinus_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 1, 1 };
        Vec2 exp { 0, 1 };
        vec -= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 1, 1, 2 };
        Vec3 exp { 0, 1, 1 };
        vec -= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 1, 1, 2, 3 };
        Vec4 exp { 0, 1, 1, 1 };
        vec -= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 1, 1, 2, 3, 4 };
        Vec5 exp { 0, 1, 1, 1, 1 };
        vec -= oth;
        ASSERT_EQ(vec, exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: inplace plus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplacePlus_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 2, 3 };
        vec += Vec2::value_type(1);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 2, 3, 4 };
        vec += Vec3::value_type(1);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 2, 3, 4, 5 };
        vec += Vec4::value_type(1);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 2, 3, 4, 5, 6 };
        vec += Vec5::value_type(1);
        ASSERT_EQ(vec, exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplacePlus_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 1, 1 };
        Vec2 exp { 2, 3 };
        vec += oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 1, 1, 2 };
        Vec3 exp { 2, 3, 5 };
        vec += oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 1, 1, 2, 3 };
        Vec4 exp { 2, 3, 5, 7 };
        vec += oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 1, 1, 2, 3, 4 };
        Vec5 exp { 2, 3, 5, 7, 9 };
        vec += oth;
        ASSERT_EQ(vec, exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: inplace per-component multiplication */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplacePerComponentMultiplication_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 3, 6 };
        vec *= Vec2::value_type(3);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 3, 6, 9 };
        vec *= Vec3::value_type(3);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 2, 4, 6, 8 };
        vec *= Vec4::value_type(2);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 2, 4, 6, 8, 10 };
        vec *= Vec5::value_type(2);
        ASSERT_EQ(vec, exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplacePerComponentMultiplication_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 2, 2 };
        Vec2 exp { 2, 4 };
        vec *= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 2, 3, 2 };
        Vec3 exp { 2, 6, 6 };
        vec *= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 2, 3, 3, 2 };
        Vec4 exp { 2, 6, 9, 8 };
        vec *= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 2, 2, 3, 2, 1 };
        Vec5 exp { 2, 4, 9, 8, 5 };
        vec *= oth;
        ASSERT_EQ(vec, exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: inplace per-component division */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplaceDivision_Scalar)
{
    {
        Vec2 vec { 2, 4 };
        Vec2 exp { 1, 2 };
        vec /= Vec2::value_type(2);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 6, 9 };
        Vec3 exp { 1, 2, 3 };
        vec /= Vec3::value_type(3);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 exp { 1, 2, 3, 4 };
        vec /= Vec4::value_type(2);
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 exp { 1, 2, 3, 4, 5 };
        vec /= Vec5::value_type(2);
        ASSERT_EQ(vec, exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplaceDivision_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 1, 2 };
        Vec2 exp { 1, 1 };
        vec /= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec3 vec { 4, 6, 8 };
        Vec3 oth { 2, 2, 2 };
        Vec3 exp { 2, 3, 4 };
        vec /= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 oth { 2, 2, 2, 2 };
        Vec4 exp { 1, 2, 3, 4 };
        vec /= oth;
        ASSERT_EQ(vec, exp);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 oth { 2, 2, 2, 2, 2 };
        Vec5 exp { 1, 2, 3, 4, 5 };
        vec /= oth;
        ASSERT_EQ(vec, exp);
    }
}
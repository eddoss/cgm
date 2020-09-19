

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Operators/Vector.hpp>


using namespace std;
using namespace CGM;

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
        ASSERT_TRUE(-vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp {-1,-2,-3 };
        ASSERT_TRUE(-vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp {-1,-2,-3,-4 };
        ASSERT_TRUE(-vec == exp);
    }


    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp {-1,-2,-3,-4,-5 };
        ASSERT_TRUE(-vec == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: increment */
/* ####################################################################################### */

TEST(Vector_Arithmetic, PreIncrement)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 2, 3 };
        ASSERT_TRUE(++vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 2, 3, 4 };
        ASSERT_TRUE(++vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 2, 3, 4, 5 };
        ASSERT_TRUE(++vec == exp);
    }


    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 2, 3, 4, 5, 6 };
        ASSERT_TRUE(++vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, PostIncrement)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 1, 2 };
        ASSERT_TRUE(vec++ == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 1, 2, 3 };
        ASSERT_TRUE(vec++ == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 1, 2, 3, 4 };
        ASSERT_TRUE(vec++ == exp);
    }


    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 1, 2, 3, 4, 5 };
        ASSERT_TRUE(vec++ == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: decrement */
/* ####################################################################################### */

TEST(Vector_Arithmetic, PreDecrement)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 0, 1 };
        ASSERT_TRUE(--vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 0, 1, 2 };
        ASSERT_TRUE(--vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 0, 1, 2, 3 };
        ASSERT_TRUE(--vec == exp);
    }


    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 0, 1, 2, 3, 4 };
        ASSERT_TRUE(--vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, PostDecrement)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 1, 2 };
        ASSERT_TRUE(vec-- == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 1, 2, 3 };
        ASSERT_TRUE(vec-- == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 1, 2, 3, 4 };
        ASSERT_TRUE(vec-- == exp);
    }


    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 1, 2, 3, 4, 5 };
        ASSERT_TRUE(vec-- == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: minus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplaceMinus_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 0, 1 };
        vec -= 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 0, 1, 2 };
        vec -= 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 0, 1, 2, 3 };
        vec -= 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 0, 1, 2, 3, 4 };
        vec -= 1;
        ASSERT_TRUE(vec == exp);
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
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 1, 1, 2 };
        Vec3 exp { 0, 1, 1 };
        vec -= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 1, 1, 2, 3 };
        Vec4 exp { 0, 1, 1, 1 };
        vec -= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 1, 1, 2, 3, 4 };
        Vec5 exp { 0, 1, 1, 1, 1 };
        vec -= oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Minus_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 0, 1 };
        vec = vec - 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 0, 1, 2 };
        vec = vec - 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 0, 1, 2, 3 };
        vec = vec - 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 0, 1, 2, 3, 4 };
        vec = vec - 1;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Minus_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 1, 1 };
        Vec2 exp { 0, 1 };
        vec = vec - oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 1, 1, 2 };
        Vec3 exp { 0, 1, 1 };
        vec = vec - oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 1, 1, 2, 3 };
        Vec4 exp { 0, 1, 1, 1 };
        vec = vec - oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 1, 1, 2, 3, 4 };
        Vec5 exp { 0, 1, 1, 1, 1 };
        vec = vec - oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: plus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplacePlus_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 2, 3 };
        vec += 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 2, 3, 4 };
        vec += 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 2, 3, 4, 5 };
        vec += 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 2, 3, 4, 5, 6 };
        vec += 1;
        ASSERT_TRUE(vec == exp);
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
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 1, 1, 2 };
        Vec3 exp { 2, 3, 5 };
        vec += oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 1, 1, 2, 3 };
        Vec4 exp { 2, 3, 5, 7 };
        vec += oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 1, 1, 2, 3, 4 };
        Vec5 exp { 2, 3, 5, 7, 9 };
        vec += oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Plus_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 2, 3 };
        vec = vec + 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 2, 3, 4 };
        vec = vec + 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 2, 3, 4, 5 };
        vec = vec + 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 2, 3, 4, 5, 6 };
        vec = vec + 1;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Plus_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 1, 1 };
        Vec2 exp { 2, 3 };
        vec = vec + oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 1, 1, 2 };
        Vec3 exp { 2, 3, 5 };
        vec = vec + oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 1, 1, 2, 3 };
        Vec4 exp { 2, 3, 5, 7 };
        vec = vec + oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 1, 1, 2, 3, 4 };
        Vec5 exp { 2, 3, 5, 7, 9 };
        vec = vec + oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: inplace per-component multiplication */
/* ####################################################################################### */

TEST(Vector_Arithmetic, Inplace_ComponentWise_Multiplication_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 3, 6 };
        vec *= 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 3, 6, 9 };
        vec *= 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 2, 4, 6, 8 };
        vec *= 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 2, 4, 6, 8, 10 };
        vec *= 2;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Inplace_ComponentWise_Multiplication_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 2, 2 };
        Vec2 exp { 2, 4 };
        vec *= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 2, 3, 2 };
        Vec3 exp { 2, 6, 6 };
        vec *= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 2, 3, 3, 2 };
        Vec4 exp { 2, 6, 9, 8 };
        vec *= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 2, 2, 3, 2, 1 };
        Vec5 exp { 2, 4, 9, 8, 5 };
        vec *= oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, ComponentWise_Multiplication_Scalar)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 exp { 3, 6 };
        vec = vec * 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 exp { 3, 6, 9 };
        vec = vec * 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 exp { 2, 4, 6, 8 };
        vec = vec * 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 exp { 2, 4, 6, 8, 10 };
        vec = vec * 2;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, ComponentWise_Multiplication_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 2, 2 };
        Vec2 exp { 2, 4 };
        vec = vec * oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 1, 2, 3 };
        Vec3 oth { 2, 3, 2 };
        Vec3 exp { 2, 6, 6 };
        vec = vec * oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 1, 2, 3, 4 };
        Vec4 oth { 2, 3, 3, 2 };
        Vec4 exp { 2, 6, 9, 8 };
        vec = vec * oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 1, 2, 3, 4, 5 };
        Vec5 oth { 2, 2, 3, 2, 1 };
        Vec5 exp { 2, 4, 9, 8, 5 };
        vec = vec * oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: inplace per-component division */
/* ####################################################################################### */

TEST(Vector_Arithmetic, Inplace_ComponentWise_Division_Scalar)
{
    {
        Vec2 vec { 2, 4 };
        Vec2 exp { 1, 2 };
        vec /= 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 6, 9 };
        Vec3 exp { 1, 2, 3 };
        vec /= 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 exp { 1, 2, 3, 4 };
        vec /= 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 exp { 1, 2, 3, 4, 5 };
        vec /= 2;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Inplace_ComponentWise_Division_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 1, 2 };
        Vec2 exp { 1, 1 };
        vec /= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 4, 6, 8 };
        Vec3 oth { 2, 2, 2 };
        Vec3 exp { 2, 3, 4 };
        vec /= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 oth { 2, 2, 2, 2 };
        Vec4 exp { 1, 2, 3, 4 };
        vec /= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 oth { 2, 2, 2, 2, 2 };
        Vec5 exp { 1, 2, 3, 4, 5 };
        vec /= oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, ComponentWise_Division_Scalar)
{
    {
        Vec2 vec { 2, 4 };
        Vec2 exp { 1, 2 };
        vec = vec / 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 3, 6, 9 };
        Vec3 exp { 1, 2, 3 };
        vec = vec / 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 exp { 1, 2, 3, 4 };
        vec = vec / 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 exp { 1, 2, 3, 4, 5 };
        vec = vec / 2;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, ComponentWise_Division_Other)
{
    {
        Vec2 vec { 1, 2 };
        Vec2 oth { 1, 2 };
        Vec2 exp { 1, 1 };
        vec = vec / oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec3 vec { 4, 6, 8 };
        Vec3 oth { 2, 2, 2 };
        Vec3 exp { 2, 3, 4 };
        vec = vec / oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec4 vec { 2, 4, 6, 8 };
        Vec4 oth { 2, 2, 2, 2 };
        Vec4 exp { 1, 2, 3, 4 };
        vec = vec / oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        Vec5 vec { 2, 4, 6, 8, 10 };
        Vec5 oth { 2, 2, 2, 2, 2 };
        Vec5 exp { 1, 2, 3, 4, 5 };
        vec = vec / oth;
        ASSERT_TRUE(vec == exp);
    }
}
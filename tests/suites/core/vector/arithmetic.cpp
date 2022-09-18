

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/operators/vector.hpp>


using namespace std;

/* ####################################################################################### */
/* Arithmetic operators: unary minus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, UnaryMinus)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp {-1,-2 };
        ASSERT_TRUE(-vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp {-1,-2,-3 };
        ASSERT_TRUE(-vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp {-1,-2,-3,-4 };
        ASSERT_TRUE(-vec == exp);
    }


    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp {-1,-2,-3,-4,-5 };
        ASSERT_TRUE(-vec == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: increment */
/* ####################################################################################### */

TEST(Vector_Arithmetic, PreIncrement)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 2, 3 };
        ASSERT_TRUE(++vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 2, 3, 4 };
        ASSERT_TRUE(++vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 2, 3, 4, 5 };
        ASSERT_TRUE(++vec == exp);
    }


    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 2, 3, 4, 5, 6 };
        ASSERT_TRUE(++vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, PostIncrement)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 1, 2 };
        ASSERT_TRUE(vec++ == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 1, 2, 3 };
        ASSERT_TRUE(vec++ == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 1, 2, 3, 4 };
        ASSERT_TRUE(vec++ == exp);
    }


    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 1, 2, 3, 4, 5 };
        ASSERT_TRUE(vec++ == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: decrement */
/* ####################################################################################### */

TEST(Vector_Arithmetic, PreDecrement)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 0, 1 };
        ASSERT_TRUE(--vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 0, 1, 2 };
        ASSERT_TRUE(--vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 0, 1, 2, 3 };
        ASSERT_TRUE(--vec == exp);
    }


    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 0, 1, 2, 3, 4 };
        ASSERT_TRUE(--vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, PostDecrement)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 1, 2 };
        ASSERT_TRUE(vec-- == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 1, 2, 3 };
        ASSERT_TRUE(vec-- == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 1, 2, 3, 4 };
        ASSERT_TRUE(vec-- == exp);
    }


    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 1, 2, 3, 4, 5 };
        ASSERT_TRUE(vec-- == exp);
    }
}

/* ####################################################################################### */
/* Arithmetic operators: minus */
/* ####################################################################################### */

TEST(Vector_Arithmetic, InplaceMinus_Scalar)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 0, 1 };
        vec -= 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 0, 1, 2 };
        vec -= 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 0, 1, 2, 3 };
        vec -= 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 0, 1, 2, 3, 4 };
        vec -= 1;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplaceMinus_Other)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> oth { 1, 1 };
        CGM::Vector<2,int> exp { 0, 1 };
        vec -= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> oth { 1, 1, 2 };
        CGM::Vector<3,int> exp { 0, 1, 1 };
        vec -= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> oth { 1, 1, 2, 3 };
        CGM::Vector<4,int> exp { 0, 1, 1, 1 };
        vec -= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> oth { 1, 1, 2, 3, 4 };
        CGM::Vector<5,int> exp { 0, 1, 1, 1, 1 };
        vec -= oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Minus_Scalar)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 0, 1 };
        vec = vec - 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 0, 1, 2 };
        vec = vec - 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 0, 1, 2, 3 };
        vec = vec - 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 0, 1, 2, 3, 4 };
        vec = vec - 1;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Minus_Other)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> oth { 1, 1 };
        CGM::Vector<2,int> exp { 0, 1 };
        vec = vec - oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> oth { 1, 1, 2 };
        CGM::Vector<3,int> exp { 0, 1, 1 };
        vec = vec - oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> oth { 1, 1, 2, 3 };
        CGM::Vector<4,int> exp { 0, 1, 1, 1 };
        vec = vec - oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> oth { 1, 1, 2, 3, 4 };
        CGM::Vector<5,int> exp { 0, 1, 1, 1, 1 };
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
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 2, 3 };
        vec += 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 2, 3, 4 };
        vec += 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 2, 3, 4, 5 };
        vec += 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 2, 3, 4, 5, 6 };
        vec += 1;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, InplacePlus_Other)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> oth { 1, 1 };
        CGM::Vector<2,int> exp { 2, 3 };
        vec += oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> oth { 1, 1, 2 };
        CGM::Vector<3,int> exp { 2, 3, 5 };
        vec += oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> oth { 1, 1, 2, 3 };
        CGM::Vector<4,int> exp { 2, 3, 5, 7 };
        vec += oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> oth { 1, 1, 2, 3, 4 };
        CGM::Vector<5,int> exp { 2, 3, 5, 7, 9 };
        vec += oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Plus_Scalar)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 2, 3 };
        vec = vec + 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 2, 3, 4 };
        vec = vec + 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 2, 3, 4, 5 };
        vec = vec + 1;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 2, 3, 4, 5, 6 };
        vec = vec + 1;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Plus_Other)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> oth { 1, 1 };
        CGM::Vector<2,int> exp { 2, 3 };
        vec = vec + oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> oth { 1, 1, 2 };
        CGM::Vector<3,int> exp { 2, 3, 5 };
        vec = vec + oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> oth { 1, 1, 2, 3 };
        CGM::Vector<4,int> exp { 2, 3, 5, 7 };
        vec = vec + oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> oth { 1, 1, 2, 3, 4 };
        CGM::Vector<5,int> exp { 2, 3, 5, 7, 9 };
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
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 3, 6 };
        vec *= 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 3, 6, 9 };
        vec *= 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 2, 4, 6, 8 };
        vec *= 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 2, 4, 6, 8, 10 };
        vec *= 2;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Inplace_ComponentWise_Multiplication_Other)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> oth { 2, 2 };
        CGM::Vector<2,int> exp { 2, 4 };
        vec *= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> oth { 2, 3, 2 };
        CGM::Vector<3,int> exp { 2, 6, 6 };
        vec *= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> oth { 2, 3, 3, 2 };
        CGM::Vector<4,int> exp { 2, 6, 9, 8 };
        vec *= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> oth { 2, 2, 3, 2, 1 };
        CGM::Vector<5,int> exp { 2, 4, 9, 8, 5 };
        vec *= oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, ComponentWise_Multiplication_Scalar)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> exp { 3, 6 };
        vec = vec * 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> exp { 3, 6, 9 };
        vec = vec * 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> exp { 2, 4, 6, 8 };
        vec = vec * 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> exp { 2, 4, 6, 8, 10 };
        vec = vec * 2;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, ComponentWise_Multiplication_Other)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> oth { 2, 2 };
        CGM::Vector<2,int> exp { 2, 4 };
        vec = vec * oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 1, 2, 3 };
        CGM::Vector<3,int> oth { 2, 3, 2 };
        CGM::Vector<3,int> exp { 2, 6, 6 };
        vec = vec * oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 1, 2, 3, 4 };
        CGM::Vector<4,int> oth { 2, 3, 3, 2 };
        CGM::Vector<4,int> exp { 2, 6, 9, 8 };
        vec = vec * oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 1, 2, 3, 4, 5 };
        CGM::Vector<5,int> oth { 2, 2, 3, 2, 1 };
        CGM::Vector<5,int> exp { 2, 4, 9, 8, 5 };
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
        CGM::Vector<2,int> vec { 2, 4 };
        CGM::Vector<2,int> exp { 1, 2 };
        vec /= 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 3, 6, 9 };
        CGM::Vector<3,int> exp { 1, 2, 3 };
        vec /= 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 2, 4, 6, 8 };
        CGM::Vector<4,int> exp { 1, 2, 3, 4 };
        vec /= 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 2, 4, 6, 8, 10 };
        CGM::Vector<5,int> exp { 1, 2, 3, 4, 5 };
        vec /= 2;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, Inplace_ComponentWise_Division_Other)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> oth { 1, 2 };
        CGM::Vector<2,int> exp { 1, 1 };
        vec /= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 4, 6, 8 };
        CGM::Vector<3,int> oth { 2, 2, 2 };
        CGM::Vector<3,int> exp { 2, 3, 4 };
        vec /= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 2, 4, 6, 8 };
        CGM::Vector<4,int> oth { 2, 2, 2, 2 };
        CGM::Vector<4,int> exp { 1, 2, 3, 4 };
        vec /= oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 2, 4, 6, 8, 10 };
        CGM::Vector<5,int> oth { 2, 2, 2, 2, 2 };
        CGM::Vector<5,int> exp { 1, 2, 3, 4, 5 };
        vec /= oth;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, ComponentWise_Division_Scalar)
{
    {
        CGM::Vector<2,int> vec { 2, 4 };
        CGM::Vector<2,int> exp { 1, 2 };
        vec = vec / 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 3, 6, 9 };
        CGM::Vector<3,int> exp { 1, 2, 3 };
        vec = vec / 3;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 2, 4, 6, 8 };
        CGM::Vector<4,int> exp { 1, 2, 3, 4 };
        vec = vec / 2;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 2, 4, 6, 8, 10 };
        CGM::Vector<5,int> exp { 1, 2, 3, 4, 5 };
        vec = vec / 2;
        ASSERT_TRUE(vec == exp);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Vector_Arithmetic, ComponentWise_Division_Other)
{
    {
        CGM::Vector<2,int> vec { 1, 2 };
        CGM::Vector<2,int> oth { 1, 2 };
        CGM::Vector<2,int> exp { 1, 1 };
        vec = vec / oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<3,int> vec { 4, 6, 8 };
        CGM::Vector<3,int> oth { 2, 2, 2 };
        CGM::Vector<3,int> exp { 2, 3, 4 };
        vec = vec / oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<4,int> vec { 2, 4, 6, 8 };
        CGM::Vector<4,int> oth { 2, 2, 2, 2 };
        CGM::Vector<4,int> exp { 1, 2, 3, 4 };
        vec = vec / oth;
        ASSERT_TRUE(vec == exp);
    }

    /* -------------- */

    {
        CGM::Vector<5,int> vec { 2, 4, 6, 8, 10 };
        CGM::Vector<5,int> oth { 2, 2, 2, 2, 2 };
        CGM::Vector<5,int> exp { 1, 2, 3, 4, 5 };
        vec = vec / oth;
        ASSERT_TRUE(vec == exp);
    }
}
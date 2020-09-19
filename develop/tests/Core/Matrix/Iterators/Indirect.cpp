

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>


using namespace CGM;

using namespace std;
using Mat22 = Matrix<2,2,int>;
using Mat23 = Matrix<2,3,int>;
using Mat24 = Matrix<2,4,int>;
using Mat32 = Matrix<3,2,int>;
using Mat33 = Matrix<3,3,int>;
using Mat34 = Matrix<3,4,int>;
using Mat42 = Matrix<4,2,int>;
using Mat43 = Matrix<4,3,int>;
using Mat44 = Matrix<4,4,int>;
using Mat55 = Matrix<5,5,int>;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_IndirectIterator, Plus)
{
    Mat34 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
    };

    auto it0 = input.beginIndirect() + 0;
    auto it1 = input.beginIndirect() + 1;
    auto it2 = input.beginIndirect() + 2;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(*it0 == 11);
        ASSERT_TRUE(*it1 == 21);
        ASSERT_TRUE(*it2 == 31);
    #else
        ASSERT_TRUE(*it0 == 11);
        ASSERT_TRUE(*it1 == 12);
        ASSERT_TRUE(*it2 == 13);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Minus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.endIndirect() - 1;
    auto it1 = input.endIndirect() - 2;
    auto it2 = input.endIndirect() - 3;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(*it0 == 9);
        ASSERT_TRUE(*it1 == 6);
        ASSERT_TRUE(*it2 == 3);
    #else
        ASSERT_TRUE(*it0 == 9);
        ASSERT_TRUE(*it1 == 8);
        ASSERT_TRUE(*it2 == 7);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, PreIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginIndirect();

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(*(++it) == 4);
        ASSERT_TRUE(*(++it) == 7);
    #else
        ASSERT_TRUE(*(++it) == 2);
        ASSERT_TRUE(*(++it) == 3);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, PostIncrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginIndirect();

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(*(it++) == 1);
        ASSERT_TRUE(*(it++) == 4);
    #else
        ASSERT_TRUE(*(it++) == 1);
        ASSERT_TRUE(*(it++) == 2);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, PreDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endIndirect();

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(*(--it) == 9);
        ASSERT_TRUE(*(--it) == 6);
    #else
        ASSERT_TRUE(*(--it) == 9);
        ASSERT_TRUE(*(--it) == 8);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, PostDecrement)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endIndirect();
    it--;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(*(it--) == 9);
        ASSERT_TRUE(*(it--) == 6);
    #else
        ASSERT_TRUE(*(it--) == 9);
        ASSERT_TRUE(*(it--) == 8);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, RowsColumns_FirstComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginIndirect()};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, RowsColumns_MidComponent)
{
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.beginIndirect() + 5};

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(*it == 7);
        ASSERT_TRUE(it.row() == 1);
        ASSERT_TRUE(it.column() == 2);
    #else
        ASSERT_TRUE(*it == 6);
        ASSERT_TRUE(it.row() == 1);
        ASSERT_TRUE(it.column() == 1);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, RowsColumns_LastComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginIndirect() + Mat33::size-1};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Difference)
{
    Mat34 input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
    };

    auto a {input.beginIndirect()};
    auto b {input.beginIndirect() + 4};

    ASSERT_TRUE(b-a == 4);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Comparison_Equal)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginIndirect();
    auto same_a = input.beginIndirect();
    auto b = input.beginIndirect() + 1;

    ASSERT_TRUE(a == same_a);
    ASSERT_FALSE(a == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Comparison_NotEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginIndirect();
    auto same_a = input.beginIndirect();
    auto b = input.beginIndirect() + 1;

    ASSERT_TRUE(a != b);
    ASSERT_FALSE(a != same_a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Comparison_Less)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginIndirect();
    auto b = input.beginIndirect() + 1;

    ASSERT_TRUE(a < b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Comparison_LessOrEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginIndirect();
    auto b = input.beginIndirect();

    ASSERT_TRUE(a <= b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Comparison_Greater)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginIndirect();
    auto b = input.beginIndirect() + 1;

    ASSERT_TRUE(b > a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Comparison_GreaterOrEqual)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.beginIndirect();
    auto b = input.beginIndirect();

    ASSERT_TRUE(b >= a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Reverse)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginIndirect();
    auto b = input.rbeginIndirect() + 1;
    auto c = input.rbeginIndirect() + 2;
    auto d = input.rbeginIndirect() + 3;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(*a == 5);
        ASSERT_TRUE(*b == 2);
        ASSERT_TRUE(*c == 4);
        ASSERT_TRUE(*d == 1);
    #else
        ASSERT_TRUE(*a == 5);
        ASSERT_TRUE(*b == 4);
        ASSERT_TRUE(*c == 2);
        ASSERT_TRUE(*d == 1);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Reverse_Differece)
{
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginIndirect();
    auto b = input.rbeginIndirect() + 2;

    ASSERT_TRUE(a - b == -2);
    ASSERT_TRUE(b - a == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Reverse_RowsColumns_FirstComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginIndirect()};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Reverse_RowsColumns_MidComponent)
{
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.rbeginIndirect() + 5};

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        ASSERT_TRUE(it.row() == 0);
        ASSERT_TRUE(it.column() == 1);
    #else
        ASSERT_TRUE(it.row() == 0);
        ASSERT_TRUE(it.column() == 2);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Reverse_RowsColumns_LastComponent)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginIndirect() + Mat33::size-1};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_IndirectIterator, Exception_Dereference)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endIndirect();
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_PreIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.endIndirect();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_PostIncrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endIndirect()++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_PlusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endIndirect();
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_Plus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endIndirect();
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_PreDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.beginIndirect();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_PostDecrement)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginIndirect()--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_MinusEqual)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginIndirect();
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_Minus)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.beginIndirect();
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_Row)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endIndirect();
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Exception_Column)
{
    Mat32 input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.endIndirect();
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get column from matrix iterator (out of range).");
    }
}

#endif
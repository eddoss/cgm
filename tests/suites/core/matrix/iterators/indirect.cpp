

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/matrix.hpp>


using namespace std;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_IndirectIterator, Plus)
{
    CGM::Matrix<3,4,int> input
    {
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
    };

    auto it0 = input.beginIndirect() + 0;
    auto it1 = input.beginIndirect() + 1;
    auto it2 = input.beginIndirect() + 2;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*it0 == 11);
        ASSERT_TRUE(*it1 == 21);
        ASSERT_TRUE(*it2 == 31);
    #elif CGM_CFG_COLUMN_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*it0 == 11);
        ASSERT_TRUE(*it1 == 12);
        ASSERT_TRUE(*it2 == 13);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Minus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.endIndirect() - 1;
    auto it1 = input.endIndirect() - 2;
    auto it2 = input.endIndirect() - 3;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
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
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginIndirect();

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
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
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.beginIndirect();

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
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
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endIndirect();

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
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
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.endIndirect();
    it--;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
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
    CGM::Matrix<3,3,int> input
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
    CGM::Matrix<2,4,int> input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.beginIndirect() + 5};

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
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
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.beginIndirect() + CGM::Matrix<3,3,int>::count - 1};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_IndirectIterator, Difference)
{
    CGM::Matrix<3,4,int> input
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
    CGM::Matrix<2,2,int> input
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
    CGM::Matrix<2,2,int> input
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
    CGM::Matrix<2,2,int> input
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
    CGM::Matrix<2,2,int> input
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
    CGM::Matrix<2,2,int> input
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
    CGM::Matrix<2,2,int> input
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
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbeginIndirect();
    auto b = input.rbeginIndirect() + 1;
    auto c = input.rbeginIndirect() + 2;
    auto d = input.rbeginIndirect() + 3;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
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
    CGM::Matrix<2,2,int> input
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
    CGM::Matrix<3,3,int> input
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
    CGM::Matrix<2,4,int> input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.rbeginIndirect() + 5};

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
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
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbeginIndirect() + CGM::Matrix<3,3,int>::count - 1};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_IndirectIterator, Exception_Dereference)
{
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
    CGM::Matrix<3,2,int> input
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
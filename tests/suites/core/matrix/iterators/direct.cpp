

#include <iostream>
#include <gtest/gtest.h>
#include <cgm/modules/core/types/matrix.hpp>


using namespace std;

/* ####################################################################################### */
/* Default iterators */
/* ####################################################################################### */

TEST(Matrix_DirectIterator, Plus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.begin() + 1;
    auto it1 = input.begin() + 2;
    auto it2 = input.begin() + 3;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*it0 == 2);
        ASSERT_TRUE(*it1 == 3);
        ASSERT_TRUE(*it2 == 4);
    #else
        ASSERT_TRUE(*it0 == 4);
        ASSERT_TRUE(*it1 == 7);
        ASSERT_TRUE(*it2 == 2);
    #endif

}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Minus)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.end() - 1;
    auto it1 = input.end() - 2;
    auto it2 = input.end() - 3;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*it0 == 9);
        ASSERT_TRUE(*it1 == 8);
        ASSERT_TRUE(*it2 == 7);
    #else
        ASSERT_TRUE(*it0 == 9);
        ASSERT_TRUE(*it1 == 6);
        ASSERT_TRUE(*it2 == 3);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, PreIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.begin();

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*(++it) == 2);
        ASSERT_TRUE(*(++it) == 3);
    #else
        ASSERT_TRUE(*(++it) == 4);
        ASSERT_TRUE(*(++it) == 7);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, PostIncrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.begin();
    it++;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*(it++) == 2);
        ASSERT_TRUE(*(it++) == 3);
    #else
        ASSERT_TRUE(*(it++) == 4);
        ASSERT_TRUE(*(it++) == 7);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, PreDecrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.end();

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*(--it) == 9);
        ASSERT_TRUE(*(--it) == 8);
    #else
        ASSERT_TRUE(*(--it) == 9);
        ASSERT_TRUE(*(--it) == 6);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, PostDecrement)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.end();
    it--;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*(it--) == 9);
        ASSERT_TRUE(*(it--) == 8);
    #else
        ASSERT_TRUE(*(it--) == 9);
        ASSERT_TRUE(*(it--) == 6);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, RowsColumns_FirstComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.begin()};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, RowsColumns_MidComponent)
{
    CGM::Matrix<2,4,int> input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.begin() + 5};

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(it.row() == 1);
        ASSERT_TRUE(it.column() == 1);
    #else
        ASSERT_TRUE(it.row() == 1);
        ASSERT_TRUE(it.column() == 2);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, RowsColumns_LastComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.begin() + CGM::Matrix<3,3,int>::count - 1};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Difference)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto a {input.begin()};
    auto b {input.begin() + 3};

    ASSERT_TRUE(b-a == 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Comparison_Equal)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.begin();
    auto same_a = input.begin();
    auto b = input.begin() + 1;

    ASSERT_TRUE(a == same_a);
    ASSERT_FALSE(a == b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Comparison_NotEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.begin();
    auto same_a = input.begin();
    auto b = input.begin() + 1;

    ASSERT_TRUE(a != b);
    ASSERT_FALSE(a != same_a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Comparison_Less)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.begin();
    auto b = input.begin() + 1;

    ASSERT_TRUE(a < b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Comparison_LessOrEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.begin();
    auto b = input.begin();

    ASSERT_TRUE(a <= b);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Comparison_Greater)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.begin();
    auto b = input.begin() + 1;

    ASSERT_TRUE(b > a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Comparison_GreaterOrEqual)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.begin();
    auto b = input.begin();

    ASSERT_TRUE(b >= a);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Reverse)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbegin();
    auto b = input.rbegin() + 1;
    auto c = input.rbegin() + 2;
    auto d = input.rbegin() + 3;

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(*a == 5);
        ASSERT_TRUE(*b == 4);
        ASSERT_TRUE(*c == 2);
        ASSERT_TRUE(*d == 1);
    #else
        ASSERT_TRUE(*a == 5);
        ASSERT_TRUE(*b == 2);
        ASSERT_TRUE(*c == 4);
        ASSERT_TRUE(*d == 1);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Reverse_Differece)
{
    CGM::Matrix<2,2,int> input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbegin();
    auto b = input.rbegin() + 2;

    ASSERT_TRUE(a - b == -2);
    ASSERT_TRUE(b - a == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Reverse_RowsColumns_FirstComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbegin()};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Reverse_RowsColumns_MidComponent)
{
    CGM::Matrix<2,4,int> input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.rbegin() + 5};

    #ifdef CGM_CFG_ROW_WISE_MATRIX_LAYOUT
        ASSERT_TRUE(it.row() == 0);
        ASSERT_TRUE(it.column() == 2);
    #else
        ASSERT_TRUE(it.row() == 0);
        ASSERT_TRUE(it.column() == 1);
    #endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Reverse_RowsColumns_LastComponent)
{
    CGM::Matrix<3,3,int> input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbegin() + CGM::Matrix<3,3,int>::count - 1};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_DirectIterator, Exception_Dereference)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.end();
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't dereference out of range matrix iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_PreIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = ++input.end();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_PostIncrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.end()++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-increment matrix iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_PlusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.end();
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_Plus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.end();
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_PreDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = --input.begin();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_PostDecrement)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.begin()--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't pre-decrement matrix iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_MinusEqual)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.begin();
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_Minus)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.begin();
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't move matrix iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_Row)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.end();
        auto val = it.row();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get row from matrix iterator (out of range).");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Exception_Column)
{
    CGM::Matrix<3,2,int> input
    {
        1, 2,
        4, 5,
        7, 8
    };

    try
    {
        auto it = input.end();
        auto val = it.column();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(CGM) can't get column from matrix iterator (out of range).");
    }
}

#endif
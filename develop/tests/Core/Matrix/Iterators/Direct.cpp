

#include <iostream>
#include <gtest/gtest.h>
#include <CGM/Modules/Core/Types/Matrix.hpp>


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

TEST(Matrix_DirectIterator, Plus)
{
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.begin() + 1;
    auto it1 = input.begin() + 2;
    auto it2 = input.begin() + 3;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it0 = input.end() - 1;
    auto it1 = input.end() - 2;
    auto it2 = input.end() - 3;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.begin();

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.begin();
    it++;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.end();

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it = input.end();
    it--;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat33 input
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
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.begin() + 5};

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.begin() + Mat33::size-1};

    ASSERT_TRUE(it.row() == 2);
    ASSERT_TRUE(it.column() == 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(Matrix_DirectIterator, Difference)
{
    Mat33 input
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
    Mat22 input
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
    Mat22 input
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
    Mat22 input
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
    Mat22 input
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
    Mat22 input
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
    Mat22 input
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
    Mat22 input
    {
        1, 2,
        4, 5
    };

    auto a = input.rbegin();
    auto b = input.rbegin() + 1;
    auto c = input.rbegin() + 2;
    auto d = input.rbegin() + 3;

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat22 input
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
    Mat33 input
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
    Mat24 input
    {
        1, 2, 3, 4,
        5, 6, 7, 8
    };

    auto it {input.rbegin() + 5};

    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
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
    Mat33 input
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    auto it {input.rbegin() + Mat33::size-1};

    ASSERT_TRUE(it.row() == 0);
    ASSERT_TRUE(it.column() == 0);
}

/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(Matrix_DirectIterator, Exception_Dereference)
{
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
    Mat32 input
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
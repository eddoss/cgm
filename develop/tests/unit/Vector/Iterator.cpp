

#include <iostream>
#include <algorithm>
#include <gtest/gtest.h>
#include <Math3D/Core/Structs/Vectors/Vector.hpp>


using namespace std;
using Vec = Vector<3>;

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Comparison, Equal)
{
    Vec input {22, 33, 44};
    auto i {input.begin() + 1};
    auto j {input.begin() + 1};

    ASSERT_EQ(*i, *j);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Comparison, NotEqual)
{
    Vec input {22, 33, 44};
    auto i {input.begin() + 1};
    auto j {input.begin() + 2};

    ASSERT_NE(*i, *j);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Comparison, Greater)
{
    Vec input {22, 33, 44};
    auto i {input.begin() + 1};
    auto j {input.begin() + 2};

    ASSERT_TRUE(j > i);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Comparison, GreaterOrEqual)
{
    Vec input {22, 33, 44};
    auto i {input.begin() + 1};
    auto j {input.begin() + 1};

    ASSERT_TRUE(j >= i);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Comparison, Less)
{
    Vec input {22, 33, 44};
    auto i {input.begin() + 1};
    auto j {input.begin() + 2};

    ASSERT_TRUE(i < j);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Comparison, LessOrEqual)
{
    Vec input {22, 33, 44};
    auto i {input.begin() + 1};
    auto j {input.begin() + 1};

    ASSERT_TRUE(i <= j);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Base, Difference)
{
    Vec input {11, 22, 33};
    auto it_0 = input.cbegin();
    auto it_2 = input.cbegin() + 2;
    auto diff {it_2 - it_0};

    ASSERT_EQ(diff, 2);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Base, Range_Based_ForLoop)
{
    const Vec input {22, 33, 44};
    const Vec expec {22, 33, 44};
    Vec inter;

    size_t i = 0;
    for (auto& val : input)
    {
        inter[i++] = val;
    }
    for (i = 0; i < 3; ++i)
    {
        ASSERT_EQ(expec[i], inter[i]);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Base, ConstIterators_Based_ForLoop)
{
    const Vec input {22, 33, 44};
    const Vec expec {22, 33, 44};

    Vec::const_iterator it_in {input.cbegin()};
    Vec::const_iterator it_ex {expec.cbegin()};

    for (; it_in != input.cend(); ++it_in, ++it_ex)
    {
        ASSERT_EQ(*it_in, *it_ex);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Base, Iterators_Based_ForLoop)
{
    Vec input {22, 33, 44};
    Vec expec {44, 66, 88};

    auto it_in {input.begin()};
    auto it_ex {expec.begin()};

    for (; it_in != input.end(); ++it_in, ++it_ex)
    {
        *it_in *= 2;
        ASSERT_EQ(*it_in, *it_ex);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Base, Reverse)
{
    Vec input {1,2,3};
    Vec expec {3,2,1};

    auto it_in {input.rbegin()};
    auto it_ex {expec.begin()};

    for (; it_in != input.rend(); ++it_in, ++it_ex)
    {
        ASSERT_EQ(*it_in, *it_ex);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_STL, IterSwap)
{
    Vec input {11, 22, 33};
    auto it_0 = input.begin();
    auto it_2 = input.begin() + 2;
    std::iter_swap(it_0, it_2);
    ASSERT_EQ(*it_0, 33);
    ASSERT_EQ(*it_2, 11);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_STL, Advance)
{
    const Vec input {11, 22, 33};
    Vec::const_iterator it {input.begin()};
    std::advance(it, 2);
    ASSERT_EQ(*it, 33);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_STL, Min_Element)
{
    const Vec input {-5, -8, 33};
    auto it = std::min_element(input.begin(), input.end());
    ASSERT_EQ(*it, -8);
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_STL, Max_Element)
{
    const Vec input {33, 5, 20};
    auto it = std::max_element(input.begin(), input.end());
    ASSERT_EQ(*it, 33);
}


/* --------------------------------------------------------------------------------------- */

#ifndef NDEBUG

TEST(VectorIterator_Exceptions, Dereference)
{
    const Vec input {1,2,3};

    try
    {
        auto it = input.end();
        auto val = *it;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't dereference out of range vector iterator.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Exceptions, PreIncrement)
{
    const Vec input {1,2,3};

    try
    {
        auto it = ++input.end();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-increment vector iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Exceptions, PostIncrement)
{
    const Vec input {1,2,3};

    try
    {
        auto it = input.end()++;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-increment vector iterator after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Exceptions, PlusEqual)
{
    const Vec input {1,2,3};

    try
    {
        auto it = input.end();
        it += 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move vector iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Exceptions, Plus)
{
    const Vec input {1,2,3};

    try
    {
        auto it = input.end();
        it = it + 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move vector iterator forward after end.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Exceptions, PreDecrement)
{
    const Vec input {1,2,3};

    try
    {
        auto it = --input.begin();
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't pre-decrement vector iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Exceptions, PostDecrement)
{
    const Vec input {1,2,3};

    try
    {
        auto it = input.begin()--;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't post-decrement vector iterator before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Exceptions, MinusEqual)
{
    const Vec input {1,2,3};

    try
    {
        auto it = input.begin();
        it -= 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move vector iterator backward before begin.");
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(VectorIterator_Exceptions, Minus)
{
    const Vec input {1,2,3};

    try
    {
        auto it = input.begin();
        it = it - 1;
    }
    catch (const std::runtime_error& excep)
    {
        ASSERT_STREQ(excep.what(), "(Math3D) can't move vector iterator backward before begin.");
    }
}

#endif

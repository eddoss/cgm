

#include <iostream>
#include <algorithm>
#include <gtest/gtest.h>
#include <Math3D/Core/RandomAccessIterator.hpp>


using namespace std;

template <typename T, size_t Size>
struct container
{
    T data[Size];

    using iterator          = RandomAccessIterator<T>;
    using const_iterator    = ConstRandomAccessIterator<T>;

   ~container() = default;
    container(){};
    container& operator = (container&& other)       = default;
    container& operator = (const container& other)  = default;
    container(std::initializer_list<T> values)
    {
        for (size_t i = 0; i < Size; ++i)
        {
            data[i] = *(values.begin() + i);
        }
    }

    T& operator [] (size_t i) {return data[i];}
    const T& operator [] (size_t i) const {return data[i];}
    constexpr size_t size() const {return Size;}

    iterator        begin()             {return iterator(data);}
    iterator        end()               {return iterator(data+Size);}
    const_iterator  begin()     const   {return const_iterator(data);}
    const_iterator  end()       const   {return const_iterator(data+Size);}
    const_iterator  cbegin()    const   {return const_iterator(data);}
    const_iterator  cend()      const   {return const_iterator(data+Size);}
};

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Comparison, Equal)
{
    container<int,3> input {22, 33, 44};
    container<int,3>::iterator i {input.begin() + 1};
    container<int,3>::iterator j {input.begin() + 1};

    ASSERT_EQ(*i, *j);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Comparison, NotEqual)
{
    container<int,3> input {22, 33, 44};
    container<int,3>::iterator i {input.begin() + 1};
    container<int,3>::iterator j {input.begin() + 2};

    ASSERT_NE(*i, *j);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Comparison, Greater)
{
    container<int,3> input {22, 33, 44};
    container<int,3>::iterator i {input.begin() + 1};
    container<int,3>::iterator j {input.begin() + 2};

    ASSERT_TRUE(j > i);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Comparison, GreaterOrEqual)
{
    container<int,3> input {22, 33, 44};
    container<int,3>::iterator i {input.begin() + 1};
    container<int,3>::iterator j {input.begin() + 1};

    ASSERT_TRUE(j >= i);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Comparison, Less)
{
    container<int,3> input {22, 33, 44};
    container<int,3>::iterator i {input.begin() + 1};
    container<int,3>::iterator j {input.begin() + 2};

    ASSERT_TRUE(i < j);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Comparison, LessOrEqual)
{
    container<int,3> input {22, 33, 44};
    container<int,3>::iterator i {input.begin() + 1};
    container<int,3>::iterator j {input.begin() + 1};

    ASSERT_TRUE(i <= j);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Base, Difference)
{
    container<int,5> input {11, 22, 33, 44, 55};
    auto it_0 = input.cbegin();
    auto it_3 = input.cbegin() + 3;
    auto diff {it_3 - it_0};

    ASSERT_EQ(diff, 3);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Base, RangeBasedForLoop)
{
    const container<int,3> input {22, 33, 44};
    const container<int,3> expec {22, 33, 44};
    container<int,3> inter;

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

TEST(RandomAccessIterator_Base, ConstIterators_Based_ForLoop)
{
    const container<int,3> input {22, 33, 44};
    const container<int,3> expec {22, 33, 44};

    container<int,3>::const_iterator it_in {input.cbegin()};
    container<int,3>::const_iterator it_ex {expec.cbegin()};

    for (; it_in != input.cend(); ++it_in, ++it_ex)
    {
        ASSERT_EQ(*it_in, *it_ex);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_Base, Iterators_Based_ForLoop)
{
    container<int,3> input {22, 33, 44};
    container<int,3> expec {44, 66, 88};

    container<int,3>::iterator it_in {input.begin()};
    container<int,3>::iterator it_ex {expec.begin()};

    for (; it_in != input.end(); ++it_in, ++it_ex)
    {
        *it_in *= 2;
        ASSERT_EQ(*it_in, *it_ex);
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_STL, IterSwap)
{
    container<int,5> input {11, 22, 33, 5, 20};
    auto it_0 = input.begin();
    auto it_2 = input.begin() + 2;
    std::iter_swap(it_0, it_2);
    ASSERT_EQ(*it_0, 33);
    ASSERT_EQ(*it_2, 11);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_STL, Advance)
{
    const container<int,3> input {11, 22, 33, 44, 55};
    container<int,3>::const_iterator it {input.begin()};
    std::advance(it, 2);
    ASSERT_EQ(*it, 33);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_STL, Min_Element)
{
    const container<int,5> input {11, 22, 33, 5, 20};
    auto it = std::min_element(input.begin(), input.end());
    ASSERT_EQ(*it, 5);
}

/* --------------------------------------------------------------------------------------- */

TEST(RandomAccessIterator_STL, Max_Element)
{
    const container<int,5> input {11, 22, 33, 5, 20};
    auto it = std::max_element(input.begin(), input.end());
    ASSERT_EQ(*it, 33);
}
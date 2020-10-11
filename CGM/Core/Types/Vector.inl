

#include "Vector.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 2D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 2)>>::Vector(T value)
    : x(value)
    , y(value)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 2)>>::Vector(T X, T Y)
    : x(X)
    , y(Y)
{

}

/* ####################################################################################### */
/* Assignment operator */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 2)>>&
Vector <D, T, std::enable_if_t<(D == 2)>>::operator = (typename Vector <D, T, std::enable_if_t<(D == 2)>>::value_type value)
{
    x = value;
    y = value;

    return *this;
}

/* ####################################################################################### */
/* Access */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 2)>>::reference
Vector <D, T, std::enable_if_t<(D == 2)>>::get(EComponent2D component)
{
    return *(&x + static_cast<size_t>(component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 2)>>::const_reference
Vector <D, T, std::enable_if_t<(D == 2)>>::get(EComponent2D component) const
{
    return *(&x + static_cast<size_t>(component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template <EComponent2D Component>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 2)>>::reference
Vector <D, T, std::enable_if_t<(D == 2)>>::get()
{
    return *(&x + static_cast<size_t>(Component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template <EComponent2D Component>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 2)>>::const_reference
Vector <D, T, std::enable_if_t<(D == 2)>>::get() const
{
    return *(&x + static_cast<size_t>(Component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 2)>>::pointer
Vector <D, T, std::enable_if_t<(D == 2)>>::data()
{
    return &x;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 2)>>::const_pointer
Vector <D, T, std::enable_if_t<(D == 2)>>::data() const
{
    return &x;
}

/* ####################################################################################### */
/* Methods */
/* ####################################################################################### */

template<size_t D, typename T>
template<EComponent2D X, EComponent2D Y>
constexpr CGM_FORCEINLINE void
Vector <D, T, std::enable_if_t<(D == 2)>>::swizzle()
{
    if constexpr (X != EComponent2D::X || Y != EComponent2D::Y)
    {
        *this = Vector<D,T>{ get<X>(), get<Y>() };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template<EComponent2D X, EComponent2D Y>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 2)>>
Vector <D, T, std::enable_if_t<(D == 2)>>::swizzled() const
{
    return Vector<D,T>{ get<X>(), get<Y>() };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE void
Vector <D, T, std::enable_if_t<(D == 2)>>::swizzle(EComponent2D X, EComponent2D Y)
{
    *this = Vector<D,T>{ get(X), get(Y) };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 2)>>
Vector <D, T, std::enable_if_t<(D == 2)>>::swizzled(EComponent2D X, EComponent2D Y) const
{
    return Vector<D,T>{ get(X), get(Y) };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 2)>>
Vector <D, T, std::enable_if_t<(D == 2)>>::xy() const
{
    return {y,x};
}

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 3D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 3)>>::Vector(T value)
    : x(value)
    , y(value)
    , z(value)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 3)>>::Vector(T X, T Y, T Z)
    : x(X)
    , y(Y)
    , z(Z)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 3)>>::Vector(const Vector<2,T>& XY, T Z)
    : x(XY.x)
    , y(XY.y)
    , z(Z)
{

}

/* ####################################################################################### */
/* Assignment operator */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 3)>>&
Vector <D, T, std::enable_if_t<(D == 3)>>::operator = (typename Vector <D, T, std::enable_if_t<(D == 3)>>::value_type value)
{
    x = value;
    y = value;
    z = value;

    return *this;
}

/* ####################################################################################### */
/* Access */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 3)>>::reference
Vector <D, T, std::enable_if_t<(D == 3)>>::get(EComponent3D component)
{
    return *(&x + static_cast<size_t>(component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 3)>>::const_reference
Vector <D, T, std::enable_if_t<(D == 3)>>::get(EComponent3D component) const
{
    return *(&x + static_cast<size_t>(component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template <EComponent3D Component>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 3)>>::reference
Vector <D, T, std::enable_if_t<(D == 3)>>::get()
{
    return *(&x + static_cast<size_t>(Component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template <EComponent3D Component>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 3)>>::const_reference
Vector <D, T, std::enable_if_t<(D == 3)>>::get() const
{
    return *(&x + static_cast<size_t>(Component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 3)>>::pointer
Vector <D, T, std::enable_if_t<(D == 3)>>::data()
{
    return &x;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 3)>>::const_pointer
Vector <D, T, std::enable_if_t<(D == 3)>>::data() const
{
    return &x;
}

/* ####################################################################################### */
/* Methods */
/* ####################################################################################### */

template<size_t D, typename T>
template<EComponent3D X, EComponent3D Y, EComponent3D Z>
constexpr CGM_FORCEINLINE void
Vector <D, T, std::enable_if_t<(D == 3)>>::swizzle()
{
    if constexpr (X != EComponent3D::X || Y != EComponent3D::Y || Z != EComponent3D::Z)
    {
        *this = Vector<D,T>{ get<X>(), get<Y>(), get<Z>() };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template<EComponent3D X, EComponent3D Y, EComponent3D Z>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 3)>>
Vector <D, T, std::enable_if_t<(D == 3)>>::swizzled() const
{
    return Vector<D,T>{ get<X>(), get<Y>(), get<Z>() };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE void
Vector <D, T, std::enable_if_t<(D == 3)>>::swizzle(EComponent3D X, EComponent3D Y, EComponent3D Z)
{
    *this = Vector<D,T>{ get(X), get(Y), get(Z) };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 3)>>
Vector <D, T, std::enable_if_t<(D == 3)>>::swizzled(EComponent3D X, EComponent3D Y, EComponent3D Z) const
{
    return Vector<D,T>{ get(X), get(Y), get(Z) };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
Vector <D, T, std::enable_if_t<(D == 3)>>::xy() const
{
    return {x,y};
}

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 4D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 4)>>::Vector(T value)
    : x(value)
    , y(value)
    , z(value)
    , w(value)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 4)>>::Vector(T X, T Y, T Z, T W)
    : x(X)
    , y(Y)
    , z(Z)
    , w(W)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 4)>>::Vector(const Vector<3,T>& XYZ, T W)
    : x(XYZ.x)
    , y(XYZ.y)
    , z(XYZ.z)
    , w(W)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D == 4)>>::Vector(const Vector<2,T>& XY, const Vector<2,T>& ZW)
    : x(XY.x)
    , y(XY.y)
    , z(ZW.z)
    , w(ZW.w)
{

}

/* ####################################################################################### */
/* Assignment operator */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 4)>>&
Vector <D, T, std::enable_if_t<(D == 4)>>::operator = (typename Vector <D, T, std::enable_if_t<(D == 4)>>::value_type value)
{
    x = value;
    y = value;
    z = value;
    w = value;

    return *this;
}

/* ####################################################################################### */
/* Access */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 4)>>::reference
Vector <D, T, std::enable_if_t<(D == 4)>>::get(EComponent4D component)
{
    return *(&x + static_cast<size_t>(component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 4)>>::const_reference
Vector <D, T, std::enable_if_t<(D == 4)>>::get(EComponent4D component) const
{
    return *(&x + static_cast<size_t>(component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template <EComponent4D Component>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 4)>>::reference
Vector <D, T, std::enable_if_t<(D == 4)>>::get()
{
    return *(&x + static_cast<size_t>(Component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template <EComponent4D Component>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 4)>>::const_reference
Vector <D, T, std::enable_if_t<(D == 4)>>::get() const
{
    return *(&x + static_cast<size_t>(Component));
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 4)>>::pointer
Vector <D, T, std::enable_if_t<(D == 4)>>::data()
{
    return &x;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D == 4)>>::const_pointer
Vector <D, T, std::enable_if_t<(D == 4)>>::data() const
{
    return &x;
}

/* ####################################################################################### */
/* Methods */
/* ####################################################################################### */

template<size_t D, typename T>
template<EComponent4D X, EComponent4D Y, EComponent4D Z, EComponent4D W>
constexpr CGM_FORCEINLINE void
Vector <D, T, std::enable_if_t<(D == 4)>>::swizzle()
{
    if constexpr (X != EComponent4D::X || Y != EComponent4D::Y || Z != EComponent4D::Z || W != EComponent4D::W)
    {
        *this = Vector<D,T>{ get<X>(), get<Y>(), get<Z>(), get<W>() };
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
template<EComponent4D X, EComponent4D Y, EComponent4D Z, EComponent4D W>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 4)>>
Vector <D, T, std::enable_if_t<(D == 4)>>::swizzled() const
{
    return Vector<D,T>{ get<X>(), get<Y>(), get<Z>(), get<W>() };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE void
Vector <D, T, std::enable_if_t<(D == 4)>>::swizzle(EComponent4D X, EComponent4D Y, EComponent4D Z, EComponent4D W)
{
    *this = Vector<D,T>{ get(X), get(Y), get(Z), get(W) };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D == 4)>>
Vector <D, T, std::enable_if_t<(D == 4)>>::swizzled(EComponent4D X, EComponent4D Y, EComponent4D Z, EComponent4D W) const
{
    return Vector<D,T>{ get(X), get(Y), get(Z), get(W) };
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
Vector <D, T, std::enable_if_t<(D == 4)>>::xy() const
{
    return {x,y};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
Vector <D, T, std::enable_if_t<(D == 4)>>::xyz() const
{
    return {x,y,z};
}

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 4+D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D > 4)>>::Vector(std::initializer_list<T> values)
{
    for (size_t i = 0; i < D; ++i)
    {
        m_data[i] = *(values.begin() + i);
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Vector <D, T, std::enable_if_t<(D > 4)>>::Vector(T value)
{
    for (size_t i = 0; i < D; ++i)
    {
        m_data[i] = value;
    }
}

/* ####################################################################################### */
/* Components accessing */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::reference
Vector <D, T, std::enable_if_t<(D > 4)>>::operator[](size_t index)
{
    return m_data[index];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_reference
Vector <D, T, std::enable_if_t<(D > 4)>>::operator[](size_t index) const
{
    return m_data[index];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector <D, T, std::enable_if_t<(D > 4)>>&
Vector <D, T, std::enable_if_t<(D > 4)>>::operator = (typename Vector <D, T, std::enable_if_t<(D > 4)>>::value_type value)
{
    for (size_t i = 0; i < D; ++i)
    {
        m_data[i] = value;
    }

    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
Vector <D, T, std::enable_if_t<(D > 4)>>::xy() const
{
    return {m_data[0], m_data[1]};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
Vector <D, T, std::enable_if_t<(D > 4)>>::xyz() const
{
    return {m_data[0], m_data[1], m_data[2]};
}

/* ####################################################################################### */
/* Raw data */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::pointer
Vector <D, T, std::enable_if_t<(D > 4)>>::data()
{
    return m_data;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_pointer
Vector <D, T, std::enable_if_t<(D > 4)>>::data() const
{
    return m_data;
}

/* ####################################################################################### */
/* Iterators */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::begin()
{
    return m_data;
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::end()
{
    return m_data + D + 1;
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::begin() const
{
    return m_data;
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::end() const
{
    return m_data + D + 1;
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::cbegin() const
{
    return m_data;
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::cend() const
{
    return m_data + D + 1;
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::reverse_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::rbegin()
{
    return this->end();
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::reverse_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::rend()
{
    return this->begin();
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_reverse_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::rbegin() const
{
    return this->end();
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_reverse_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::rend() const
{
    return this->begin();
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_reverse_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::crbegin() const
{
    return this->cend();
}
/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE typename Vector <D, T, std::enable_if_t<(D > 4)>>::const_reverse_iterator
Vector <D, T, std::enable_if_t<(D > 4)>>::crend() const
{
    return this->cbegin();
}

CGM_NAMESPACE_END

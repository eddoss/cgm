

#include "rectangle.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Rectangle<T>::Rectangle(const Vector<2,T>& Position, const Size<2,T>& SizeValue)
    : center(Position)
    , size(SizeValue)
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
Rectangle<T>::topLeft() const
{
    return
    {
        center.x - size.w / 2,
        center.y + size.h / 2
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
Rectangle<T>::topRight() const
{
    return
    {
        center.x + size.w / 2,
        center.y + size.h / 2
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
Rectangle<T>::bottomLeft() const
{
    return
    {
        center.x - size.w / 2,
        center.y - size.h / 2
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
Rectangle<T>::bottomRight() const
{
    return
    {
        center.x + size.w / 2,
        center.y - size.h / 2
    };
}

CGM_2D_NAMESPACE_END
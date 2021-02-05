

#include "Rectangle.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Rectangle<T>::Rectangle(const Vector<2,T>& Position, const Size<T>& SizeValue)
    : position(position)
    , size(SizeValue)
{

}

CGM_2D_NAMESPACE_END
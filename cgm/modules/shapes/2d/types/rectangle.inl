

#include "rectangle.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Rectangle<T>::Rectangle(const Vector<2,T>& Position, const Size<2,T>& SizeValue)
    : center(Position)
    , size(SizeValue)
{

}

CGM_2D_NAMESPACE_END
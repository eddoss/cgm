

#include "Rectangle.hpp"


CGM_NAMESPACE_BEGIN
CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Rectangle<T>::Rectangle(const Vector<2,T>& Position, const Size<T>& Size)
    : position(position)
    , size(Size)
{

}

CGM_2D_NAMESPACE_END
CGM_NAMESPACE_END
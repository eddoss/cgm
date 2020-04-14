#ifndef MATH3D_PIVOT_HPP
#define MATH3D_PIVOT_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

template<size_t D, typename T=FLOAT, typename = void> struct Pivot;

template<size_t D, typename T>
struct Pivot <D, T, std::enable_if_t<(D == 2)>>
{
    Vector<D,T> x;          ///< X axes.
    Vector<D,T> y;          ///< Y axes.
    Vector<D,T> position;   ///< Pivot position.
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Pivot <D, T, std::enable_if_t<(D == 3)>>
{
    Vector<D,T> x;           ///< X axes.
    Vector<D,T> y;           ///< Y axes.
    Vector<D,T> z;           ///< Z axes.
    Vector<D,T> position;    ///< Pivot position.
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_PIVOT_HPP
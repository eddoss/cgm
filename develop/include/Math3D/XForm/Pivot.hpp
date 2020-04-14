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
    MATH3D_RULE_OF_FIVE(Pivot)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    Vector<D,T> x;          ///< X axes.
    Vector<D,T> y;          ///< Y axes.
    Vector<D,T> position;   ///< Pivot position.

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initializing all axes.
     * @param InX X axes.
     * @param InY Y axes.
     * @param InPosition Pivot position.
     */
    constexpr
    Pivot(const Vector<D,T>& InX, const Vector<D,T>& InY, const Vector<D,T>& InPosition);
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Pivot <D, T, std::enable_if_t<(D == 3)>>
{
    MATH3D_RULE_OF_FIVE(Pivot)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    Vector<D,T> x;           ///< X axes.
    Vector<D,T> y;           ///< Y axes.
    Vector<D,T> z;           ///< Z axes.
    Vector<D,T> position;    ///< Pivot position.

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initializing all axes.
     * @param InX X axes.
     * @param InY Y axes.
     * @param InZ Z axes.
     * @param InPosition Pivot position.
     */
    constexpr
    Pivot(const Vector<D,T>& InX, const Vector<D,T>& InY, const Vector<D,T>& InZ, const Vector<D,T>& InPosition);
};

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/XForm/Pivot.hpp>


#endif // MATH3D_PIVOT_HPP
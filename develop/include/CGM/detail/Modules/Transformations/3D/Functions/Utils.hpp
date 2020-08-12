

#include <CGM/Modules/Transformations/3D/Functions/Utils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
constexpr Quaternion<T>
quaternion(const Vector<3,T>& axis, T angle)
{
    T ang = angle * number<T>(0.5);
    T sin = std::sin(ang);

    return Quaternion<T>
    {
        axis.x * sin,
        axis.y * sin,
        axis.z * sin,
        std::cos(ang)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
quaternion(const AxisAngle<T>& axisAngle)
{
    auto [axis, angle] = axisAngle;
    return quaternion(axis, angle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE AxisAngle<T>
axisAngle(const Vector<3,T>& axis, T angle)
{
    return std::make_tuple(axis, angle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr AxisAngle<T>
axisAngle(const Quaternion<T>& quaternion)
{
    T ang = std::acos(quaternion.w) * 2;
    T isn = number<T>(1) / std::sin(ang * number<T>(0.5));

    auto axs = Vector<3,T>
    {
        quaternion.x * isn,
        quaternion.y * isn,
        quaternion.z * isn
    };

    return std::make_tuple(axs, ang);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
axis(const AxisAngle<T>& axisAngle)
{
    return std::get<0>(axisAngle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
axis(const Quaternion<T>& quaternion)
{
    T ang = std::acos(quaternion.w) * 2;
    T isn = number<T>(1) / std::sin(ang * number<T>(0.5));

    auto axs = Vector<3,T>
    {
        quaternion.x * isn,
        quaternion.y * isn,
        quaternion.z * isn
    };

    return axs;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
angle(const AxisAngle<T>& axisAngle)
{
    return std::get<1>(axisAngle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
angle(const Quaternion<T>& quaternion)
{
    return std::acos(quaternion.w) * 2;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
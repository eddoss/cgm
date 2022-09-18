

#include "utils.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr Quaternion<T>
orientationQuaternion(const Vector<3,T>& axis, T angle)
{
    T ang = angle * T(0.5);
    T sin = T(std::sin(ang));

    return Quaternion<T>
    {
        axis.x * sin,
        axis.y * sin,
        axis.z * sin,
        T(std::cos(ang))
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const AxisAngle<T>& axisAngle)
{
    return orientationQuaternion(axisAngle.axis, axisAngle.angle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr AxisAngle<T>
axisAngle(const Quaternion<T>& quaternion)
{
    T ang = angle(quaternion);
    T isn = T(1) / std::sin(ang * T(0.5));

    auto axs = Vector<3,T>
    {
        quaternion.vector.x * isn,
        quaternion.vector.y * isn,
        quaternion.vector.z * isn
    };

    return AxisAngle<T>(axs, ang);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
axis(const Quaternion<T>& quaternion)
{
    T ang = angle(quaternion);
    T isn = T(1) / std::sin(ang * T(0.5));

    auto axs = Vector<3,T>
    {
        quaternion.vector.x * isn,
        quaternion.vector.y * isn,
        quaternion.vector.z * isn
    };

    return axs;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
angle(const Quaternion<T>& quaternion)
{
    return std::acos(quaternion.scalar) * 2;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
shortestDistance(const Vector<3,T>& point, const Vector<3,T>& planeNormal)
{
    return dot(point, planeNormal);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
zeroPivot()
{
    return
    {
        x<T>(),
        y<T>(),
        z<T>(),
        Vector<3,T>(T(0))
    };
}

CGM_NAMESPACE_END
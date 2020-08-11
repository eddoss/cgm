

#include <CGM/Modules/Transformations/3D/Functions/Scale.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

 template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& values)
{
    vector.x *= values.x;
    vector.y *= values.y;
    vector.z *= values.z;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
scale(Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    auto p = vector - pivotPoint.position;

    auto sdx = dot(p, pivotPoint.x); // short dist to pivot XZ plane
    auto sdy = dot(p, pivotPoint.y); // short dist to pivot YZ plane
    auto sdz = dot(p, pivotPoint.z); // short dist to pivot XY plane

    vector += pivotPoint.x * (values.x - 1) * sdx;
    vector += pivotPoint.y * (values.y - 1) * sdy;
    vector += pivotPoint.z * (values.z - 1) * sdz;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Transforms<T>& transforms)
{
    scale(vector, transforms.scales * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values)
{
    if constexpr (Space == ESpace::World)
    {
        auto scaler = Matrix<3,3,T>
        {
            values.x, number<T>(0), number<T>(0),
            number<T>(0), values.y, number<T>(0),
            number<T>(0), number<T>(0), values.z
        };

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = matrix * scaler;
    #else
        matrix = scaler * matrix;
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,0) *= values.x;
        matrix(0,1) *= values.x;
        matrix(0,2) *= values.x;

        matrix(1,0) *= values.y;
        matrix(1,1) *= values.y;
        matrix(1,2) *= values.y;

        matrix(2,0) *= values.z;
        matrix(2,1) *= values.z;
        matrix(2,2) *= values.z;
    #else
        matrix(0,0) *= values.x;
        matrix(1,0) *= values.x;
        matrix(2,0) *= values.x;

        matrix(0,1) *= values.y;
        matrix(1,1) *= values.y;
        matrix(2,1) *= values.y;

        matrix(0,2) *= values.z;
        matrix(1,2) *= values.z;
        matrix(2,2) *= values.z;
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::World)
    {
        auto worldSpacePivot = Pivot<T>
        {
            localToGlobal(pivotPoint.x, matrix),
            localToGlobal(pivotPoint.y, matrix),
            localToGlobal(pivotPoint.z, matrix),
            localToGlobal(pivotPoint.position, matrix)
        };

        scale<ESpace::Local>(matrix, values, worldSpacePivot);
    }
    else
    {
        auto X = x(matrix);
        auto Y = y(matrix);
        auto Z = z(matrix);

        scale(X, values, pivotPoint);
        scale(Y, values, pivotPoint);
        scale(Z, values, pivotPoint);

        setX(matrix, X);
        setY(matrix, Y);
        setZ(matrix, Z);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    scale<Space>(matrix, transforms.scales * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values)
{
    if constexpr (Space == ESpace::World)
    {
        auto scaler = Matrix<4,4,T>
        {
            values.x, number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), values.y, number<T>(0), number<T>(0),
            number<T>(0), number<T>(0), values.z, number<T>(0),
            number<T>(0), number<T>(0), number<T>(0), number<T>(1)
        };

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = matrix * scaler;
    #else
        matrix = scaler * matrix;
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,0) *= values.x;
        matrix(0,1) *= values.x;
        matrix(0,2) *= values.x;

        matrix(1,0) *= values.y;
        matrix(1,1) *= values.y;
        matrix(1,2) *= values.y;

        matrix(2,0) *= values.z;
        matrix(2,1) *= values.z;
        matrix(2,2) *= values.z;
    #else
        matrix(0,0) *= values.x;
        matrix(1,0) *= values.x;
        matrix(2,0) *= values.x;

        matrix(0,1) *= values.y;
        matrix(1,1) *= values.y;
        matrix(2,1) *= values.y;

        matrix(0,2) *= values.z;
        matrix(1,2) *= values.z;
        matrix(2,2) *= values.z;
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::World)
    {
        auto worldSpacePivot = Pivot<T>
        {
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.x, matrix),
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.y, matrix),
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.z, matrix),
            localToGlobal<EVectorRepresentation::Point>(pivotPoint.position, matrix)
        };

        scale<ESpace::Local>(matrix, values, worldSpacePivot);
    }
    else
    {
        auto X = x(matrix);
        auto Y = y(matrix);
        auto Z = z(matrix);

        scale(X, values, pivotPoint);
        scale(Y, values, pivotPoint);
        scale(Z, values, pivotPoint);

        setX(matrix, X);
        setY(matrix, Y);
        setZ(matrix, Z);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    scale<Space>(matrix, transforms.scales * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

 template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Vector<3,T>& values)
{
    scale(pivot.position, values);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    scale(pivot.position, values, pivotPoint);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    scale(pivot.position, transforms);
}

/* ####################################################################################### */
/* AxesTuple */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr void
scale(AxesTuple<T>& axes, const Vector<3,T>& values)
{
    auto& [X,Y,Z] = axes;

    if constexpr (Space == ESpace::World)
    {
        auto scales = values - number<T>(1);
        auto xAxis = X * values.x;
        auto yAxis = Y * values.y;
        auto zAxis = Z * values.z;

        X += xAxis * X.x;
        X += yAxis * X.y;
        X += zAxis * X.z;

        Y += xAxis * Y.x;
        Y += yAxis * Y.y;
        Y += zAxis * Y.z;

        Z += xAxis * Z.x;
        Z += yAxis * Z.y;
        Z += zAxis * Z.z;
    }
    else
    {
        X *= values.x;
        Y *= values.y;
        Z *= values.z;
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(AxesTuple<T>& axes, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::World)
    {
        auto mat = orientationMatrix(axes);
        auto worldSpacePivot = Pivot<T>
        {
            localToGlobal(pivotPoint.x, mat),
            localToGlobal(pivotPoint.y, mat),
            localToGlobal(pivotPoint.z, mat),
            localToGlobal(pivotPoint.position, mat)
        };

        scale<ESpace::Local>(axes, values, worldSpacePivot);
    }
    else
    {
        auto& [X,Y,Z] = axes;

        scale(X, values, pivotPoint);
        scale(Y, values, pivotPoint);
        scale(Z, values, pivotPoint);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(AxesTuple<T>& axes, const Transforms<T>& transforms)
{
    scale(axes, transforms.scales * transforms.uniformScale, transforms.pivot);
}

/* ####################################################################################### */
/* SpaceTuple */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr void
scale(SpaceTuple<T>& space, const Vector<3,T>& values)
{
    auto& X = std::get<0>(space);
    auto& Y = std::get<1>(space);
    auto& Z = std::get<2>(space);

    if constexpr (Space == ESpace::World)
    {
        auto scales = values - number<T>(1);
        auto xAxis = X * values.x;
        auto yAxis = Y * values.y;
        auto zAxis = Z * values.z;

        X += xAxis * X.x;
        X += yAxis * X.y;
        X += zAxis * X.z;

        Y += xAxis * Y.x;
        Y += yAxis * Y.y;
        Y += zAxis * Y.z;

        Z += xAxis * Z.x;
        Z += yAxis * Z.y;
        Z += zAxis * Z.z;
    }
    else
    {
        X *= values.x;
        Y *= values.y;
        Z *= values.z;
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
scale(SpaceTuple<T>& space, const Vector<3,T>& values, const Pivot<T>& pivotPoint)
{
    if constexpr (Space == ESpace::World)
    {
        auto mat = packBasis(space);
        auto wsp = Pivot<T> // world space pivot
        {
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.x, mat),
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.y, mat),
            localToGlobal<EVectorRepresentation::Direction>(pivotPoint.z, mat),
            localToGlobal<EVectorRepresentation::Point>(pivotPoint.position, mat)
        };

        scale<ESpace::Local>(space, values, wsp);
    }
    else
    {
        auto X = x(space);
        auto Y = y(space);
        auto Z = z(space);

        scale(X, values, pivotPoint);
        scale(Y, values, pivotPoint);
        scale(Z, values, pivotPoint);

        setX(space, X);
        setY(space, Y);
        setZ(space, Z);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
scale(SpaceTuple<T>& space, const Transforms<T>& transforms)
{
    scale(space, transforms.scales * transforms.uniformScale, transforms.pivot);
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END

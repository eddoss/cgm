#pragma once


#include <CGM/detail/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/detail/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/detail/Modules/Cartesian/3D/Functions/Converters/Vector.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean pivot 
 * will be converted to from local to world (and vice versa). The physically position of
 * the pivot does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientation);

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean pivot 
 * will be converted to from local to world (and vice versa). The physically position of
 * the pivot does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 * @param position Local space position.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean pivot 
 * will be converted to from local to world (and vice versa). The physically position of
 * the pivot does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param space Local space represented by 4x4 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& space);

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean pivot 
 * will be converted to from local to world (and vice versa). The physically position of
 * the pivot does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param orientation orientation Local space orientation represented by quaternion.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientation);

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean pivot 
 * will be converted to from local to world (and vice versa). The physically position of
 * the pivot does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param orientation Local space orientation represented by quaternion.
 * @param position Position of local space.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientation, const Vector<3,T>& position);

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (inplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Quaternion with Position (inplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean axis
 * will be converted to from local to world (and vice versa). The physically position
 * of the pivot does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientation);

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean axis
 * will be converted to from local to world (and vice versa). The
 * physically position  of the pivot does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 * @param position Local space position.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean axis
 * will be converted to from local to world (and vice versa). The
 * physically position  of the pivot does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param space Local space represented by 4x4 matrix.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& space);

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean axis
 * will be converted to from local to world (and vice versa). The
 * physically position  of the pivot does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param orientation orientation Local space orientation represented by quaternion.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientation);

/**
 * Convert pivot from given space to another space. If 'Space' is 'World' it mean axis
 * will be converted to from local to world (and vice versa). The
 * physically position  of the pivot does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param pivot Pivot to convert.
 * @param orientation Local space orientation represented by quaternion.
 * @param position Position of local space.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientation, const Vector<3,T>& position);

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (outplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Quaternion with Position (outplace) */
/* ####################################################################################### */

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Convert pivot from space A to space B (A and B are in one space). The physically 
 * position of the pivot does not change, only recalculation to the B system occurs.
 * @param pivot Pivot in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
converted(const Pivot<T>& pivot, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Converters/Pivot_impl.hpp>

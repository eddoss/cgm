#pragma once


#include <cgm/modules/transformations/3d/module_globals.hpp>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/cartesian/3d/functions/converters/vector.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The physically position of
 * the axis does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientation);

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The physically position of
 * the axis does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 * @param position Local space position.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The physically position of
 * the axis does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param space Local space represented by 4x4 matrix.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<4,4,T>& space);

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The physically position of
 * the axis does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param orientation orientation Local space orientation represented by quaternion.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientation);

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The physically position of
 * the axis does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param orientation Local space orientation represented by quaternion.
 * @param position Position of local space.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientation, const Vector<3,T>& position);

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (inplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Quaternion with Position (inplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param spaceB 4x4 matrix of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
convert(Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The physically position
 * of the axis does not change, only recalculation to the local system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientation);

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The
 * physically position  of the axis does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param orientation Local space orientation represented by 3x3 matrix.
 * @param position Local space position.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The
 * physically position  of the axis does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param space Local space represented by 4x4 matrix.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<4,4,T>& space);

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The
 * physically position  of the axis does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param orientation orientation Local space orientation represented by quaternion.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientation);

/**
 * Convert axis from given space to another space. If 'Space' is 'Global' it mean axis
 * will be converted to from local to global (and vice versa). The
 * physically position  of the axis does not change, only recalculation to the local
 * system occurs.
 * @tparam Space Space to convert to.
 * @param axis Axis to convert.
 * @param orientation Local space orientation represented by quaternion.
 * @param position Position of local space.
 * @return Converted axis.
 */
template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientation, const Vector<3,T>& position);

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (outplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionB Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param spaceA Basis of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

/* ####################################################################################### */
/* Local to local: Quaternion with Position (outplace) */
/* ####################################################################################### */

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param spaceB 4x4 matrix of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB);

/**
 * Convert axis from space A to space B (A and B are in one space). The physically 
 * position of the axis does not change, only recalculation to the B system occurs.
 * @param axis Axis in A space.
 * @param orientationA Orientation of A space.
 * @param positionA Position of A space.
 * @param orientationB Orientation of B space.
 * @param positionB Position of B space.
 * @return Converted axis from space A to B.
 */
template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
converted(const Ray<T>& axis, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB);

CGM_NAMESPACE_END


#include "axis.inl"

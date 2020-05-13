

#include <Math3D/Core/Operators/MatrixVectorMultiplication.hpp>


template<size_t D, size_t N, typename T>
constexpr std::conditional_t<(N == 1), T, MATH3D_NAMESPACE::Vector<N,T>>
operator * (const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Matrix<D,N,T>& B)
{
    if constexpr (N == 1)
    {
        if constexpr (D == 2)
        {
            return {A.x * B(0, 0) + A.y * B(1, 0)};
        }
        else if constexpr (D == 3)
        {
            return {A.x * B(0, 0) + A.y * B(1, 0) + A.z * B(2, 0)};
        }
        else if constexpr (D == 4)
        {
            return {A.x * B(0, 0) + A.y * B(1, 0) + A.z * B(2, 0) + A.w * B(3, 0)};
        }
        else
        {
            T sum {MATH3D_NAMESPACE::zero<T>};

            for (size_t i = 0; i < D; ++i)
            {
                sum += A[i] * B(i,0);
            }

            return sum;
        }
    }
    else
    {
        if constexpr (D == 2)
        {
            if constexpr (N == 2)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0),
                    A.x * B(0,1) + A.y * B(1,1)
                };
            }
            else if constexpr (N == 3)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0),
                    A.x * B(0,1) + A.y * B(1,1),
                    A.x * B(0,2) + A.y * B(1,2)
                };
            }
            else if constexpr (N == 4)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0),
                    A.x * B(0,1) + A.y * B(1,1),
                    A.x * B(0,2) + A.y * B(1,2),
                    A.x * B(0,3) + A.y * B(1,3)
                };
            }
            else
            {
                MATH3D_NAMESPACE::Vector<N,T> vec(MATH3D_NAMESPACE::zero<T>);

                for (size_t i = 0; i < N; ++i)
                {
                    vec[i] = A.x * B(0,i) + A.y * B(1,i);
                }

                return vec;
            }
        }
        else if constexpr (D == 3)
        {
            if constexpr (N == 2)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0) + A.z * B(2,0),
                    A.x * B(0,1) + A.y * B(1,1) + A.z * B(2,1)
                };
            }
            else if constexpr (N == 3)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0) + A.z * B(2,0),
                    A.x * B(0,1) + A.y * B(1,1) + A.z * B(2,1),
                    A.x * B(0,2) + A.y * B(1,2) + A.z * B(2,2)
                };
            }
            else if constexpr (N == 4)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0) + A.z * B(2,0),
                    A.x * B(0,1) + A.y * B(1,1) + A.z * B(2,1),
                    A.x * B(0,2) + A.y * B(1,2) + A.z * B(2,2),
                    A.x * B(0,3) + A.y * B(1,3) + A.z * B(2,3)
                };
            }
            else
            {
                MATH3D_NAMESPACE::Vector<N,T> vec(MATH3D_NAMESPACE::zero<T>);

                for (size_t i = 0; i < N; ++i)
                {
                    vec[i] = A.x * B(0,i) + A.y * B(1,i) + A.z * B(2,i);
                }

                return vec;
            }
        }
        else if constexpr (D == 4)
        {
            if constexpr (N == 2)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0) + A.z * B(2,0) + A.w * B(3,0),
                    A.x * B(0,1) + A.y * B(1,1) + A.z * B(2,1) + A.w * B(3,1)
                };
            }
            else if constexpr (N == 3)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0) + A.z * B(2,0) + A.w * B(3,0),
                    A.x * B(0,1) + A.y * B(1,1) + A.z * B(2,1) + A.w * B(3,1),
                    A.x * B(0,2) + A.y * B(1,2) + A.z * B(2,2) + A.w * B(3,2)
                };
            }
            else if constexpr (N == 4)
            {
                return
                {
                    A.x * B(0,0) + A.y * B(1,0) + A.z * B(2,0) + A.w * B(3,0),
                    A.x * B(0,1) + A.y * B(1,1) + A.z * B(2,1) + A.w * B(3,1),
                    A.x * B(0,2) + A.y * B(1,2) + A.z * B(2,2) + A.w * B(3,2),
                    A.x * B(0,3) + A.y * B(1,3) + A.z * B(2,3) + A.w * B(3,3)
                };
            }
            else
            {
                MATH3D_NAMESPACE::Vector<N,T> vec(MATH3D_NAMESPACE::zero<T>);

                for (size_t i = 0; i < N; ++i)
                {
                    vec[i] = A.x * B(0,i) + A.y * B(1,i) + A.z * B(2,i) + A.w * B(3,i);
                }

                return vec;
            }
        }
        else
        {
            MATH3D_NAMESPACE::Vector<N,T> vec(MATH3D_NAMESPACE::zero<T>);

            if constexpr (N == 2)
            {
                for (size_t i = 0; i < D; ++i) {vec.x += A[i] * B(i,0);}
                for (size_t i = 0; i < D; ++i) {vec.y += A[i] * B(i,1);}
            }
            else if constexpr (N == 3)
            {
                for (size_t i = 0; i < D; ++i) {vec.x += A[i] * B(i,0);}
                for (size_t i = 0; i < D; ++i) {vec.y += A[i] * B(i,1);}
                for (size_t i = 0; i < D; ++i) {vec.z += A[i] * B(i,2);}
            }
            else if constexpr (N == 4)
            {
                for (size_t i = 0; i < D; ++i) {vec.x += A[i] * B(i,0);}
                for (size_t i = 0; i < D; ++i) {vec.y += A[i] * B(i,1);}
                for (size_t i = 0; i < D; ++i) {vec.z += A[i] * B(i,2);}
                for (size_t i = 0; i < D; ++i) {vec.w += A[i] * B(i,3);}
            }
            else
            {
                for (size_t i = 0; i < N; ++i)
                {
                    for (size_t j = 0; j < D; ++j)
                    {
                        vec[i] += A[j] * B(j,i);
                    }
                }
            }

            return vec;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, size_t M, typename T>
constexpr std::conditional_t<(M == 1), T, MATH3D_NAMESPACE::Vector<M,T>>
operator * (const MATH3D_NAMESPACE::Matrix<M,D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B)
{
    if constexpr (M == 1)
    {
        if constexpr (D == 2)
        {
            return {B.x * A(0,0) + B.y * A(0,1)};
        }
        else if constexpr (D == 3)
        {
            return {B.x * A(0,0) + B.y * A(0,1) + B.z * A(0,2)};
        }
        else if constexpr (D == 4)
        {
            return {B.x * A(0,0) + B.y * A(0,1) + B.z * A(0,2) + B.w * A(0,3)};
        }
        else
        {
            T sum {MATH3D_NAMESPACE::zero<T>};

            for (size_t i = 0; i < D; ++i)
            {
                sum += B[i] * A(0,i);
            }

            return sum;
        }
    }
    else
    {
        if constexpr (D == 2)
        {
            if constexpr (M == 2)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1),
                    B.x * A(1,0) + B.y * A(1,1)
                };
            }
            else if constexpr (M == 3)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1),
                    B.x * A(1,0) + B.y * A(1,1),
                    B.x * A(2,0) + B.y * A(2,1)
                };
            }
            else if constexpr (M == 4)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1),
                    B.x * A(1,0) + B.y * A(1,1),
                    B.x * A(2,0) + B.y * A(2,1),
                    B.x * A(3,0) + B.y * A(3,1)
                };
            }
            else
            {
                MATH3D_NAMESPACE::Vector<M,T> vec(MATH3D_NAMESPACE::zero<T>);

                for (size_t i = 0; i < M; ++i)
                {
                    vec[i] = B.x * A(i,0) + B.y * A(i,1);
                }

                return vec;
            }
        }
        else if constexpr (D == 3)
        {
            if constexpr (M == 2)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1) + B.z * A(0,2),
                    B.x * A(1,0) + B.y * A(1,1) + B.z * A(1,2)
                };
            }
            else if constexpr (M == 3)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1) + B.z * A(0,2),
                    B.x * A(1,0) + B.y * A(1,1) + B.z * A(1,2),
                    B.x * A(2,0) + B.y * A(2,1) + B.z * A(2,2)
                };
            }
            else if constexpr (M == 4)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1) + B.z * A(0,2),
                    B.x * A(1,0) + B.y * A(1,1) + B.z * A(1,2),
                    B.x * A(2,0) + B.y * A(2,1) + B.z * A(2,2),
                    B.x * A(3,0) + B.y * A(3,1) + B.z * A(3,2)
                };
            }
            else
            {
                MATH3D_NAMESPACE::Vector<M,T> vec(MATH3D_NAMESPACE::zero<T>);

                for (size_t i = 0; i < M; ++i)
                {
                    vec[i] = B.x * A(i,0) + B.y * A(i,1) + B.z * A(i,2);
                }

                return vec;
            }
        }
        else if constexpr (D == 4)
        {
            if constexpr (M == 2)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1) + B.z * A(0,2) + B.w * A(0,3),
                    B.x * A(1,0) + B.y * A(1,1) + B.z * A(1,2) + B.w * A(1,3)
                };
            }
            else if constexpr (M == 3)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1) + B.z * A(0,2) + B.w * A(0,3),
                    B.x * A(1,0) + B.y * A(1,1) + B.z * A(1,2) + B.w * A(1,3),
                    B.x * A(2,0) + B.y * A(2,1) + B.z * A(2,2) + B.w * A(2,3)
                };
            }
            else if constexpr (M == 4)
            {
                return
                {
                    B.x * A(0,0) + B.y * A(0,1) + B.z * A(0,2) + B.w * A(0,3),
                    B.x * A(1,0) + B.y * A(1,1) + B.z * A(1,2) + B.w * A(1,3),
                    B.x * A(2,0) + B.y * A(2,1) + B.z * A(2,2) + B.w * A(2,3),
                    B.x * A(3,0) + B.y * A(3,1) + B.z * A(3,2) + B.w * A(3,3)
                };
            }
            else
            {
                MATH3D_NAMESPACE::Vector<M,T> vec(MATH3D_NAMESPACE::zero<T>);

                for (size_t i = 0; i < M; ++i)
                {
                    vec[i] = B.x * A(i,0) + B.y * A(i,1) + B.z * A(i,2) + B.w * A(i,3);
                }

                return vec;
            }
        }
        else
        {
            MATH3D_NAMESPACE::Vector<M,T> vec(MATH3D_NAMESPACE::zero<T>);

            if constexpr (M == 2)
            {
                for (size_t i = 0; i < D; ++i) {vec.x += B[i] * A(0,i);}
                for (size_t i = 0; i < D; ++i) {vec.y += B[i] * A(1,i);}
            }
            else if constexpr (M == 3)
            {
                for (size_t i = 0; i < D; ++i) {vec.x += B[i] * A(0,i);}
                for (size_t i = 0; i < D; ++i) {vec.y += B[i] * A(1,i);}
                for (size_t i = 0; i < D; ++i) {vec.z += B[i] * A(2,i);}
            }
            else if constexpr (M == 4)
            {
                for (size_t i = 0; i < D; ++i) {vec.x += B[i] * A(0,i);}
                for (size_t i = 0; i < D; ++i) {vec.y += B[i] * A(1,i);}
                for (size_t i = 0; i < D; ++i) {vec.z += B[i] * A(2,i);}
                for (size_t i = 0; i < D; ++i) {vec.w += B[i] * A(3,i);}
            }
            else
            {
                for (size_t i = 0; i < M; ++i)
                {
                    for (size_t j = 0; j < D; ++j)
                    {
                        vec[i] += B[j] * A(i,j);
                    }
                }
            }

            return vec;
        }
    }
}
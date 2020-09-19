

#include <CGM/detail/Core/Operators/Matrix.hpp>


/* ####################################################################################### */
/* IMPLEMENTATION | Increment and decrement */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator ++ (CGM::Matrix<M,N,T>& matrix)
{
    if constexpr (M == 2 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);
        ++matrix(1,0);  ++matrix(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);  
        ++matrix(1,0);  ++matrix(1,1);
        ++matrix(2,0);  ++matrix(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);  ++matrix(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);  
        ++matrix(1,0);  ++matrix(1,1);
        ++matrix(2,0);  ++matrix(2,1);
        ++matrix(3,0);  ++matrix(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);
        ++matrix(3,0);  ++matrix(3,1);  ++matrix(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);  ++matrix(2,3);
        ++matrix(3,0);  ++matrix(3,1);  ++matrix(3,2);  ++matrix(3,3);
    } 
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            ++(matrix[i]);
        }
    }

    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator -- (CGM::Matrix<M,N,T>& matrix)
{
    if constexpr (M == 2 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);
        --matrix(1,0);  --matrix(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);  
        --matrix(1,0);  --matrix(1,1);
        --matrix(2,0);  --matrix(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);  --matrix(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);  
        --matrix(1,0);  --matrix(1,1);
        --matrix(2,0);  --matrix(2,1);
        --matrix(3,0);  --matrix(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);
        --matrix(3,0);  --matrix(3,1);  --matrix(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);  --matrix(2,3);
        --matrix(3,0);  --matrix(3,1);  --matrix(3,2);  --matrix(3,3);
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            --(matrix[i]);
        }
    }

    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator ++ (CGM::Matrix<M,N,T>& matrix, int)
{
    auto copy {matrix};

    if constexpr (M == 2 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);
        ++matrix(1,0);  ++matrix(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);
        ++matrix(1,0);  ++matrix(1,1);
        ++matrix(2,0);  ++matrix(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);  ++matrix(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        ++matrix(0,0);  ++matrix(0,1);
        ++matrix(1,0);  ++matrix(1,1);
        ++matrix(2,0);  ++matrix(2,1);
        ++matrix(3,0);  ++matrix(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);
        ++matrix(3,0);  ++matrix(3,1);  ++matrix(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        ++matrix(0,0);  ++matrix(0,1);  ++matrix(0,2);  ++matrix(0,3);
        ++matrix(1,0);  ++matrix(1,1);  ++matrix(1,2);  ++matrix(1,3);
        ++matrix(2,0);  ++matrix(2,1);  ++matrix(2,2);  ++matrix(2,3);
        ++matrix(3,0);  ++matrix(3,1);  ++matrix(3,2);  ++matrix(3,3);
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            ++(matrix[i]);
        }
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator -- (CGM::Matrix<M,N,T>& matrix, int)
{
    auto copy {matrix};

    if constexpr (M == 2 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);
        --matrix(1,0);  --matrix(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);
        --matrix(1,0);  --matrix(1,1);
        --matrix(2,0);  --matrix(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);  --matrix(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        --matrix(0,0);  --matrix(0,1);
        --matrix(1,0);  --matrix(1,1);
        --matrix(2,0);  --matrix(2,1);
        --matrix(3,0);  --matrix(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);
        --matrix(3,0);  --matrix(3,1);  --matrix(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        --matrix(0,0);  --matrix(0,1);  --matrix(0,2);  --matrix(0,3);
        --matrix(1,0);  --matrix(1,1);  --matrix(1,2);  --matrix(1,3);
        --matrix(2,0);  --matrix(2,1);  --matrix(2,2);  --matrix(2,3);
        --matrix(3,0);  --matrix(3,1);  --matrix(3,2);  --matrix(3,3);
    } 
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            --(matrix[i]);
        }
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Plus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator + (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),
            A(1,0)+B(1,0),  A(1,1)+B(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),  A(0,3)+B(0,3),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),  A(1,3)+B(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),
            A(2,0)+B(2,0),  A(2,1)+B(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),  A(2,2)+B(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),  A(0,3)+B(0,3),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),  A(1,3)+B(1,3),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),  A(2,2)+B(2,2),  A(2,3)+B(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),
            A(3,0)+B(3,0),  A(3,1)+B(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),  A(2,2)+B(2,2),
            A(3,0)+B(3,0),  A(3,1)+B(3,1),  A(3,2)+B(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            A(0,0)+B(0,0),  A(0,1)+B(0,1),  A(0,2)+B(0,2),  A(0,3)+B(0,3),
            A(1,0)+B(1,0),  A(1,1)+B(1,1),  A(1,2)+B(1,2),  A(1,3)+B(1,3),
            A(2,0)+B(2,0),  A(2,1)+B(2,1),  A(2,2)+B(2,2),  A(2,3)+B(2,3),
            A(3,0)+B(3,0),  A(3,1)+B(3,1),  A(3,2)+B(3,2),  A(3,3)+B(3,3)
        };
    }
    else
    {
        CGM::Matrix<M,N,T> result;
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] = A[i] + B[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator + (const CGM::Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value,
            matrix(2,0)+value,  matrix(2,1)+value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,  matrix(2,3)+value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value,
            matrix(2,0)+value,  matrix(2,1)+value,
            matrix(3,0)+value,  matrix(3,1)+value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,
            matrix(3,0)+value,  matrix(3,1)+value,  matrix(3,2)+value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,  matrix(2,3)+value,
            matrix(3,0)+value,  matrix(3,1)+value,  matrix(3,2)+value,  matrix(3,3)+value
        };
    }
    else
    {
        auto result {matrix};
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] += value;
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator + (T scalar, const CGM::Matrix<M,N,T>& matrix)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value,
            matrix(2,0)+value,  matrix(2,1)+value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,  matrix(2,3)+value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,
            matrix(1,0)+value,  matrix(1,1)+value,
            matrix(2,0)+value,  matrix(2,1)+value,
            matrix(3,0)+value,  matrix(3,1)+value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,
            matrix(3,0)+value,  matrix(3,1)+value,  matrix(3,2)+value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            matrix(0,0)+value,  matrix(0,1)+value,  matrix(0,2)+value,  matrix(0,3)+value,
            matrix(1,0)+value,  matrix(1,1)+value,  matrix(1,2)+value,  matrix(1,3)+value,
            matrix(2,0)+value,  matrix(2,1)+value,  matrix(2,2)+value,  matrix(2,3)+value,
            matrix(3,0)+value,  matrix(3,1)+value,  matrix(3,2)+value,  matrix(3,3)+value
        };
    }
    else
    {
        auto result {matrix};
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] += value;
        }
        return result;
    } 
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>&
operator += (CGM::Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;  matrix(0,3)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;  matrix(1,3)+=value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;  matrix(2,2)+=value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;  matrix(0,3)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;  matrix(1,3)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;  matrix(2,2)+=value;  matrix(2,3)+=value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;
        matrix(3,0)+=value;  matrix(3,1)+=value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;  matrix(2,2)+=value;
        matrix(3,0)+=value;  matrix(3,1)+=value;  matrix(3,2)+=value;
    }
    else if constexpr (M == 4 && N == 4)
    {
        matrix(0,0)+=value;  matrix(0,1)+=value;  matrix(0,2)+=value;  matrix(0,3)+=value;
        matrix(1,0)+=value;  matrix(1,1)+=value;  matrix(1,2)+=value;  matrix(1,3)+=value;
        matrix(2,0)+=value;  matrix(2,1)+=value;  matrix(2,2)+=value;  matrix(2,3)+=value;
        matrix(3,0)+=value;  matrix(3,1)+=value;  matrix(3,2)+=value;  matrix(3,3)+=value;
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            matrix[i] += value;
        }
    }
    
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator += (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);  A(0,3)+=B(0,3);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);  A(1,3)+=B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);  A(2,2)+=B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);  A(0,3)+=B(0,3);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);  A(1,3)+=B(1,3);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);  A(2,2)+=B(2,2);  A(2,3)+=B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);
        A(3,0)+=B(3,0);  A(3,1)+=B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);  A(2,2)+=B(2,2);
        A(3,0)+=B(3,0);  A(3,1)+=B(3,1);  A(3,2)+=B(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        A(0,0)+=B(0,0);  A(0,1)+=B(0,1);  A(0,2)+=B(0,2);  A(0,3)+=B(0,3);
        A(1,0)+=B(1,0);  A(1,1)+=B(1,1);  A(1,2)+=B(1,2);  A(1,3)+=B(1,3);
        A(2,0)+=B(2,0);  A(2,1)+=B(2,1);  A(2,2)+=B(2,2);  A(2,3)+=B(2,3);
        A(3,0)+=B(3,0);  A(3,1)+=B(3,1);  A(3,2)+=B(3,2);  A(3,3)+=B(3,3);
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            A[i] += B[i];
        }
    }
    
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Minus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator - (const CGM::Matrix<M,N,T>& matrix)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),
            -matrix(1,0),  -matrix(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),  -matrix(0,3),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),  -matrix(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),
            -matrix(1,0),  -matrix(1,1),
            -matrix(2,0),  -matrix(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),
            -matrix(2,0),  -matrix(2,1),  -matrix(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),  -matrix(0,3),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),  -matrix(1,3),
            -matrix(2,0),  -matrix(2,1),  -matrix(2,2),  -matrix(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),
            -matrix(1,0),  -matrix(1,1),
            -matrix(2,0),  -matrix(2,1),
            -matrix(3,0),  -matrix(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),
            -matrix(2,0),  -matrix(2,1),  -matrix(2,2),
            -matrix(3,0),  -matrix(3,1),  -matrix(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            -matrix(0,0),  -matrix(0,1),  -matrix(0,2),  -matrix(0,3),
            -matrix(1,0),  -matrix(1,1),  -matrix(1,2),  -matrix(1,3),
            -matrix(2,0),  -matrix(2,1),  -matrix(2,2),  -matrix(2,3),
            -matrix(3,0),  -matrix(3,1),  -matrix(3,2),  -matrix(3,3)
        };
    }
    else
    {
        CGM::Matrix<M,N,T> result;
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] = -matrix[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator - (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),
            A(1,0)-B(1,0),  A(1,1)-B(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),  A(0,3)-B(0,3),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),  A(1,3)-B(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),
            A(2,0)-B(2,0),  A(2,1)-B(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),  A(2,2)-B(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),  A(0,3)-B(0,3),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),  A(1,3)-B(1,3),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),  A(2,2)-B(2,2),  A(2,3)-B(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),
            A(3,0)-B(3,0),  A(3,1)-B(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),  A(2,2)-B(2,2),
            A(3,0)-B(3,0),  A(3,1)-B(3,1),  A(3,2)-B(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            A(0,0)-B(0,0),  A(0,1)-B(0,1),  A(0,2)-B(0,2),  A(0,3)-B(0,3),
            A(1,0)-B(1,0),  A(1,1)-B(1,1),  A(1,2)-B(1,2),  A(1,3)-B(1,3),
            A(2,0)-B(2,0),  A(2,1)-B(2,1),  A(2,2)-B(2,2),  A(2,3)-B(2,3),
            A(3,0)-B(3,0),  A(3,1)-B(3,1),  A(3,2)-B(3,2),  A(3,3)-B(3,3)
        };
    }
    else
    {
        CGM::Matrix<M,N,T> result;
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] = A[i] - B[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator - (const CGM::Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,
            matrix(1,0)-value,  matrix(1,1)-value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,  matrix(0,3)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,  matrix(1,3)-value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,
            matrix(1,0)-value,  matrix(1,1)-value,
            matrix(2,0)-value,  matrix(2,1)-value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,
            matrix(2,0)-value,  matrix(2,1)-value,  matrix(2,2)-value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,  matrix(0,3)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,  matrix(1,3)-value,
            matrix(2,0)-value,  matrix(2,1)-value,  matrix(2,2)-value,  matrix(2,3)-value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,
            matrix(1,0)-value,  matrix(1,1)-value,
            matrix(2,0)-value,  matrix(2,1)-value,
            matrix(3,0)-value,  matrix(3,1)-value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,
            matrix(2,0)-value,  matrix(2,1)-value,  matrix(2,2)-value,
            matrix(3,0)-value,  matrix(3,1)-value,  matrix(3,2)-value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            matrix(0,0)-value,  matrix(0,1)-value,  matrix(0,2)-value,  matrix(0,3)-value,
            matrix(1,0)-value,  matrix(1,1)-value,  matrix(1,2)-value,  matrix(1,3)-value,
            matrix(2,0)-value,  matrix(2,1)-value,  matrix(2,2)-value,  matrix(2,3)-value,
            matrix(3,0)-value,  matrix(3,1)-value,  matrix(3,2)-value,  matrix(3,3)-value
        };
    }
    else
    {
        CGM::Matrix<M,N,T> result;
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] = matrix[i] - value;
        }
        return result;
    } 
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>&
operator -= (CGM::Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;  matrix(0,3)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;  matrix(1,3)-=value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;  matrix(2,2)-=value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;  matrix(0,3)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;  matrix(1,3)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;  matrix(2,2)-=value;  matrix(2,3)-=value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;
        matrix(3,0)-=value;  matrix(3,1)-=value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;  matrix(2,2)-=value;
        matrix(3,0)-=value;  matrix(3,1)-=value;  matrix(3,2)-=value;
    }
    else if constexpr (M == 4 && N == 4)
    {
        matrix(0,0)-=value;  matrix(0,1)-=value;  matrix(0,2)-=value;  matrix(0,3)-=value;
        matrix(1,0)-=value;  matrix(1,1)-=value;  matrix(1,2)-=value;  matrix(1,3)-=value;
        matrix(2,0)-=value;  matrix(2,1)-=value;  matrix(2,2)-=value;  matrix(2,3)-=value;
        matrix(3,0)-=value;  matrix(3,1)-=value;  matrix(3,2)-=value;  matrix(3,3)-=value;
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            matrix[i] -= value;
        }
    }
    
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator -= (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);  A(0,3)-=B(0,3);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);  A(1,3)-=B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);  A(2,2)-=B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);  A(0,3)-=B(0,3);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);  A(1,3)-=B(1,3);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);  A(2,2)-=B(2,2);  A(2,3)-=B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);
        A(3,0)-=B(3,0);  A(3,1)-=B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);  A(2,2)-=B(2,2);
        A(3,0)-=B(3,0);  A(3,1)-=B(3,1);  A(3,2)-=B(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        A(0,0)-=B(0,0);  A(0,1)-=B(0,1);  A(0,2)-=B(0,2);  A(0,3)-=B(0,3);
        A(1,0)-=B(1,0);  A(1,1)-=B(1,1);  A(1,2)-=B(1,2);  A(1,3)-=B(1,3);
        A(2,0)-=B(2,0);  A(2,1)-=B(2,1);  A(2,2)-=B(2,2);  A(2,3)-=B(2,3);
        A(3,0)-=B(3,0);  A(3,1)-=B(3,1);  A(3,2)-=B(3,2);  A(3,3)-=B(3,3);
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            A[i] -= B[i];
        }
    }

    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise multiplication */
/* ####################################################################################### */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator * (const CGM::Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value,
            matrix(2,0)*value,  matrix(2,1)*value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,  matrix(2,3)*value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value,
            matrix(2,0)*value,  matrix(2,1)*value,
            matrix(3,0)*value,  matrix(3,1)*value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,
            matrix(3,0)*value,  matrix(3,1)*value,  matrix(3,2)*value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,  matrix(2,3)*value,
            matrix(3,0)*value,  matrix(3,1)*value,  matrix(3,2)*value,  matrix(3,3)*value
        };
    }
    else
    {
        CGM::Matrix<M,N,T> result {matrix};
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] *= value;
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator * (TScalar scalar, const CGM::Matrix<M,N,T>& matrix)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value,
            matrix(2,0)*value,  matrix(2,1)*value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,  matrix(2,3)*value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,
            matrix(1,0)*value,  matrix(1,1)*value,
            matrix(2,0)*value,  matrix(2,1)*value,
            matrix(3,0)*value,  matrix(3,1)*value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,
            matrix(3,0)*value,  matrix(3,1)*value,  matrix(3,2)*value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            matrix(0,0)*value,  matrix(0,1)*value,  matrix(0,2)*value,  matrix(0,3)*value,
            matrix(1,0)*value,  matrix(1,1)*value,  matrix(1,2)*value,  matrix(1,3)*value,
            matrix(2,0)*value,  matrix(2,1)*value,  matrix(2,2)*value,  matrix(2,3)*value,
            matrix(3,0)*value,  matrix(3,1)*value,  matrix(3,2)*value,  matrix(3,3)*value
        };
    }
    else
    {
        auto result {matrix};
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] *= value;
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t AM, size_t AN, size_t BN, typename T>
constexpr CGM::Matrix<AM,BN,T>
operator * (const CGM::Matrix<AM,AN,T>& A, const CGM::Matrix<AN,BN,T>& B)
{
    // 2x2 * 2x2 -> 2x2
    if constexpr (AM == 2 && AN == 2 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1)
        };
    }

    // 2x2 * 2x3 -> 2x3
    if constexpr (AM == 2 && AN == 2 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2)
        };
    }

    // 2x2 * 2x4 -> 2x4
    if constexpr (AM == 2 && AN == 2 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3)
        };
    }

/* ********************************************************* */

    // 2x3 * 3x2 -> 2x2
    if constexpr (AM == 2 && AN == 3 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1)
        };
    }

    // 2x3 * 3x3 -> 2x3
    if constexpr (AM == 2 && AN == 3 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2)
        };
    }

    // 2x3 * 3x4 -> 2x4
    if constexpr (AM == 2 && AN == 3 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3)
        };
    }

/* ********************************************************* */

    // 2x4 * 4x2 -> 2x2
    if constexpr (AM == 2 && AN == 4 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1)
        };
    }

    // 2x4 * 4x3 -> 2x3
    if constexpr (AM == 2 && AN == 4 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2)
        };
    }

    // 2x4 * 4x4 -> 2x4
    if constexpr (AM == 2 && AN == 4 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3) + A(0,3)*B(3,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3) + A(1,3)*B(3,3)
        };
    }

/* ********************************************************* */

    // 3x2 * 2x2 -> 3x2
    if constexpr (AM == 3 && AN == 2 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1)
        };
    }

    // 3x2 * 2x3 -> 3x3
    if constexpr (AM == 3 && AN == 2 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2)
        };
    }

    // 3x2 * 2x4 -> 3x4
    if constexpr (AM == 3 && AN == 2 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3)
        };
    }

/* ********************************************************* */

    // 3x3 * 3x2 -> 3x2
    if constexpr (AM == 3 && AN == 3 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1)
        };
    }

    // 3x3 * 3x3 -> 3x3
    if constexpr (AM == 3 && AN == 3 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2)
        };
    }

    // 3x3 * 3x4 -> 3x4
    if constexpr (AM == 3 && AN == 3 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3)
        };
    }

/* ********************************************************* */

    // 3x4 * 4x2 -> 3x2
    if constexpr (AM == 3 && AN == 4 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1)
        };
    }

    // 3x4 * 4x3 -> 3x3
    if constexpr (AM == 3 && AN == 4 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2)
        };
    }

    // 3x4 * 4x4 -> 3x4
    if constexpr (AM == 3 && AN == 4 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3) + A(0,3)*B(3,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3) + A(1,3)*B(3,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3) + A(2,3)*B(3,3)
        };
    }

/* ********************************************************* */

    // 4x2 * 2x2 -> 4x2
    if constexpr (AM == 4 && AN == 2 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1)
        };
    }

    // 4x2 * 2x3 -> 4x3
    if constexpr (AM == 4 && AN == 2 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2)
        };
    }

    // 4x2 * 2x4 -> 4x4
    if constexpr (AM == 4 && AN == 2 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3)
        };
    }

/* ********************************************************* */

    // 4x3 * 3x2 -> 4x2
    if constexpr (AM == 4 && AN == 3 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1)
        };
    }

    // 4x3 * 3x3 -> 4x3
    if constexpr (AM == 4 && AN == 3 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2)
        };
    }

    // 4x3 * 3x4 -> 4x4
    if constexpr (AM == 4 && AN == 3 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3) + A(3,2)*B(2,3)
        };
    }

/* ********************************************************* */

    // 4x4 * 4x2 -> 4x2
    if constexpr (AM == 4 && AN == 4 && BN == 2)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0) + A(3,3)*B(3,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1) + A(3,3)*B(3,1)
        };
    }

    // 4x4 * 4x3 -> 4x3
    if constexpr (AM == 4 && AN == 4 && BN == 3)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0) + A(3,3)*B(3,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1) + A(3,3)*B(3,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2) + A(3,3)*B(3,2)
        };
    }

    // 4x4 * 4x4 -> 4x4
    if constexpr (AM == 4 && AN == 4 && BN == 4)
    {
        return
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3) + A(0,3)*B(3,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3) + A(1,3)*B(3,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3) + A(2,3)*B(3,3),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0) + A(3,3)*B(3,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1) + A(3,3)*B(3,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2) + A(3,3)*B(3,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3) + A(3,2)*B(2,3) + A(3,3)*B(3,3)
        };
    }

/* ********************************************************* */

    if constexpr (AM > 4 && AN > 4 && BN > 4)
    {
        CGM::Matrix<AM,BN,T> result;
        typename CGM::Matrix<AM,BN,T>::value_type sum;

        for (size_t c = 0; c < BN; ++c )
        {
            for (auto r = 0; r < AM; ++r)
            {
                sum = static_cast<typename CGM::Matrix<AM,BN,T>::value_type>(0);
                for (auto i = 0; i < AN; ++i)
                {
                    sum += A(r,i) * B(i,c);
                }
                result(r,c) = sum;
            }
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr T
operator * (const CGM::Matrix<1,S,T>& A, const CGM::Matrix<S,1,T>& B)
{
    if constexpr (S == 2)
    {
        return  A(0,0) * B(0,0) +
                A(0,1) * B(1,0);
    }
    if constexpr (S == 3)
    {
        return  A(0,0) * B(0,0) +
                A(0,1) * B(1,0) +
                A(0,2) * B(2,0);
    }
    if constexpr (S == 4)
    {
        return  A(0,0) * B(0,0) +
                A(0,1) * B(1,0) +
                A(0,2) * B(2,0) +
                A(0,3) * B(3,0);
    }
    if constexpr (S > 4)
    {
        T value {static_cast<T>(0)};
        for (int i = 0; i < S; ++i)
        {
            value += A(0,i) * B(i,0);
        }
        return value;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>&
operator *= (CGM::Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;  matrix(0,3)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;  matrix(1,3)*=value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;  matrix(2,2)*=value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;  matrix(0,3)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;  matrix(1,3)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;  matrix(2,2)*=value;  matrix(2,3)*=value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;
        matrix(3,0)*=value;  matrix(3,1)*=value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;  matrix(2,2)*=value;
        matrix(3,0)*=value;  matrix(3,1)*=value;  matrix(3,2)*=value;
    }
    else if constexpr (M == 4 && N == 4)
    {
        matrix(0,0)*=value;  matrix(0,1)*=value;  matrix(0,2)*=value;  matrix(0,3)*=value;
        matrix(1,0)*=value;  matrix(1,1)*=value;  matrix(1,2)*=value;  matrix(1,3)*=value;
        matrix(2,0)*=value;  matrix(2,1)*=value;  matrix(2,2)*=value;  matrix(2,3)*=value;
        matrix(3,0)*=value;  matrix(3,1)*=value;  matrix(3,2)*=value;  matrix(3,3)*=value;
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            matrix[i] *= value;
        }
    }
    
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr CGM::Matrix<S,S,T>&
operator *= (CGM::Matrix<S,S,T>& A, const CGM::Matrix<S,S,T>& B)
{
    if constexpr (S== 2)
    {
        A =
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1)
        };
    }
    else if constexpr (S == 3)
    {
        A =
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2)
        };
    }
    else if constexpr (S == 4)
    {
        A =
        {
            // row 0
            A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0) + A(0,3)*B(3,0),
            A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1) + A(0,3)*B(3,1),
            A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2) + A(0,3)*B(3,2),
            A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3) + A(0,3)*B(3,3),

            // row 1
            A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0) + A(1,3)*B(3,0),
            A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1) + A(1,3)*B(3,1),
            A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2) + A(1,3)*B(3,2),
            A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3) + A(1,3)*B(3,3),

            // row 2
            A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0) + A(2,3)*B(3,0),
            A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1) + A(2,3)*B(3,1),
            A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2) + A(2,3)*B(3,2),
            A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3) + A(2,3)*B(3,3),

            // row 3
            A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0) + A(3,3)*B(3,0),
            A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1) + A(3,3)*B(3,1),
            A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2) + A(3,3)*B(3,2),
            A(3,0)*B(0,3) + A(3,1)*B(1,3) + A(3,2)*B(2,3) + A(3,3)*B(3,3)
        };
    }
    else
    {
        CGM::Matrix<S,S,T> result;

        typename CGM::Matrix<S,S,T>::value_type sum;
    
        for (auto c = 0; c < S; ++c)
        {
            for (auto r = 0; r < S; ++r)
            {
                sum = CGM::zero<T>;
                for (auto i = 0; i < S; ++i)
                {
                    sum += A(r,i) * B(i,c);
                }
                result(r,c) = sum;
            }
        }
        A = result;
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator ^ (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),
            A(1,0)*B(1,0),  A(1,1)*B(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),  A(0,2)*B(0,2),
            A(1,0)*B(1,0),  A(1,1)*B(1,1),  A(1,2)*B(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),  A(0,2)*B(0,2),  A(0,3)*B(0,3),
            A(1,0)*B(1,0),  A(1,1)*B(1,1),  A(1,2)*B(1,2),  A(1,3)*B(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),
            A(1,0)*B(1,0),  A(1,1)*B(1,1),
            A(2,0)*B(2,0),  A(2,1)*B(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),  A(0,2)*B(0,2),
            A(1,0)*B(1,0),  A(1,1)*B(1,1),  A(1,2)*B(1,2),
            A(2,0)*B(2,0),  A(2,1)*B(2,1),  A(2,2)*B(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),  A(0,2)*B(0,2),  A(0,3)*B(0,3),
            A(1,0)*B(1,0),  A(1,1)*B(1,1),  A(1,2)*B(1,2),  A(1,3)*B(1,3),
            A(2,0)*B(2,0),  A(2,1)*B(2,1),  A(2,2)*B(2,2),  A(2,3)*B(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),
            A(1,0)*B(1,0),  A(1,1)*B(1,1),
            A(2,0)*B(2,0),  A(2,1)*B(2,1),
            A(3,0)*B(3,0),  A(3,1)*B(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),  A(0,2)*B(0,2),
            A(1,0)*B(1,0),  A(1,1)*B(1,1),  A(1,2)*B(1,2),
            A(2,0)*B(2,0),  A(2,1)*B(2,1),  A(2,2)*B(2,2),
            A(3,0)*B(3,0),  A(3,1)*B(3,1),  A(3,2)*B(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            A(0,0)*B(0,0),  A(0,1)*B(0,1),  A(0,2)*B(0,2),  A(0,3)*B(0,3),
            A(1,0)*B(1,0),  A(1,1)*B(1,1),  A(1,2)*B(1,2),  A(1,3)*B(1,3),
            A(2,0)*B(2,0),  A(2,1)*B(2,1),  A(2,2)*B(2,2),  A(2,3)*B(2,3),
            A(3,0)*B(3,0),  A(3,1)*B(3,1),  A(3,2)*B(3,2),  A(3,3)*B(3,3)
        };
    }
    else
    {
        CGM::Matrix<M,N,T> result;
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] = A[i] * B[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator ^= (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(0,3) =* B(0,3);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(1,3) =* B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(2,2) =* B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(0,3) =* B(0,3);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(1,3) =* B(1,3);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(2,2) =* B(2,2);
        A(2,3) =* B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(3,0) =* B(3,0);
        A(3,1) =* B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(2,2) =* B(2,2);
        A(3,0) =* B(3,0);
        A(3,1) =* B(3,1);
        A(3,2) =* B(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(0,3) =* B(0,3);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(1,3) =* B(1,3);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(2,2) =* B(2,2);
        A(2,3) =* B(2,3);
        A(3,0) =* B(3,0);
        A(3,1) =* B(3,1);
        A(3,2) =* B(3,2);
        A(3,3) =* B(3,3);
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            A[i] *= B[i];
        };
    }

    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise division */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator | (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),
            A(1,0)/B(1,0),  A(1,1)/B(1,1)
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2)
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),  A(0,3)/B(0,3),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),  A(1,3)/B(1,3)
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),
            A(2,0)/B(2,0),  A(2,1)/B(2,1)
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),  A(2,2)/B(2,2)
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),  A(0,3)/B(0,3),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),  A(1,3)/B(1,3),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),  A(2,2)/B(2,2),  A(2,3)/B(2,3)
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),
            A(3,0)/B(3,0),  A(3,1)/B(3,1)
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),  A(2,2)/B(2,2),
            A(3,0)/B(3,0),  A(3,1)/B(3,1),  A(3,2)/B(3,2)
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            A(0,0)/B(0,0),  A(0,1)/B(0,1),  A(0,2)/B(0,2),  A(0,3)/B(0,3),
            A(1,0)/B(1,0),  A(1,1)/B(1,1),  A(1,2)/B(1,2),  A(1,3)/B(1,3),
            A(2,0)/B(2,0),  A(2,1)/B(2,1),  A(2,2)/B(2,2),  A(2,3)/B(2,3),
            A(3,0)/B(3,0),  A(3,1)/B(3,1),  A(3,2)/B(3,2),  A(3,3)/B(3,3)
        };
    }
    else
    {
        CGM::Matrix<M,N,T> result;
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] = A[i] / B[i];
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>
operator |= (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(0,3) =* B(0,3);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(1,3) =* B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(2,2) =* B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(0,3) =* B(0,3);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(1,3) =* B(1,3);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(2,2) =* B(2,2);
        A(2,3) =* B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(3,0) =* B(3,0);
        A(3,1) =* B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(2,2) =* B(2,2);
        A(3,0) =* B(3,0);
        A(3,1) =* B(3,1);
        A(3,2) =* B(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        A(0,0) =* B(0,0);
        A(0,1) =* B(0,1);
        A(0,2) =* B(0,2);
        A(0,3) =* B(0,3);
        A(1,0) =* B(1,0);
        A(1,1) =* B(1,1);
        A(1,2) =* B(1,2);
        A(1,3) =* B(1,3);
        A(2,0) =* B(2,0);
        A(2,1) =* B(2,1);
        A(2,2) =* B(2,2);
        A(2,3) =* B(2,3);
        A(3,0) =* B(3,0);
        A(3,1) =* B(3,1);
        A(3,2) =* B(3,2);
        A(3,3) =* B(3,3);
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            A[i] /= B[i];
        };
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>
operator / (const CGM::Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 2 && N == 2)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,
            matrix(1,0)/value,  matrix(1,1)/value
        };
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value
        };
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,  matrix(0,3)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,  matrix(1,3)/value
        };
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,
            matrix(1,0)/value,  matrix(1,1)/value,
            matrix(2,0)/value,  matrix(2,1)/value
        };
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,
            matrix(2,0)/value,  matrix(2,1)/value,  matrix(2,2)/value
        };
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,  matrix(0,3)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,  matrix(1,3)/value,
            matrix(2,0)/value,  matrix(2,1)/value,  matrix(2,2)/value,  matrix(2,3)/value
        };
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,
            matrix(1,0)/value,  matrix(1,1)/value,
            matrix(2,0)/value,  matrix(2,1)/value,
            matrix(3,0)/value,  matrix(3,1)/value
        };
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,
            matrix(2,0)/value,  matrix(2,1)/value,  matrix(2,2)/value,
            matrix(3,0)/value,  matrix(3,1)/value,  matrix(3,2)/value
        };
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        {
            matrix(0,0)/value,  matrix(0,1)/value,  matrix(0,2)/value,  matrix(0,3)/value,
            matrix(1,0)/value,  matrix(1,1)/value,  matrix(1,2)/value,  matrix(1,3)/value,
            matrix(2,0)/value,  matrix(2,1)/value,  matrix(2,2)/value,  matrix(2,3)/value,
            matrix(3,0)/value,  matrix(3,1)/value,  matrix(3,2)/value,  matrix(3,3)/value
        };
    }
    else
    {
        CGM::Matrix<M,N,T> result;
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            result[i] = matrix[i] / value;
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T, typename TScalar>
constexpr CGM::Matrix<M,N,T>&
operator /= (CGM::Matrix<M,N,T>& matrix, TScalar scalar)
{
    T value {static_cast<T>(scalar)};
    
    if constexpr (M == 2 && N == 2)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;
    }
    else if constexpr (M == 2 && N == 3)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;
    }
    else if constexpr (M == 2 && N == 4)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;  matrix(0,3)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;  matrix(1,3)/=value;
    }
    else if constexpr (M == 3 && N == 2)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;
    }
    else if constexpr (M == 3 && N == 3)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;  matrix(2,2)/=value;
    }
    else if constexpr (M == 3 && N == 4)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;  matrix(0,3)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;  matrix(1,3)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;  matrix(2,2)/=value;  matrix(2,3)/=value;
    }
    else if constexpr (M == 4 && N == 2)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;
        matrix(3,0)/=value;  matrix(3,1)/=value;
    }
    else if constexpr (M == 4 && N == 3)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;  matrix(2,2)/=value;
        matrix(3,0)/=value;  matrix(3,1)/=value;  matrix(3,2)/=value;
    }
    else if constexpr (M == 4 && N == 4)
    {
        matrix(0,0)/=value;  matrix(0,1)/=value;  matrix(0,2)/=value;  matrix(0,3)/=value;
        matrix(1,0)/=value;  matrix(1,1)/=value;  matrix(1,2)/=value;  matrix(1,3)/=value;
        matrix(2,0)/=value;  matrix(2,1)/=value;  matrix(2,2)/=value;  matrix(2,3)/=value;
        matrix(3,0)/=value;  matrix(3,1)/=value;  matrix(3,2)/=value;  matrix(3,3)/=value;
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            matrix[i] /= value;
        }
    }
    
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM::Matrix<M,N,T>&
operator /= (CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 2 && N == 2)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);
    }
    else if constexpr (M == 2 && N == 3)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);
    }
    else if constexpr (M == 2 && N == 4)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);  A(0,3)/=B(0,3);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);  A(1,3)/=B(1,3);
    }
    else if constexpr (M == 3 && N == 2)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);
    }
    else if constexpr (M == 3 && N == 3)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);  A(2,2)/=B(2,2);
    }
    else if constexpr (M == 3 && N == 4)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);  A(0,3)/=B(0,3);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);  A(1,3)/=B(1,3);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);  A(2,2)/=B(2,2);  A(2,3)/=B(2,3);
    }
    else if constexpr (M == 4 && N == 2)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);
        A(3,0)/=B(3,0);  A(3,1)/=B(3,1);
    }
    else if constexpr (M == 4 && N == 3)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);  A(2,2)/=B(2,2);
        A(3,0)/=B(3,0);  A(3,1)/=B(3,1);  A(3,2)/=B(3,2);
    }
    else if constexpr (M == 4 && N == 4)
    {
        A(0,0)/=B(0,0);  A(0,1)/=B(0,1);  A(0,2)/=B(0,2);  A(0,3)/=B(0,3);
        A(1,0)/=B(1,0);  A(1,1)/=B(1,1);  A(1,2)/=B(1,2);  A(1,3)/=B(1,3);
        A(2,0)/=B(2,0);  A(2,1)/=B(2,1);  A(2,2)/=B(2,2);  A(2,3)/=B(2,3);
        A(3,0)/=B(3,0);  A(3,1)/=B(3,1);  A(3,2)/=B(3,2);  A(3,3)/=B(3,3);
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            A[i] /= B[i];
        }
    }
    
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr bool
operator == (const CGM::Matrix<M,N,T>& matrix, T scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 1 && N == 2)
    {
        return
        CGM::eq(matrix(0,0), value) &&
        CGM::eq(matrix(0,1), value);
    }
    else if constexpr (M == 1 && N == 3)
    {
        return
        CGM::eq(matrix(0,0), value) &&
        CGM::eq(matrix(0,1), value) &&
        CGM::eq(matrix(0,2), value);
    }
    else if constexpr (M == 1 && N == 4)
    {
        return
        CGM::eq(matrix(0,0), value) &&
        CGM::eq(matrix(0,1), value) &&
        CGM::eq(matrix(0,2), value) &&
        CGM::eq(matrix(0,3), value);
    }
    else if constexpr (M == 2 && N == 1)
    {
        return
        CGM::eq(matrix(0,0), value) &&
        CGM::eq(matrix(1,0), value);
    }
    else if constexpr (M == 3 && N == 1)
    {
        return
        CGM::eq(matrix(0,0), value) &&
        CGM::eq(matrix(1,0), value) &&
        CGM::eq(matrix(2,0), value);
    }
    else if constexpr (M == 4 && N == 1)
    {
        return
        CGM::eq(matrix(0,0), value) &&
        CGM::eq(matrix(1,0), value) &&
        CGM::eq(matrix(2,0), value) &&
        CGM::eq(matrix(3,0), value);
    }
    else if constexpr (M == 2 && N == 2)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(1,1),value);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(0,2),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(1,1),value) &&
        CGM::eq(matrix(1,2),value);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(0,2),value) &&
        CGM::eq(matrix(0,3),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(1,1),value) &&
        CGM::eq(matrix(1,2),value) &&
        CGM::eq(matrix(1,3),value);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(2,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(1,1),value) &&
        CGM::eq(matrix(2,1),value);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(0,2),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(1,1),value) &&
        CGM::eq(matrix(1,2),value) &&
        CGM::eq(matrix(2,0),value) &&
        CGM::eq(matrix(2,1),value) &&
        CGM::eq(matrix(2,2),value);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(0,2),value) &&
        CGM::eq(matrix(0,3),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(1,1),value) &&
        CGM::eq(matrix(1,2),value) &&
        CGM::eq(matrix(1,3),value) &&
        CGM::eq(matrix(2,0),value) &&
        CGM::eq(matrix(2,1),value) &&
        CGM::eq(matrix(2,2),value) &&
        CGM::eq(matrix(2,3),value);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(1,1),value) &&
        CGM::eq(matrix(2,0),value) &&
        CGM::eq(matrix(2,1),value) &&
        CGM::eq(matrix(3,0),value) &&
        CGM::eq(matrix(3,1),value);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(0,2),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(1,1),value) &&
        CGM::eq(matrix(1,2),value) &&
        CGM::eq(matrix(2,0),value) &&
        CGM::eq(matrix(2,1),value) &&
        CGM::eq(matrix(2,2),value) &&
        CGM::eq(matrix(3,0),value) &&
        CGM::eq(matrix(3,1),value) &&
        CGM::eq(matrix(3,2),value);
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        CGM::eq(matrix(0,0),value) &&
        CGM::eq(matrix(0,1),value) &&
        CGM::eq(matrix(0,2),value) &&
        CGM::eq(matrix(0,3),value) &&
        CGM::eq(matrix(1,0),value) &&
        CGM::eq(matrix(1,1),value) &&
        CGM::eq(matrix(1,2),value) &&
        CGM::eq(matrix(1,3),value) &&
        CGM::eq(matrix(2,0),value) &&
        CGM::eq(matrix(2,1),value) &&
        CGM::eq(matrix(2,2),value) &&
        CGM::eq(matrix(2,3),value) &&
        CGM::eq(matrix(3,0),value) &&
        CGM::eq(matrix(3,1),value) &&
        CGM::eq(matrix(3,2),value) &&
        CGM::eq(matrix(3,3),value);
    } 
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            if (CGM::neq(matrix[i], scalar)) return false;
        }
        return true;   
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator != (const CGM::Matrix<M,N,T>& matrix, T scalar)
{
    T value {static_cast<T>(scalar)};

    if constexpr (M == 1 && N == 2)
    {
        return
        CGM::neq(matrix(0,0), value) ||
        CGM::neq(matrix(0,1), value);
    }
    else if constexpr (M == 1 && N == 3)
    {
        return
        CGM::neq(matrix(0,0), value) ||
        CGM::neq(matrix(0,1), value) ||
        CGM::neq(matrix(0,2), value);
    }
    else if constexpr (M == 1 && N == 4)
    {
        return
        CGM::neq(matrix(0,0), value) ||
        CGM::neq(matrix(0,1), value) ||
        CGM::neq(matrix(0,2), value) ||
        CGM::neq(matrix(0,3), value);
    }
    else if constexpr (M == 2 && N == 1)
    {
        return
        CGM::neq(matrix(0,0), value) ||
        CGM::neq(matrix(1,0), value);
    }
    else if constexpr (M == 3 && N == 1)
    {
        return
        CGM::neq(matrix(0,0), value) ||
        CGM::neq(matrix(1,0), value) ||
        CGM::neq(matrix(2,0), value);
    }
    else if constexpr (M == 4 && N == 1)
    {
        return
        CGM::neq(matrix(0,0), value) ||
        CGM::neq(matrix(1,0), value) ||
        CGM::neq(matrix(2,0), value) ||
        CGM::neq(matrix(3,0), value);
    }
    else if constexpr (M == 2 && N == 2)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(1,1),value);
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(0,2),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(1,1),value) ||
        CGM::neq(matrix(1,2),value);
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(0,2),value) ||
        CGM::neq(matrix(0,3),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(1,1),value) ||
        CGM::neq(matrix(1,2),value) ||
        CGM::neq(matrix(1,3),value);
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(2,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(1,1),value) ||
        CGM::neq(matrix(2,1),value);
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(0,2),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(1,1),value) ||
        CGM::neq(matrix(1,2),value) ||
        CGM::neq(matrix(2,0),value) ||
        CGM::neq(matrix(2,1),value) ||
        CGM::neq(matrix(2,2),value);
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(0,2),value) ||
        CGM::neq(matrix(0,3),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(1,1),value) ||
        CGM::neq(matrix(1,2),value) ||
        CGM::neq(matrix(1,3),value) ||
        CGM::neq(matrix(2,0),value) ||
        CGM::neq(matrix(2,1),value) ||
        CGM::neq(matrix(2,2),value) ||
        CGM::neq(matrix(2,3),value);
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(1,1),value) ||
        CGM::neq(matrix(2,0),value) ||
        CGM::neq(matrix(2,1),value) ||
        CGM::neq(matrix(3,0),value) ||
        CGM::neq(matrix(3,1),value);
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(0,2),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(1,1),value) ||
        CGM::neq(matrix(1,2),value) ||
        CGM::neq(matrix(2,0),value) ||
        CGM::neq(matrix(2,1),value) ||
        CGM::neq(matrix(2,2),value) ||
        CGM::neq(matrix(3,0),value) ||
        CGM::neq(matrix(3,1),value) ||
        CGM::neq(matrix(3,2),value);
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        CGM::neq(matrix(0,0),value) ||
        CGM::neq(matrix(0,1),value) ||
        CGM::neq(matrix(0,2),value) ||
        CGM::neq(matrix(0,3),value) ||
        CGM::neq(matrix(1,0),value) ||
        CGM::neq(matrix(1,1),value) ||
        CGM::neq(matrix(1,2),value) ||
        CGM::neq(matrix(1,3),value) ||
        CGM::neq(matrix(2,0),value) ||
        CGM::neq(matrix(2,1),value) ||
        CGM::neq(matrix(2,2),value) ||
        CGM::neq(matrix(2,3),value) ||
        CGM::neq(matrix(3,0),value) ||
        CGM::neq(matrix(3,1),value) ||
        CGM::neq(matrix(3,2),value) ||
        CGM::neq(matrix(3,3),value);
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            if (CGM::neq(matrix[i], scalar)) return true;
        }
        return false;
    }
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr bool
operator == (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 1 && N == 2)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1));
    }
    else if constexpr (M == 1 && N == 3)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(0,2), B(0,2));
    }
    else if constexpr (M == 1 && N == 4)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(0,2), B(0,2)) &&
        CGM::eq(A(0,3), B(0,3));
    }
    else if constexpr (M == 2 && N == 1)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(1,0), B(1,0));
    }
    else if constexpr (M == 3 && N == 1)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(2,0), B(2,0));
    }
    else if constexpr (M == 4 && N == 1)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(2,0), B(2,0)) &&
        CGM::eq(A(3,0), B(3,0));
    }
    else if constexpr (M == 2 && N == 2)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(1,1), B(1,1));
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(0,2), B(0,2)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(1,1), B(1,1)) &&
        CGM::eq(A(1,2), B(1,2));
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(0,2), B(0,2)) &&
        CGM::eq(A(0,3), B(0,3)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(1,1), B(1,1)) &&
        CGM::eq(A(1,2), B(1,2)) &&
        CGM::eq(A(1,3), B(1,3));
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(2,0), B(2,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(1,1), B(1,1)) &&
        CGM::eq(A(2,1), B(2,1));
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(0,2), B(0,2)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(1,1), B(1,1)) &&
        CGM::eq(A(1,2), B(1,2)) &&
        CGM::eq(A(2,0), B(2,0)) &&
        CGM::eq(A(2,1), B(2,1)) &&
        CGM::eq(A(2,2), B(2,2));
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(0,2), B(0,2)) &&
        CGM::eq(A(0,3), B(0,3)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(1,1), B(1,1)) &&
        CGM::eq(A(1,2), B(1,2)) &&
        CGM::eq(A(1,3), B(1,3)) &&
        CGM::eq(A(2,0), B(2,0)) &&
        CGM::eq(A(2,1), B(2,1)) &&
        CGM::eq(A(2,2), B(2,2)) &&
        CGM::eq(A(2,3), B(2,3));
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(1,1), B(1,1)) &&
        CGM::eq(A(2,0), B(2,0)) &&
        CGM::eq(A(2,1), B(2,1)) &&
        CGM::eq(A(3,0), B(3,0)) &&
        CGM::eq(A(3,1), B(3,1));
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(0,2), B(0,2)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(1,1), B(1,1)) &&
        CGM::eq(A(1,2), B(1,2)) &&
        CGM::eq(A(2,0), B(2,0)) &&
        CGM::eq(A(2,1), B(2,1)) &&
        CGM::eq(A(2,2), B(2,2)) &&
        CGM::eq(A(3,0), B(3,0)) &&
        CGM::eq(A(3,1), B(3,1)) &&
        CGM::eq(A(3,2), B(3,2));
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        CGM::eq(A(0,0), B(0,0)) &&
        CGM::eq(A(0,1), B(0,1)) &&
        CGM::eq(A(0,2), B(0,2)) &&
        CGM::eq(A(0,3), B(0,3)) &&
        CGM::eq(A(1,0), B(1,0)) &&
        CGM::eq(A(1,1), B(1,1)) &&
        CGM::eq(A(1,2), B(1,2)) &&
        CGM::eq(A(1,3), B(1,3)) &&
        CGM::eq(A(2,0), B(2,0)) &&
        CGM::eq(A(2,1), B(2,1)) &&
        CGM::eq(A(2,2), B(2,2)) &&
        CGM::eq(A(2,3), B(2,3)) &&
        CGM::eq(A(3,0), B(3,0)) &&
        CGM::eq(A(3,1), B(3,1)) &&
        CGM::eq(A(3,2), B(3,2)) &&
        CGM::eq(A(3,3), B(3,3));
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            if (CGM::neq(A[i], B[i])) return false;
        }
        return true; 
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr bool
operator != (const CGM::Matrix<M,N,T>& A, const CGM::Matrix<M,N,T>& B)
{
    if constexpr (M == 1 && N == 2)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1));
    }
    else if constexpr (M == 1 && N == 3)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(0,2), B(0,2));
    }
    else if constexpr (M == 1 && N == 4)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(0,2), B(0,2)) ||
        CGM::neq(A(0,3), B(0,3));
    }
    else if constexpr (M == 2 && N == 1)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(1,0), B(1,0));
    }
    else if constexpr (M == 3 && N == 1)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(2,0), B(2,0));
    }
    else if constexpr (M == 4 && N == 1)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(2,0), B(2,0)) ||
        CGM::neq(A(3,0), B(3,0));
    }
    else if constexpr (M == 2 && N == 2)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(1,1), B(1,1));
    }
    else if constexpr (M == 2 && N == 3)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(0,2), B(0,2)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(1,1), B(1,1)) ||
        CGM::neq(A(1,2), B(1,2));
    }
    else if constexpr (M == 2 && N == 4)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(0,2), B(0,2)) ||
        CGM::neq(A(0,3), B(0,3)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(1,1), B(1,1)) ||
        CGM::neq(A(1,2), B(1,2)) ||
        CGM::neq(A(1,3), B(1,3));
    }
    else if constexpr (M == 3 && N == 2)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(2,0), B(2,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(1,1), B(1,1)) ||
        CGM::neq(A(2,1), B(2,1));
    }
    else if constexpr (M == 3 && N == 3)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(0,2), B(0,2)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(1,1), B(1,1)) ||
        CGM::neq(A(1,2), B(1,2)) ||
        CGM::neq(A(2,0), B(2,0)) ||
        CGM::neq(A(2,1), B(2,1)) ||
        CGM::neq(A(2,2), B(2,2));
    }
    else if constexpr (M == 3 && N == 4)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(0,2), B(0,2)) ||
        CGM::neq(A(0,3), B(0,3)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(1,1), B(1,1)) ||
        CGM::neq(A(1,2), B(1,2)) ||
        CGM::neq(A(1,3), B(1,3)) ||
        CGM::neq(A(2,0), B(2,0)) ||
        CGM::neq(A(2,1), B(2,1)) ||
        CGM::neq(A(2,2), B(2,2)) ||
        CGM::neq(A(2,3), B(2,3));
    }
    else if constexpr (M == 4 && N == 2)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(1,1), B(1,1)) ||
        CGM::neq(A(2,0), B(2,0)) ||
        CGM::neq(A(2,1), B(2,1)) ||
        CGM::neq(A(3,0), B(3,0)) ||
        CGM::neq(A(3,1), B(3,1));
    }
    else if constexpr (M == 4 && N == 3)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(0,2), B(0,2)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(1,1), B(1,1)) ||
        CGM::neq(A(1,2), B(1,2)) ||
        CGM::neq(A(2,0), B(2,0)) ||
        CGM::neq(A(2,1), B(2,1)) ||
        CGM::neq(A(2,2), B(2,2)) ||
        CGM::neq(A(3,0), B(3,0)) ||
        CGM::neq(A(3,1), B(3,1)) ||
        CGM::neq(A(3,2), B(3,2));
    }
    else if constexpr (M == 4 && N == 4)
    {
        return
        CGM::neq(A(0,0), B(0,0)) ||
        CGM::neq(A(0,1), B(0,1)) ||
        CGM::neq(A(0,2), B(0,2)) ||
        CGM::neq(A(0,3), B(0,3)) ||
        CGM::neq(A(1,0), B(1,0)) ||
        CGM::neq(A(1,1), B(1,1)) ||
        CGM::neq(A(1,2), B(1,2)) ||
        CGM::neq(A(1,3), B(1,3)) ||
        CGM::neq(A(2,0), B(2,0)) ||
        CGM::neq(A(2,1), B(2,1)) ||
        CGM::neq(A(2,2), B(2,2)) ||
        CGM::neq(A(2,3), B(2,3)) ||
        CGM::neq(A(3,0), B(3,0)) ||
        CGM::neq(A(3,1), B(3,1)) ||
        CGM::neq(A(3,2), B(3,2)) ||
        CGM::neq(A(3,3), B(3,3));
    }
    else
    {
        for (auto i = 0; i < CGM::Matrix<M,N,T>::size; ++i)
        {
            if (CGM::neq(A[i], B[i])) return true;
        }
        return false;
    }
}
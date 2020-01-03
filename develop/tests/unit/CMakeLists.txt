
# ####################################################################################### #
# Init test project
# ####################################################################################### #

project(UnitTests
    LANGUAGES CXX
)

# ####################################################################################### #
# Tests list
# ####################################################################################### #

set(DEFAULT_ITERATORS_TESTS_SUITES
    DefaultIterators/RandomAccessIterator.cpp
)

set(VECTOR_TESTS_SUITES
    Vector/Arithmetic.cpp
    Vector/Assignment.cpp
    Vector/IncrementDecrement.cpp
    Vector/ComparisonWithOther.cpp
    Vector/ComparisonWithScalar.cpp
)

set(MATRIX_TESTS_SUITES
    Matrix/Arithmetic.cpp
    Matrix/Assignment.cpp
    Matrix/IncrementDecrement.cpp
    Matrix/ComparisonWithOther.cpp
    Matrix/ComparisonWithScalar.cpp
    Matrix/Iterators.cpp
    Matrix/ColumnIterators.cpp
    Matrix/RowIterators.cpp
)

# ####################################################################################### #
# Setup target
# ####################################################################################### #

add_executable(${PROJECT_NAME}
    run.cpp
    ${DEFAULT_ITERATORS_TESTS_SUITES}
    ${VECTOR_TESTS_SUITES}
    ${MATRIX_TESTS_SUITES}
)

find_package(GTest REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ../../include)
target_link_libraries(${PROJECT_NAME} PRIVATE
    debug ${GTEST_LIBRARY_DEBUG} ${GTEST_MAIN_LIBRARY_DEBUG} Math3D
    optimized ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} Math3D
)

# ####################################################################################### #
# Setup tests
# ####################################################################################### #

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

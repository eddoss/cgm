
cmake_minimum_required(VERSION 3.12)

# ####################################################################################### #
# Init project
# ####################################################################################### #

project(ComputerGraphixMath
    LANGUAGES CXX
    VERSION 0.0.1
)

# ####################################################################################### #
# Project C++ parameters
# ####################################################################################### #

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ####################################################################################### #
# Promoted cmake options
# ####################################################################################### #

option(CGM_BUILD_UNIT_TESTS "Build unit testing projects." OFF)
option(CGM_BUILD_EXAMPLES "Build examples projects." OFF)
option(CGM_USE_DOUBLE_PRECISION "Use double floating point number precision." OFF)
set(CGM_MATRIX_LAYOUT "Column" CACHE STRING "Store matrix components by rows or columns (Row/Column).")
set(CGM_HANDEDNESS "Right" CACHE STRING "Cartesian system handedness (Right/Left).")
set(CGM_RIGHT_UP_FORWARD_AXES_LABELS "XYZ" CACHE STRING "Right, Up, Forward vectors of Cartesian system (XYZ/YXZ/ZYX/YZX/XZY/ZXY).")
set(CGM_MATRIX_MULTIPLICATION_ORDER "Pre" CACHE STRING "If 'Pre' is used vector will be represented as row, if 'Post' - as column.")

# ####################################################################################### #
# Promoted cmake options constraints
# ####################################################################################### #

set_property(CACHE CGM_RIGHT_UP_FORWARD_AXES_LABELS PROPERTY STRINGS "XYZ;YXZ;ZYX;YZX;XZY;ZXY")
set_property(CACHE CGM_MATRIX_MULTIPLICATION_ORDER PROPERTY STRINGS "Pre;Post")
set_property(CACHE CGM_MATRIX_LAYOUT PROPERTY STRINGS "Row;Column")
set_property(CACHE CGM_HANDEDNESS PROPERTY STRINGS "Left;Right")

# ####################################################################################### #
# Setup subproject output dirs
# ####################################################################################### #

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# ####################################################################################### #
# Subprojects
# ####################################################################################### #

add_subdirectory(library)

if(${CGM_BUILD_UNIT_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif()

if(${CGM_BUILD_EXAMPLES})
    add_subdirectory(examples)
endif()

cmake_minimum_required(VERSION 3.12)

# ####################################################################################### #
# Init project
# ####################################################################################### #

project(Math3D
    LANGUAGES CXX
    VERSION 0.0.1
)

# ####################################################################################### #
# Project C++ parameters
# ####################################################################################### #

set(PROJECT_INSTALL_PREFIX ${PROJECT_NAME}/${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ####################################################################################### #
# Promoted cmake options
# ####################################################################################### #

option(MATH3D_BUILD_UNIT_TESTS "Build unit testing projects." OFF)
option(MATH3D_BUILD_VISUAL_TESTS "Build visual testing projects." OFF)
option(MATH3D_USE_DOUBLE_PRECISION "Use double floating point number precision." OFF)
option(MATH3D_USE_ROW_WISE_MATRIX_STORING "Store matrix components by row-wise (in default by column-wise)." OFF)
option(MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM "Use left handed Cartesian system. Right handed is default." OFF)
set(MATH3D_RIGHT_UP_FORWARD_AXES_LABELS "XYZ" CACHE STRING "Chose 'Right', 'Up', 'Forward' vectors of Cartesian system. By default its XYZ.")
set(MATH3D_VECTOR_REPRESENTATION "Column-Major" CACHE STRING "Chose a vector representation to multiply by the matrix.")

# ####################################################################################### #
# Promoted cmake options constraints
# ####################################################################################### #

set_property(CACHE MATH3D_RIGHT_UP_FORWARD_AXES_LABELS PROPERTY STRINGS "XYZ;YXZ;ZYX;YZX;XZY;ZXY")
set_property(CACHE MATH3D_VECTOR_REPRESENTATION PROPERTY STRINGS "Column-Major;Row-Major")

# ####################################################################################### #
# Setup shared and static libraries output dir
# ####################################################################################### #

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# ####################################################################################### #
# Setup main target
# ####################################################################################### #

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/develop/include"
)

# --------------------------------------------------------------------------------------- #

if(MATH3D_USE_DOUBLE_PRECISION)
    add_definitions(-DMATH3D_USE_DOUBLE_PRECISION)
endif()

# --------------------------------------------------------------------------------------- #

if(MATH3D_USE_ROW_WISE_MATRIX_STORING)
    add_definitions(-DMATH3D_USE_ROW_WISE_MATRIX_STORING)
endif()

# --------------------------------------------------------------------------------------- #

if(MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM)
    add_definitions(-DMATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM)
endif()

# --------------------------------------------------------------------------------------- #

if(MATH3D_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL ZXY)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_Z)
    add_definitions(-DMATH3D_CARTESIAN_UP_X)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_Y)
    add_definitions(-DMATH3D_CARTESIAN_ZXY)
elseif(MATH3D_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL YXZ)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_Y)
    add_definitions(-DMATH3D_CARTESIAN_UP_X)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_Z)
    add_definitions(-DMATH3D_CARTESIAN_YXZ)
elseif(MATH3D_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL ZYX)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_Z)
    add_definitions(-DMATH3D_CARTESIAN_UP_Y)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_X)
    add_definitions(-DMATH3D_CARTESIAN_ZYX)
elseif(MATH3D_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL YZX)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_Y)
    add_definitions(-DMATH3D_CARTESIAN_UP_Z)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_X)
    add_definitions(-DMATH3D_CARTESIAN_YZX)
elseif(MATH3D_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL XZY)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_X)
    add_definitions(-DMATH3D_CARTESIAN_UP_Z)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_Y)
    add_definitions(-DMATH3D_CARTESIAN_XZY)
else()
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_X)
    add_definitions(-DMATH3D_CARTESIAN_UP_Y)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_Z)
    add_definitions(-DMATH3D_CARTESIAN_XYZ)
endif()

# --------------------------------------------------------------------------------------- #

if(MATH3D_VECTOR_REPRESENTATION STREQUAL Column-Major)
    add_definitions(-DMATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION)
elseif(MATH3D_VECTOR_REPRESENTATION STREQUAL Row-Major)
    add_definitions(-DMATH3D_USE_ROW_MAJOR_VECTOR_REPRESENTATION)
else()
    message(FATAL_ERROR "Invalid value of <VECTOR_REPRESENTATION> parameter. It must be <Column-Major> or <Row-Major>.")
endif()

# ####################################################################################### #
# Installation 
# ####################################################################################### #

install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/develop/include"
    DESTINATION "${PROJECT_INSTALL_PREFIX}"
)

# ####################################################################################### #
# Testing
# ####################################################################################### #

if(${MATH3D_BUILD_UNIT_TESTS})
    enable_testing()
    add_subdirectory(develop/tests)
endif()

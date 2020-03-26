
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

option(BUILD_UNIT_TESTS "Build unit testing projects." OFF)
option(BUILD_VISUAL_TESTS "Build visual testing projects." OFF)
option(USE_DOUBLE_PRECISION "Use double floating point number precision." OFF)
option(USE_ROW_WISE_MATRIX_STORING "Store matrix components by row-wise (in default by column-wise)." OFF)
option(USE_LEFT_HANDED_CORD_SYSTEM "Use left handed Cartesian system. Right handed is default." OFF)
set(CARTESIAN_AXES "XYZ" CACHE STRING "Chose 'Right', 'Up', 'Forward' vectors of Cartesian system. By default its XYZ.")

# ####################################################################################### #
# Promoted cmake options constraints
# ####################################################################################### #

set_property(CACHE CARTESIAN_AXES PROPERTY STRINGS "XYZ;YXZ;ZYX;YZX;XZY;ZXY")

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

if(USE_DOUBLE_PRECISION)
    add_definitions(-DMATH3D_USE_DOUBLE_PRECISION)
endif()

if(USE_ROW_WISE_MATRIX_STORING)
    add_definitions(-DMATH3D_USE_ROW_WISE_MATRIX_STORING)
endif()

if(USE_LEFT_HANDED_CORD_SYSTEM)
    add_definitions(-DMATH3D_USE_LEFT_HANDED_CORD_SYSTEM)
endif()

if(CARTESIAN_AXES STREQUAL ZXY)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_Z)
    add_definitions(-DMATH3D_CARTESIAN_UP_X)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_Y)
    add_definitions(-DMATH3D_CARTESIAN_ZXY)
elseif(CARTESIAN_AXES STREQUAL YXZ)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_Y)
    add_definitions(-DMATH3D_CARTESIAN_UP_X)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_Z)
    add_definitions(-DMATH3D_CARTESIAN_YXZ)
elseif(CARTESIAN_AXES STREQUAL ZYX)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_Z)
    add_definitions(-DMATH3D_CARTESIAN_UP_Y)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_X)
    add_definitions(-DMATH3D_CARTESIAN_ZYX)
elseif(CARTESIAN_AXES STREQUAL YZX)
    add_definitions(-DMATH3D_CARTESIAN_RIGHT_Y)
    add_definitions(-DMATH3D_CARTESIAN_UP_Z)
    add_definitions(-DMATH3D_CARTESIAN_FORWARD_X)
    add_definitions(-DMATH3D_CARTESIAN_YZX)
elseif(CARTESIAN_AXES STREQUAL XZY)
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

if(${BUILD_UNIT_TESTS})
    enable_testing()
    add_subdirectory(develop/tests)
endif()

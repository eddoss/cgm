
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

#add_subdirectory(library)

if(${CGM_BUILD_UNIT_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif()

if(${CGM_BUILD_EXAMPLES})
    add_subdirectory(examples)
endif()


# ####################################################################################### #
# Library target
# ####################################################################################### #

add_library(${PROJECT_NAME} INTERFACE)

# ####################################################################################### #
# Library properties
# ####################################################################################### #

target_include_directories(${PROJECT_NAME} INTERFACE
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)

# --------------------------------------------------------------------------------------- #

if(CGM_USE_DOUBLE_PRECISION)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_USE_DOUBLE_PRECISION)
endif()

# --------------------------------------------------------------------------------------- #

if(CGM_MATRIX_LAYOUT STREQUAL Row)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_MATRIX_LAYOUT=Row)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_ROW_WISE_MATRIX_LAYOUT)
elseif(CGM_MATRIX_LAYOUT STREQUAL Column)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_MATRIX_LAYOUT=Column)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_COLUMN_WISE_MATRIX_LAYOUT)
else()
    message(FATAL_ERROR "[${PROJECT_NAME}]: invalid value of <CGM_MATRIX_LAYOUT> configuration property. It must be <Row> or <Column>.")
endif()

# --------------------------------------------------------------------------------------- #

if(CGM_HANDEDNESS STREQUAL Left)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_HANDEDNESS=Left)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_LEFT_HANDED)
elseif(CGM_HANDEDNESS STREQUAL Right)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_HANDEDNESS=Right)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_RIGHT_HANDED)
else()
    message(FATAL_ERROR "[${PROJECT_NAME}]: invalid value of <CGM_HANDEDNESS> configuration property. It must be <Left> or <Right>.")
endif()

# --------------------------------------------------------------------------------------- #

if(CGM_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL ZXY)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_RIGHT_UP_FORWARD_AXES_LABELS=ZXY)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_RIGHT_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_UP_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_FORWARD_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_ZXY)
elseif(CGM_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL YXZ)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_RIGHT_UP_FORWARD_AXES_LABELS=YXZ)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_RIGHT_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_UP_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_FORWARD_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_YXZ)
elseif(CGM_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL ZYX)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_RIGHT_UP_FORWARD_AXES_LABELS=ZYX)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_RIGHT_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_UP_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_FORWARD_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_ZYX)
elseif(CGM_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL YZX)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_RIGHT_UP_FORWARD_AXES_LABELS=YZX)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_RIGHT_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_UP_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_FORWARD_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_YZX)
elseif(CGM_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL XZY)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_RIGHT_UP_FORWARD_AXES_LABELS=XZY)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_RIGHT_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_UP_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_FORWARD_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_XZY)
elseif(CGM_RIGHT_UP_FORWARD_AXES_LABELS STREQUAL XYZ)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_RIGHT_UP_FORWARD_AXES_LABELS=XYZ)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_RIGHT_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_UP_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_FORWARD_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CARTESIAN_XYZ)
else()
    message(FATAL_ERROR "[${PROJECT_NAME}]: invalid value of <CGM_RIGHT_UP_FORWARD_AXES_LABELS> configuration property. It must be <XYZ>/<YXZ>/<ZYX>/<YZX>/<XZY>/<ZXY>.")
endif()

# --------------------------------------------------------------------------------------- #

if(CGM_MATRIX_MULTIPLICATION_ORDER STREQUAL Pre)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_MATRIX_MULTIPLICATION_ORDER=Pre)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_MATRIX_PRE_MULTIPLICATION)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_ROW_MAJOR)
elseif(CGM_MATRIX_MULTIPLICATION_ORDER STREQUAL Post)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_MATRIX_MULTIPLICATION_ORDER=Post)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_MATRIX_POST_MULTIPLICATION)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_COLUMN_MAJOR)
else()
    message(FATAL_ERROR "[${PROJECT_NAME}]: invalid value of 'CGM_MATRIX_MULTIPLICATION_ORDER' configuration property. It must be <Pre> or <Post>.")
endif()

# ####################################################################################### #
# Installation
# ####################################################################################### #

include(CMakePackageConfigHelpers)

set(ConfigPackageLocation "${CMAKE_INSTALL_PREFIX}/cmake")

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${ConfigPackageLocation}
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION ${ConfigPackageLocation}
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${ConfigPackageLocation}
)

install(
    DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/CGM"
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

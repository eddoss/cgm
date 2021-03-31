# ####################################################################################### #
# Project parameters
# ####################################################################################### #

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# ####################################################################################### #
# Promoted cmake options
# ####################################################################################### #

option(CGMATH_BUILD_UNIT_TESTS "Build unit testing projects." OFF)
option(CGMATH_BUILD_EXAMPLES "Build examples projects." OFF)
option(CGMATH_USE_DOUBLE_PRECISION "Use double floating point number precision." OFF)
set(CGMATH_MATRIX_LAYOUT "Column" CACHE STRING "Store matrix components by rows or columns (Row/Column).")
set(CGMATH_MATRIX_MULTIPLICATION_ORDER "Post" CACHE STRING "If 'Pre' is used vector will be represented as row, if 'Post' - as column.")
set(CGMATH_HANDEDNESS "Right" CACHE STRING "Cartesian system handedness (Right/Left).")
set(CGMATH_UP_AXIS "Y" CACHE STRING "Label of Up axis of Cartesian system (X/Y/Z).")

# ####################################################################################### #
# Promoted cmake options constraints
# ####################################################################################### #

set_property(CACHE CGMATH_UP_AXIS PROPERTY STRINGS "X;Y;Z")
set_property(CACHE CGMATH_MATRIX_MULTIPLICATION_ORDER PROPERTY STRINGS "Pre;Post")
set_property(CACHE CGMATH_MATRIX_LAYOUT PROPERTY STRINGS "Row;Column")
set_property(CACHE CGMATH_HANDEDNESS PROPERTY STRINGS "Left;Right")
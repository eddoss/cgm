# ####################################################################################### #
# Promoted cmake options
# ####################################################################################### #

option(CGM_BUILD_UNIT_TESTS "Build unit testing projects." OFF)
option(CGM_BUILD_EXAMPLES "Build examples projects." OFF)
option(CGM_USE_DOUBLE_PRECISION "Use double floating point number precision." OFF)
set(CGM_MATRIX_LAYOUT "Column" CACHE STRING "Store matrix components by rows or columns (Row/Column).")
set(CGM_MATRIX_MULTIPLICATION_ORDER "Post" CACHE STRING "If 'Pre' is used vector will be represented as row, if 'Post' - as column.")
set(CGM_HANDEDNESS "Right" CACHE STRING "Cartesian system handedness (Right/Left).")
set(CGM_UP_AXIS "Y" CACHE STRING "Label of Up axis of Cartesian system (X/Y/Z).")

# ####################################################################################### #
# Promoted cmake options constraints
# ####################################################################################### #

set_property(CACHE CGM_UP_AXIS PROPERTY STRINGS "X;Y;Z")
set_property(CACHE CGM_MATRIX_MULTIPLICATION_ORDER PROPERTY STRINGS "Pre;Post")
set_property(CACHE CGM_MATRIX_LAYOUT PROPERTY STRINGS "Row;Column")
set_property(CACHE CGM_HANDEDNESS PROPERTY STRINGS "Left;Right")
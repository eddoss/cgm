project(
    Testing
    LANGUAGES CXX
)

if(${MATH3D_BUILD_UNIT_TESTS})
    add_subdirectory(unit)
endif()

project(
    Testing
    LANGUAGES CXX
)

if(${BUILD_UNIT_TESTS})
    add_subdirectory(unit)
endif()
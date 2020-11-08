
project(Examples LANGUAGES CXX)

set(EXAMPLES_RESOURCES_DIR ${CMAKE_CURRENT_LIST_DIR}/Resources)

add_subdirectory(Core)
add_subdirectory(Launchers/Text2D)
add_subdirectory(Launchers/BasicRotations)
add_subdirectory(Launchers/ProjectionFromCamera)
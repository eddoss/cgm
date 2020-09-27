
project(ExamplesCore LANGUAGES CXX)

file(GLOB_RECURSE SOURCES_FILES ${CMAKE_CURRENT_LIST_DIR}/sources/*.cpp)

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

add_library(${PROJECT_NAME} STATIC ${SOURCES_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw GLEW::GLEW ComputerGraphixMath)
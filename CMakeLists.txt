# ####################################################################################### #
# Init project
# ####################################################################################### #

cmake_minimum_required(VERSION 3.18)

project(CGM
    LANGUAGES CXX
    VERSION 0.9.1
)

# ####################################################################################### #
# Project parameters
# ####################################################################################### #

include(cmake/Parameters.cmake)

# ####################################################################################### #
# Subprojects
# ####################################################################################### #

add_subdirectory(CGM)
add_subdirectory(tests)
add_subdirectory(examples)

# ####################################################################################### #
# Installation
# ####################################################################################### #

include(cmake/Installation.cmake)

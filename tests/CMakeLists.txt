
# ##################################################################################### #
# This function help you add tests based on GoogleTest framework.
# You need find GTest package before to call this function.
# It create executable target and setup it with GTest libraries
# and include directories.
#
# TARGET    - name of the created target
# RUNNER    - .cpp file running tests
# SOURCES   - tests list
# ##################################################################################### #

function(cgm_add_test TARGET SOURCES)
    add_executable(${TARGET} ${SOURCES})
    target_link_libraries(${TARGET}
        PRIVATE
            GTest::GTest
            GTest::Main
        PUBLIC
            ComputerGraphixMath
    )
    add_test(NAME ${TARGET} COMMAND ${TARGET})
endfunction()

# ####################################################################################### #
# Init test project
# ####################################################################################### #

project(UnitTests LANGUAGES CXX)
find_package(GTest REQUIRED)

# ####################################################################################### #
# Setup libraries output dir
# ####################################################################################### #

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# ####################################################################################### #
# SUITES | Core
# ####################################################################################### #

set(TS_CORE_VECTOR
    Core/Vector/Getters.cpp
    Core/Vector/Functions.cpp
    Core/Vector/Arithmetic.cpp
    Core/Vector/ComparisonWithOther.cpp
    Core/Vector/ComparisonWithScalar.cpp
)

set(TS_CORE_MATRIX
    Core/Matrix/Access.cpp
    Core/Matrix/Functions.cpp
    Core/Matrix/Arithmetic/Plus.cpp
    Core/Matrix/Arithmetic/Minus.cpp
    Core/Matrix/Arithmetic/IncrementDecrement.cpp
    Core/Matrix/Arithmetic/DivisionByScalar.cpp
    Core/Matrix/Arithmetic/MultiplicationToScalar.cpp
    Core/Matrix/Arithmetic/MatrixMultiplication1NxN1.cpp
    Core/Matrix/Arithmetic/MatrixMultiplication.cpp
    Core/MatrixVectorMultiplication.cpp
    Core/Matrix/Comparison/WithOther.cpp
    Core/Matrix/Comparison/WithScalar.cpp
    Core/Matrix/Iterators/Direct.cpp
    Core/Matrix/Iterators/Indirect.cpp
    Core/Matrix/Iterators/RowDir.cpp
    Core/Matrix/Iterators/ColumnDir.cpp
    Core/Matrix/Iterators/Row.cpp
    Core/Matrix/Iterators/Column.cpp
)

set(TS_MODULE_CORE
    "${TS_CORE_VECTOR}"
    "${TS_CORE_MATRIX}"
    "${TS_CORE_COORDINATES}"
)

cgm_add_test(ModuleCoreTestSuite         "run.cpp;${TS_MODULE_CORE}")
cgm_add_test(Core-VectorTestSuite        "run.cpp;${TS_CORE_VECTOR}")
cgm_add_test(Core-MatrixTestSuite        "run.cpp;${TS_CORE_MATRIX}")
cgm_add_test(Core-QuaternionTestSuite    "run.cpp;${TS_CORE_QUATERNION}")

# ####################################################################################### #
# SUITES | Coordinates
# ####################################################################################### #

set(TS_MODULE_COORDINATES
    Coordinates.cpp
)

cgm_add_test(ModuleCoordinatesTestSuite "run.cpp;${TS_MODULE_COORDINATES}")

# ####################################################################################### #
# SUITES | Cartesian
# ####################################################################################### #

set(TS_CARTESIAN_2D
    Cartesian/2D/Functions/Axes.cpp
    Cartesian/2D/Functions/Utils.cpp
    Cartesian/2D/Functions/Orientation.cpp
    Cartesian/2D/Functions/Converters/Vector/WorldToLocal.cpp
    Cartesian/2D/Functions/Converters/Vector/LocalToWorld.cpp
    Cartesian/2D/Functions/Converters/Vector/LocalToLocal/Matrix3.cpp
    Cartesian/2D/Functions/Converters/Vector/LocalToLocal/Matrix2.cpp
    Cartesian/2D/Functions/Converters/Matrix2x2/WorldToLocal.cpp
    Cartesian/2D/Functions/Converters/Matrix2x2/LocalToWorld.cpp
    Cartesian/2D/Functions/Converters/Matrix2x2/LocalToLocal/Matrix3.cpp
    Cartesian/2D/Functions/Converters/Matrix2x2/LocalToLocal/Matrix2.cpp
    Cartesian/2D/Functions/Converters/Matrix3x3/WorldToLocal.cpp
    Cartesian/2D/Functions/Converters/Matrix3x3/LocalToWorld.cpp
    Cartesian/2D/Functions/Converters/Matrix3x3/LocalToLocal/Matrix3.cpp
    Cartesian/2D/Functions/Converters/Matrix3x3/LocalToLocal/Matrix2.cpp
)

set(TS_CARTESIAN_3D
    Cartesian/3D/Operators.cpp
    Cartesian/3D/Functions/Axes.cpp
    Cartesian/3D/Functions/Utils.cpp
    Cartesian/3D/Functions/Quaternion.cpp
    Cartesian/3D/Functions/Orientation.cpp
    Cartesian/3D/Functions/Converters/Vector/WorldToLocal.cpp
    Cartesian/3D/Functions/Converters/Vector/LocalToWorld.cpp
    Cartesian/3D/Functions/Converters/Vector/LocalToLocal/Matrix3.cpp
    Cartesian/3D/Functions/Converters/Vector/LocalToLocal/Matrix4.cpp
    Cartesian/3D/Functions/Converters/Vector/LocalToLocal/Quaternion.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/WorldToLocal.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/LocalToWorld.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/LocalToLocal/Matrix3.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/LocalToLocal/Matrix4.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/LocalToLocal/Quaternion.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/WorldToLocal.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/LocalToWorld.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/LocalToLocal/Matrix3.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/LocalToLocal/Matrix4.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/LocalToLocal/Quaternion.cpp
)

set(TS_MODULE_CARTESIAN
    ${TS_CARTESIAN_2D}
    ${TS_CARTESIAN_3D}
)

cgm_add_test(ModuleCartesianTestSuite "run.cpp;${TS_MODULE_CARTESIAN}")
cgm_add_test(Cartesian2DTestSuite "run.cpp;${TS_CARTESIAN_2D}")
cgm_add_test(Cartesian3DTestSuite "run.cpp;${TS_CARTESIAN_3D}")

# ####################################################################################### #
# SUITES | Cartesian
# ####################################################################################### #

set(TS_TRANSFORMATION_3D
    Transformations/3D/Apply.cpp
    Transformations/3D/Translation.cpp
    Transformations/3D/Scale.cpp
    Transformations/3D/Rotate.cpp
    Transformations/3D/Reflect.cpp
    Transformations/3D/Refract.cpp
    Transformations/3D/Transform.cpp
)

set(TS_TRANSFORMATION_2D
    Transformations/2D/Apply.cpp
    Transformations/2D/Translation.cpp
    Transformations/2D/Scale.cpp
    Transformations/2D/Rotate.cpp
    Transformations/2D/Reflect.cpp
    Transformations/2D/Refract.cpp
    Transformations/2D/Transform.cpp
)

set(TS_MODULE_TRANSFORMATION
    ${TS_TRANSFORMATION_2D}
    ${TS_TRANSFORMATION_3D}
)

cgm_add_test(Transformation2DTestSuite "run.cpp;${TS_TRANSFORMATION_2D}")
cgm_add_test(Transformation3DTestSuite "run.cpp;${TS_TRANSFORMATION_3D}")
cgm_add_test(ModuleTransformationTestSuite "run.cpp;${TS_MODULE_TRANSFORMATION}")

# ####################################################################################### #
# SUITES | All modules
# ####################################################################################### #

set(TS_ALL_MODULES
    ${TS_MODULE_CORE}
    ${TS_MODULE_COORDINATES}
    ${TS_MODULE_CARTESIAN}
    ${TS_MODULE_TRANSFORMATION}
)

cgm_add_test(AllModulesTestSuites  "${TS_ALL_MODULES}")
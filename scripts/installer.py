import os


def generate(properties, source_dir, build_dir):
    cmd = f'cmake -S {source_dir} -B {build_dir} -G "Visual Studio 15 2017" -A x64'
    for prop in properties:
        cmd += f" -D{prop}={props[prop]}"
    os.system(cmd)


def build(build_dir, config, target):
    cmd = f'cmake --build {build_dir} --target {target} --config {config}'
    os.system(cmd)


def install(build_dir, config):
    cmd = f'cmake --build {build_dir} --target INSTALL --config {config}'
    os.system(cmd)


dir_root = os.path.abspath(os.path.join(os.getcwd(), '../'))
dir_source = dir_root
dir_install = os.path.join(dir_root, 'install')
dir_build = os.path.join(dir_install, 'build')

props = {
    "CMAKE_INSTALL_PREFIX":                 dir_install,
    "CGMATH_BUILD_UNIT_TESTS":              "OFF",
    "CGMATH_BUILD_EXAMPLES":                "OFF",
    "CGMATH_USE_DOUBLE_PRECISION":          "OFF",
    "CGMATH_MATRIX_LAYOUT":                 "Column",
    "CGMATH_MATRIX_MULTIPLICATION_ORDER":   "Post",
    "CGMATH_HANDEDNESS":                    "Right",
    "CGMATH_UP_AXIS":                       "Y",
}

generate(props, dir_source, dir_build)
install(dir_build, "Release")

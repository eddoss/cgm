import os
import shutil


def clear(dir: str):
    shutil.rmtree(dir, True)

def build(labels, mat_mult, handedness, matrix_storing, double_precis):
    root = os.path.abspath(os.path.join(os.getcwd(), '../'))
    source_dir = root
    install_dir = os.path.join(root, 'install')
    build_dir = os.path.join(install_dir, 'build')

    props = {
        "CMAKE_INSTALL_PREFIX": install_dir,
        "CGM_BUILD_UNIT_TESTS": "OFF",
        "CGM_BUILD_EXAMPLES": "OFF",
        "CGM_USE_DOUBLE_PRECISION": double_precis,
        "CGM_MATRIX_LAYOUT": matrix_storing,
        "CGM_HANDEDNESS": handedness,
        "CGM_RIGHT_UP_FORWARD_AXES_LABELS": labels,
        "CGM_MATRIX_MULTIPLICATION_ORDER": mat_mult
    }

    cmd_gen = f'cmake -S {source_dir} -B {build_dir} -G "Visual Studio 15 2017" -A x64'
    for prop in props:
        cmd_gen += f" -D{prop}={props[prop]}"

    cmd_install = f'cmake --build {build_dir} --target INSTALL --config Release'

    # clear(build_dir)
    # clear(install_dir)

    os.system(cmd_gen)
    os.system(cmd_install)

build('XYZ', 'Post', 'Right', 'Column', 'OFF')
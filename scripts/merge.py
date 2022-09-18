import os
import pathlib

from common.paths import PATHS
from common import utils

for item in utils.walk(PATHS.develop, with_dirs=False):
    try:
        if item.extension == ".inl":
            inl_file = item.path
            src_file = pathlib.Path(item.root) / item.body / (item.name + ".hpp")

            with open(inl_file, 'r') as stream:
                inl_text = stream.read()
                inl_text = inl_text.replace(f'#include "{item.name}.hpp"', "")
                inl_text = inl_text.strip()
                inl_text = inl_text.strip('\n')
                namespace = inl_text[:inl_text.find('\n')+1]
                if "CGM_" in namespace and "_NAMESPACE" in namespace:
                    namespace = namespace.strip()
                    if namespace.endswith("_BEGIN"):
                        namespace = namespace[:-6]
                    inl_text = inl_text[len(namespace + "_BEGIN"):]
                    inl_text = inl_text.strip()
                    inl_text = inl_text.strip("\n")
                else:
                    namespace = ""

            with open(src_file, 'r') as stream:
                src_text = stream.read()
                src_text = src_text.replace(f'#include "{item.name}.inl"', "")
                src_text = src_text.strip()
                src_text = src_text.strip("\n")
                if namespace:
                    src_text = src_text[:-len(namespace + "_END")]
                    src_text = src_text.strip()
                    src_text = src_text.strip("\n")

            src_text += "\n\n\n"
            src_text += "/* ####################################################################################### */\n"
            src_text += "/* ####################################################################################### */\n"
            src_text += "/*                                      DEFINITION                                         */\n"
            src_text += "/* ####################################################################################### */\n"
            src_text += "/* ####################################################################################### */"
            src_text += "\n\n\n"

            src_text += inl_text
            src_text += "\n"

            with open(src_file, 'w') as stream:
                stream.write(src_text)
            os.remove(inl_file)
            print("OK", src_file)
    except(Exception) as err:
        print(f"FAILED: {err}")

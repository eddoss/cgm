import os
import pathlib
import subprocess
import sys
from pathlib import Path
from typing import Optional


def shell(cmd: str, pwd: Optional[Path] = None, log_prefix='') -> int:
    with subprocess.Popen(
        args=cmd,
        stdout=subprocess.PIPE,
        universal_newlines=True,
        cwd=pwd,
        shell=True
    ) as proc:
        while proc.poll() is None:
            if proc.stdout:
                line = proc.stdout.readline()
                if line != "":
                    print(log_prefix + line.rstrip())
            if proc.stderr:
                line = proc.stderr.readline()
                if line != "":
                    print(log_prefix + line.rstrip(), file=sys.stderr)
        return proc.returncode


class WalkerItem:
    @property
    def root(self) -> pathlib.Path:
        return self._root

    @property
    def body(self) -> str:
        return self._body

    @property
    def full_body(self) -> str:
        if self.body:
            return f'{self.body}/{self.full_name}'
        else:
            return f'{self.full_name}'

    @property
    def name(self) -> str:
        return self._name

    @property
    def full_name(self) -> str:
        return self.name + self.extension

    @property
    def extension(self) -> str:
        return self._ext

    @property
    def path(self) -> pathlib.Path:
        return self.root / self.full_body

    def __init__(self, root: pathlib.Path, body: str, name: str, ext: str):
        self._root = root
        self._body = body
        self._name = name
        self._ext = ext


def walk(root: pathlib.Path, with_files=True, with_dirs=True, recursive=True):
    """
    Recursively walk by given directory.
    :param with_files: Include files or not.
    :param with_dirs: Include directories or not.
    :param root: Path to directory.
    :return: WalkerItem generator.
    :param recursive: Walk subdirectory or not.
    """
    root_size = len(root.resolve().absolute().as_posix())
    if recursive:
        for path, dirs, files in os.walk(root):
            body = path[root_size + 1:]
            if with_files:
                for name in files:
                    yield WalkerItem(root, body, *os.path.splitext(name))
            if with_dirs:
                for name in dirs:
                    if name not in ['.DS_Store']:
                        yield WalkerItem(root, body, name, '')
    else:
        for name in os.listdir(root):
            if with_dirs and os.path.isdir(f'{root}/{name}'):
                yield WalkerItem(root, '', name, '')
            elif with_files and os.path.isfile(f'{root}/{name}'):
                yield WalkerItem(root, '', *os.path.splitext(name))

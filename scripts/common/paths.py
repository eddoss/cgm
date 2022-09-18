from pathlib import Path


class Paths:
    @property
    def root(self) -> Path:
        return Path(__file__).parent.parent.parent

    @property
    def dependencies(self) -> Path:
        return self.root / 'dependencies'

    @property
    def examples(self) -> Path:
        return self.root / 'examples'

    @property
    def build(self) -> Path:
        return self.root / 'build'

    @property
    def develop(self) -> Path:
        return self.root / 'CGM'

    @property
    def tests(self) -> Path:
        return self.root / 'tests'


PATHS = Paths()

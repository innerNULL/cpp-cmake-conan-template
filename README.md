Cpp Project Template With Conan + CMake + Conda

## Overview

As titled.

## Build Example

### Initialize Conda Environment

```shell
conda/micromamba env create -f environment.yaml -p ./_venv --yes
conda/micromamba env update -f environment.yaml -p ./_venv --yes
conda/micromamba activate ./_venv
```

### Building Example Lib and Bin
```shell
conan install . -pr=./conan_profiles/default --output-folder=build --build=missing -s build_type=Release # or build_type=Debug

cmake -DDUMMY_COMPILE_OPTION=ON --preset conan-release # or -DDUMMY_COMPILE_OPTION=OFF --preset conan-debug

cmake --build --preset conan-release # or --preset conan-debug
```

## Run Example
Run bin:
```shell
./build/build/Release/example
```

Run test:
```shell
./build/build/Release/test/test
```

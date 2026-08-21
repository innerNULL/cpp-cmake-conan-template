Cpp Project Template With Conan + CMake + Conda

## Overview

As titled. This template can help you convieniently start a new C++ project using Conan, CMake, 
and Conda for:

* C++ libraries organization and isolation.
* Dependency management via Conan and CMake (sometimes).
* Easy integration with Python bindings.
* Quick unit-test development.

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

Using our pre-built example bin, library and binding as example:

* Compiled bin location: `./build/build/Release/example` 
* Compiled static library location: `./build/build/Release/libexample_lib.a`
* Compiled library Python binding location: `./build/build/Release/bindings/python/example_lib/py_example_lib.*`

## Run Examples

Run bin:

```shell
./build/build/Release/example
```

Run test:

```shell
./build/build/Release/test/test
```

Try example libraries's Python binding:
```shell
cp ./build/build/Release/bindings/python/example_lib/py_example_lib.* ./

python -c "
import py_example_lib

a = py_example_lib.add(1, 2)
b = py_example_lib.Bot()
c = b.move_to('up')

print(a)
print(b)
print(c)
"
```

## Template Structure Design

All C++ source codes should be under `./src`, where `./src/bin` are the source codes of 
C++ programs which depend on one or multiple libraries which source codes are located at 
else folders `./src/*`. So besides `./src/bin`, all else are `./src/${CPP_LIB_NAME}`.

As a lot of C++ libraries need to export a python binding for quick development purpose, 
you can find example Python binding definitions under `./bindings`, grouped by different 
programming languages. The organization of this directory is similar with `./src`, each 
C++ libraries' binding has its own folder and building logics defined in `CMakeLists.txt` here. 
So the folders under `./bindings` are organized as `./bindings/${LANGUAGE}/${CPP_LIB_NAME}`.


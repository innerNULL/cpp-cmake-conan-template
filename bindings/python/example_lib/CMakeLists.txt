# file: CMakeLists.txt
# date: 2026-08-21


cmake_minimum_required(VERSION 3.15)


find_package(pybind11)
find_package(pybind11_json)


pybind11_add_module(py_example_lib ${CMAKE_CURRENT_SOURCE_DIR}/src/pymodule.cpp)
target_link_libraries(py_example_lib PRIVATE example_lib external_deps) 

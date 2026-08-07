/// file: example.cpp
/// date: 2026-08-07


#include <fmt/base.h>

#include "example.h"

using cpp_cmake_conan_template::example_lib::example::add;


int main(int argc, char** argv) {
  fmt::print("The answer of 1 + 1 = {}\n", add(1, 1));
  return 0;
}

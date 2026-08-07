/// file: test_example.h
/// date: 2026-08-07


#include <optional>
#include <string>
#include <vector>
#include <memory>

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

#include "example.h"

using cpp_cmake_conan_template::example_lib::example::add;


TEST(example_lib__example__add, Case0) {
  ASSERT_TRUE(add(1, 2) == 3);
}

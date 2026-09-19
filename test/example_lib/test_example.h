/// file: test_example.h
/// date: 2026-08-07


#include <optional>
#include <string>
#include <vector>
#include <memory>

#include <Eigen/Dense>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

#include "example.h"

using cpp_cmake_conan_template::example_lib::example::add;
using cpp_cmake_conan_template::example_lib::example::Bot;


TEST(example_lib__example__add, Case0) {
  ASSERT_TRUE(add(1, 2) == 3);
}


TEST(example_lib__example__Bot__sum_matrix, Case0) {
  Bot bot{.name = "test_bot"};
  Eigen::MatrixXd mat(2, 2);
  mat << 1.0, 2.0,
         3.0, 4.0;
  ASSERT_DOUBLE_EQ(bot.sum_matrix(mat), 10.0);
}

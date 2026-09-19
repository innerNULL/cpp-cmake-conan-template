/// file: example.cpp
/// date: 2026-08-07


#include "./include/example.h"


namespace cpp_cmake_conan_template {
namespace example_lib {
namespace example {


BotStatus Bot::move_to(const std::string& direction) {
  return BotStatus { .live = true };
}


double Bot::sum_matrix(const Eigen::MatrixXd& mat) const {
  return mat.sum();
}


int32_t add(const int32_t a, const int32_t b) {
  return a + b;
}


} // example.h/cpp
} // example_lib
} // cpp_cmake_conan_template

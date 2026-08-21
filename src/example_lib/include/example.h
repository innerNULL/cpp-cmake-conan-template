/// file: example.h
/// date: 2026-08-07


#include <cstdint>
#include <string>


namespace cpp_cmake_conan_template {
namespace example_lib {
namespace example {



struct BotStatus {
  bool live;
};


struct Bot {
  std::string name;

  BotStatus move_to(const std::string& direction);
};


int32_t add(const int32_t a, const int32_t b);


} // example.h/cpp
} // example_lib
} // cpp_cmake_conan_template

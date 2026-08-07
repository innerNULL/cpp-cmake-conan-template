cmake_minimum_required(VERSION 3.15)
project(cpp-cmake-conan-template)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/v1.17.x.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
  test
  test.cpp
)
target_link_libraries(test PRIVATE example_lib external_deps GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test)



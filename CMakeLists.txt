cmake_minimum_required(VERSION 3.15)
project(cpp-cmake-conan-template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(DUMMY_COMPILE_OPTION "Dummy compile option" OFF)
if (DUMMY_COMPILE_OPTION)
  message(STATUS "[cmake] Setting dummy compile option to ON")
  add_compile_definitions(DUMMY_COMPILE_OPTION)
else()
  message(STATUS "[cmake] Setting dummy compile option to OFF")
endif()


find_package(absl)
find_package(fmt)
find_package(glaze)
find_package(nlohmann_json)
find_package(spdlog)


add_library(external_deps INTERFACE)
target_link_libraries(external_deps INTERFACE 
  abseil::abseil
  glaze::glaze
  nlohmann_json::nlohmann_json
  spdlog::spdlog 
  fmt::fmt
)

add_library(example_lib 
  ${CMAKE_SOURCE_DIR}/src/example_lib/example.cpp
)
target_include_directories(example_lib PUBLIC
  ${CMAKE_SOURCE_DIR}/src/example_lib/include 
)
target_compile_definitions(example_lib PRIVATE _FORTIFY_SOURCE=3)
target_link_libraries(example_lib PRIVATE external_deps)
target_compile_options(example_lib PRIVATE
  -Wall -Wextra -Wpedantic
  -Wconversion -Wsign-conversion
  -Wshadow -Wformat=2 -Wundef
  -fno-omit-frame-pointer -fstack-protector-strong 
)

add_executable(example ${CMAKE_SOURCE_DIR}/src/bin/example.cpp)
target_link_libraries(example PRIVATE example_lib external_deps)
target_link_options(example PRIVATE -Wl,--start-group -Wl,--end-group)


add_subdirectory(${CMAKE_SOURCE_DIR}/test)

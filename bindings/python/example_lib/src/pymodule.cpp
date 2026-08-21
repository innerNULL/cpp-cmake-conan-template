/// file: pymodule.cpp
/// date: 2026-08-21


#include <fmt/base.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "example.h"

namespace py = pybind11;

using cpp_cmake_conan_template::example_lib::example::Bot;
using cpp_cmake_conan_template::example_lib::example::BotStatus;
using cpp_cmake_conan_template::example_lib::example::add;


void bot_status_pybind(py::module &m) {
  py::class_<BotStatus>(m, "BotStatus")
      .def(py::init<>());
}


void bot_pybind(py::module &m) {
  py::class_<Bot>(m, "Bot")
      .def(py::init<>())
      .def("move_to", &Bot::move_to);
}


void add_pybind(py::module &m) {
  m.def("add", &add, "A function that adds two numbers");
}


PYBIND11_MODULE(py_example_lib, m) {
  bot_status_pybind(m);
  bot_pybind(m);
  add_pybind(m);
}

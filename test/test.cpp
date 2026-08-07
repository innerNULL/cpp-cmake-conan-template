// file: test.cpp
// date: 2025-10-22


#include <optional>
#include <string>
#include <vector>

#include "spdlog/spdlog.h"
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

#include "./example_lib/test_example.h"


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    spdlog::set_level(spdlog::level::off);
    return RUN_ALL_TESTS();
}

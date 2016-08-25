#pragma once

#include <gtest/gtest.h>

#include <array>

template <class T>
class SortTest : public ::testing::Test {

};

TYPED_TEST_CASE_P(SortTest);

TYPED_TEST_P(SortTest, AscendingInt) {
  std::array<int, 7> data{3, 1, 4, 1, 5, 9, 2};

  using sort_function_fn = TypeParam;
  sort_function_fn()(data.begin(), data.end());

  for (std::size_t i = 1; i < data.size(); ++i) {
    EXPECT_LE(data[i - 1], data[i]);
  }
}

REGISTER_TYPED_TEST_CASE_P(SortTest, AscendingInt);

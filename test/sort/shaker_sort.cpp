#include "sort_test.hpp"

#include <cxxalgo/sort/shaker_sort.hpp>

INSTANTIATE_TYPED_TEST_CASE_P(
  BubbleSortTest,
  SortTest,
  ::testing::Types<cxxalgo::sort::shaker_sort_fn>
);

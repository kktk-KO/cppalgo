#include "sort_test.hpp"

#include <cxxalgo/sort/quick_sort.hpp>

INSTANTIATE_TYPED_TEST_CASE_P(
  BubbleSortTest,
  SortTest,
  ::testing::Types<cxxalgo::sort::quick_sort_fn>
);

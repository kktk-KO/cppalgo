#include "sort_test.hpp"

#include <cxxalgo/sort/merge_sort.hpp>

INSTANTIATE_TYPED_TEST_CASE_P(
  BubbleSortTest,
  SortTest,
  ::testing::Types<cxxalgo::sort::merge_sort_fn>
);

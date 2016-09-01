#include "sort_test.hpp"

#include <cxxalgo/sort/bogo_sort.hpp>

INSTANTIATE_TYPED_TEST_CASE_P(
  BubbleSortTest,
  SortTest,
  ::testing::Types<cxxalgo::sort::bogo_sort_fn>
);

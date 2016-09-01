#include "sort_test.hpp"

#include <cxxalgo/sort/comb_sort.hpp>

INSTANTIATE_TYPED_TEST_CASE_P(
  BubbleSortTest,
  SortTest,
  ::testing::Types<cxxalgo::sort::comb_sort_fn>
);

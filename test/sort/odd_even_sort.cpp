#include "sort_test.hpp"

#include <cxxalgo/sort/odd_even_sort.hpp>

INSTANTIATE_TYPED_TEST_CASE_P(
  BubbleSortTest,
  SortTest,
  ::testing::Types<cxxalgo::sort::odd_even_sort_fn>
);

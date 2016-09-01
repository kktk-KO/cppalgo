#include "sort_test.hpp"

#include <cxxalgo/sort/gnome_sort.hpp>

INSTANTIATE_TYPED_TEST_CASE_P(
  BubbleSortTest,
  SortTest,
  ::testing::Types<cxxalgo::sort::gnome_sort_fn>
);

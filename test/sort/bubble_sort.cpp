#include "sort_test.hpp"

#include <cxxalgo/sort/bubble_sort.hpp>

INSTANTIATE_TYPED_TEST_CASE_P(
  BubbleSortTest,
  SortTest,
  ::testing::Types<cxxalgo::sort::bubble_sort_fn>
);

TEST(BubbleSortTest, AlwaysFail) {
  EXPECT_EQ(true, false);
}

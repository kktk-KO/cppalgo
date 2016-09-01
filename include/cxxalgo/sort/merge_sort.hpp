#pragma once

#include <algorithm>

namespace cxxalgo { namespace sort {

template <class Iterator, class Compare>
void merge_sort (Iterator first, Iterator last, Compare const & comp) {
  auto size = std::distance(first, last);

  for (decltype(size) i = 0; i < size; ++i) {
    for (decltype(size) j = 1; j < size - i; ++j) {
      if (!comp(first[j - 1], first[j])) {
        std::swap(first[j - 1], first[j]);
      }
    }
  }
}

template <class Iterator>
void merge_sort (Iterator first, Iterator last) {
  using value_type = decltype(*first);
  merge_sort(first, last, [] (value_type const & left, value_type const & right) {
    return left < right;
  }); 
}

struct merge_sort_fn {

  template <class Iterator, class Compare>
  void operator() (Iterator first, Iterator last, Compare const & comp) {
    merge_sort(first, last, comp);
  }

  template <class Iterator>
  void operator() (Iterator first, Iterator last) {
    merge_sort(first, last);
  }

};

}}

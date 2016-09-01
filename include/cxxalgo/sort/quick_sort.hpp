#pragma once

#include <algorithm>

namespace cxxalgo { namespace sort {

template <class Iterator, class Compare>
void quick_sort (Iterator first, Iterator last, Compare const & comp) {
  if (first == last) { return; }

  auto size = std::distance(first, last);
  auto x = first[0];
  auto y = first[size / 2];
  auto z = first[size - 1];

  decltype(*first) pivot = (comp(x, y) ? (comp(y, z) ? y : z) : (comp(x, z) ? x : z));

  decltype(size) i = 0;
  decltype(size) j = size - 1;
  while (true) {
    while (comp(first[i], pivot)) {
     ++i;
    }
    while (comp(pivot, first[j])) {
      --j;
    }
    if (i >= j) { break; }
    std::swap(first[i], first[j]);
    ++i;
    --j;
  }
  quick_sort(first, first + i, comp);
  quick_sort(first + j + 1, last, comp);
}

template <class Iterator>
void quick_sort (Iterator first, Iterator last) {
  using value_type = decltype(*first);
  quick_sort(first, last, [] (value_type const & left, value_type const & right) {
    return left < right;
  }); 
}

struct quick_sort_fn {

  template <class Iterator, class Compare>
  void operator() (Iterator first, Iterator last, Compare const & comp) {
    quick_sort(first, last, comp);
  }

  template <class Iterator>
  void operator() (Iterator first, Iterator last) {
    quick_sort(first, last);
  }

};

}}

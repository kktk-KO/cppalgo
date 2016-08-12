#pragma once

#include <algorithm>

namespace cxxalgro { namespace sort {

template <class Iterator, class Compare>
void quick_sort (Iterator first, Iterator last, Compare const & comp) {
  if (first == last) { return; }

  auto size = std::distance(first, last);
  auto x = first[0];
  auto y = first[size / 2];
  auto z = first[size - 1];

  decltype(*first) pivot = (x > y ? (y > z ? y : z) : (x > z ? x : z));

  decltype(size) i = 0;
  decltype(size) j = size - 1;
  while (true) {
    while(first[i] < pivot) { ++i; }
    while(pivot < first[j]) { --j; }
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

}}

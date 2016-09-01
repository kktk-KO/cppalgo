#pragma once

#include <algorithm>

namespace cxxalgo { namespace sort {

template <class Iterator, class Compare>
void shaker_sort (Iterator first, Iterator last, Compare const & comp) {

  bool toggle = true;
  while (first != last) {
    auto size = std::distance(first, last);
    if (toggle) {
      decltype(size) j = 0;
      for (decltype(size) i = 0; i < size; ++i) {
        if (!comp(first[i - 1], first[i])) {
            std::swap(first[i - 1], first[i]);
            j = i;
        }
      }
      last = first + j;
    } else {
      decltype(size) j = 0;
      for (decltype(size) i = size - 1; i >= 0; --i) {
        if (!comp(first[i - 1], first[i])) {
            std::swap(first[i - 1], first[i]);
            j = i;
        }
      }
      first = first + j;

    }
    toggle = !toggle;
  }
}

template <class Iterator>
void shaker_sort (Iterator first, Iterator last) {
  using value_type = decltype(*first);
  shaker_sort(first, last, [] (value_type const & left, value_type const & right) {
    return left < right;
  }); 
}

struct shaker_sort_fn {

  template <class Iterator, class Compare>
  void operator() (Iterator first, Iterator last, Compare const & comp) {
    shaker_sort(first, last, comp);
  }

  template <class Iterator>
  void operator() (Iterator first, Iterator last) {
    shaker_sort(first, last);
  }

};

}}

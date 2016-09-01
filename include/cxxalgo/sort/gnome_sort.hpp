#pragma once

#include <algorithm>

namespace cxxalgo { namespace sort {

template <class Iterator, class Compare>
void gnome_sort (Iterator first, Iterator last, Compare const & comp) {
  auto size = std::distance(first, last);
  decltype(size) i = 1;
  while (i < size) {
    if (!comp(first[i], first[i - 1])) {
      ++i;
    } else {
      std::swap(first[i - 1], first[i]);
      --i;
      if (i == 0) { i = 1; }
    }
  }
}

template <class Iterator>
void gnome_sort (Iterator first, Iterator last) {
  using value_type = decltype(*first);
  gnome_sort(first, last, [] (value_type const & left, value_type const & right) {
    return left < right;
  }); 
}

struct gnome_sort_fn {

  template <class Iterator, class Compare>
  void operator() (Iterator first, Iterator last, Compare const & comp) {
    gnome_sort(first, last, comp);
  }

  template <class Iterator>
  void operator() (Iterator first, Iterator last) {
    gnome_sort(first, last);
  }

};

}}

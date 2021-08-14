#pragma once

#include <cmath>

namespace upp {
namespace types {

template <class Pack, auto Filter>
struct select_one;

template <auto F, auto... Vs, auto Filter>
struct select_one<value_pack<F, Vs...>, Filter> {
  static constexpr auto value = []() {
    if constexpr (sizeof...(Vs)) {
      return Filter(F, select_one<value_pack<Vs...>, Filter>::value);
    } else {
      return F;
    }
  }();
};

/**
 * Select one value from the pack using a given filter
 *
 * \tparam Pack value_pack that is filtered
 * \tparam Filter that takes two arguments and returns the more fitting one.
 *  This is called recursively to select one value.
 *
 */
template <class Pack, auto Filter>
constexpr auto select_one_v = select_one<Pack, Filter>::value;

namespace detail {
constexpr auto max_cmp = [](const auto& a, const auto& b) {
  return a > b ? a : b;
};

constexpr auto min_cmp = [](const auto& a, const auto& b) {
  return a < b ? a : b;
};
}  // namespace detail

template <class Pack>
constexpr auto max_v = select_one_v<Pack, detail::max_cmp>;

template <class Pack>
constexpr auto min_v = select_one_v<Pack, detail::min_cmp>;

}  // namespace types
}  // namespace upp

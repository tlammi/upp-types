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

template <class Pack, auto Filter>
constexpr auto select_one_v = select_one<Pack, Filter>::value;

}  // namespace types
}  // namespace upp

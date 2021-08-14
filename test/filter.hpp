#pragma once

#include <type_traits>

#include "upp/types.hpp"

using namespace upp::types;

namespace value_test {
using Input = value_pack<0, 'c', 100.0>;

using Expected = value_pack<0>;

constexpr auto filter_cb = [](auto v) {
  if constexpr (std::is_same_v<decltype(v), int>) {
    return true;
  } else {
    return false;
  }
};

static_assert(std::is_same_v<filter_t<Input, filter_cb>, Expected>);

using Expected2 = value_pack<0, 'c'>;

constexpr auto filter_cb2 = [](auto v) {
  if constexpr (std::is_same_v<decltype(v), double>) {
    return false;
  } else {
    return true;
  }
};

static_assert(std::is_same_v<filter_t<Input, filter_cb2>, Expected2>);
}  // namespace value_test

namespace type_test {

using Input = pack<int, float, double, char>;

using Expected = pack<float>;

constexpr auto filter_cb = [](auto i) {
  if constexpr (std::is_same_v<decltype(i), float>) {
    return keep;
  } else {
    return remove;
  }
};

static_assert(std::is_same_v<filter_t<Input, filter_cb>, Expected>);

using Expected2 = pack<int, char>;

constexpr auto filter_cb2 = [](auto i) {
  if constexpr (std::is_same_v<decltype(i), int>) {
    return keep;
  } else if constexpr (std::is_same_v<decltype(i), char>) {
    return keep;
  } else {
    return remove;
  }
};

static_assert(std::is_same_v<filter_t<Input, filter_cb2>, Expected2>);

}  // namespace type_test

#pragma once

#include "upp/types/bits/pack.hpp"

namespace upp {
namespace types {

template <class T, class Pack>
struct is_type_in_pack;

template <class T, class F, class... Ts>
struct is_type_in_pack<T, pack<F, Ts...>> {
  static constexpr bool value =
      std::is_same_v<T, F> || is_type_in_pack<T, pack<Ts...>>::value;
};

template <class T>
struct is_type_in_pack<T, pack<>> {
  static constexpr bool value = false;
};

template <class T, class Pack>
constexpr bool is_type_in_pack_v = is_type_in_pack<T, Pack>::value;

template <auto V, class Pack>
struct is_value_in_pack;

template <auto V, auto F, auto... Vs>
struct is_value_in_pack<V, value_pack<F, Vs...>> {
  static constexpr bool value =
      (V == F) || is_value_in_pack<V, value_pack<Vs...>>::value;
};

template <auto V>
struct is_value_in_pack<V, value_pack<>> {
  static constexpr bool value = false;
};

template <auto V, class Pack>
constexpr bool is_value_in_pack_v = is_value_in_pack<V, Pack>::value;

}  // namespace types
}  // namespace upp
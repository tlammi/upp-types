#pragma once

#include <cstddef>

#include "upp/types/bits/pack.hpp"
#include "upp/types/bits/pack_size.hpp"

namespace upp {
namespace types {

namespace detail {
template <size_t I, class Pack, class = void>
struct nth_impl;

template <size_t I, class T, class... Ts>
struct nth_impl<I, pack<T, Ts...>, std::enable_if_t<(I > 0)>> {
  using type = nth_impl<I - 1, pack<Ts...>>::type;
};

template <class T, class... Ts>
struct nth_impl<0, pack<T, Ts...>> {
  using type = T;
};

template <size_t I, auto V, auto... Vs>
struct nth_impl<I, value_pack<V, Vs...>, std::enable_if_t<(I > 0)>> {
  static constexpr auto value = nth_impl<I - 1, value_pack<Vs...>>::value;
};

template <auto V, auto... Vs>
struct nth_impl<0, value_pack<V, Vs...>> {
  static constexpr auto value = V;
};
}  // namespace detail

template <size_t I, class Pack>
using nth = detail::nth_impl<I, Pack>;

template <size_t I, class Pack>
using nth_t = typename nth<I, Pack>::type;

template <size_t I, class Pack>
constexpr auto nth_v = nth<I, Pack>::value;

template <class Pack>
using first_t = nth_t<0, Pack>;

template <class Pack>
constexpr auto first_v = nth_v<0, Pack>;

template <class Pack>
using last_t = nth_t<pack_size_v<Pack> - 1, Pack>;

template <class Pack>
constexpr auto last_v = nth_v<pack_size_v<Pack> - 1, Pack>;

}  // namespace types
}  // namespace upp
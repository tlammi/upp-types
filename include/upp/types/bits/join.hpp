#pragma once

#include "upp/types/bits/pack.hpp"

namespace upp {
namespace types {

template <class L, class R>
struct join;

template <class... Tl, class... Tr>
struct join<pack<Tl...>, pack<Tr...>> {
  using type = pack<Tl..., Tr...>;
};

template <auto... Tl, auto... Tr>
struct join<value_pack<Tl...>, value_pack<Tr...>> {
  using type = value_pack<Tl..., Tr...>;
};

template <class L, class R>
using join_t = typename join<L, R>::type;

}  // namespace types
}  // namespace upp
#pragma once

#include "upp/types/bits/pack.hpp"
#include "upp/types/bits/select.hpp"

namespace upp {
namespace types {

/**
 * Sort the values in a value_pack
 *
 * \tparam Pack value_pack to sort
 * \tparam Cmp a callable taking two arguments and returning the one that should
 * come first in the sort result
 */
template <class Pack, auto Cmp>
struct sort;

template <auto V, auto... Vs, auto Cmp>
struct sort<value_pack<V, Vs...>, Cmp> {
  static constexpr auto selected_value =
      select_one_v<value_pack<V, Vs...>, Cmp>;
  using ltype = value_pack<selected_value>;
  using rtype_raw = pop_first_value_t<selected_value, value_pack<V, Vs...>>;
  using rtype_sorted = sort<rtype_raw, Cmp>::type;

  using type = join_t<ltype, rtype_sorted>;
};

template <auto Cmp>
struct sort<value_pack<>, Cmp> {
  using type = value_pack<>;
};

template <class Pack, auto Cmp>
using sort_t = typename sort<Pack, Cmp>::type;

}  // namespace types
}  // namespace upp
#pragma once

namespace upp {
namespace types {

template <bool V, class T, class F>
struct conditional;

template <class T, class F>
struct conditional<true, T, F> {
  using type = T;
};

template <class T, class F>
struct conditional<false, T, F> {
  using type = F;
};

template <bool V, class T, class F>
using conditional_t = typename conditional<V, T, F>::type;

}  // namespace types
}  // namespace upp
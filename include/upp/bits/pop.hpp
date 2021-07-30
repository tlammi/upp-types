#pragma once

#include "upp/bits/pop.hpp"
#include "upp/bits/join.hpp"
#include "upp/bits/pack.hpp"
#include "upp/bits/conditional.hpp"

namespace upp{

template<auto T, class Pack>
struct pop_first_value;

template<auto T, auto V, auto... Vs>
struct pop_first_value<T, value_pack<V, Vs...>>{
    using l_type = conditional_t<(T == V), value_pack<>, value_pack<V>>;
    using r_type = conditional_t<(T == V), value_pack<Vs...>, typename pop_first_value<T, value_pack<Vs...>>::type>;
    using type = join_t<l_type, r_type>;
};

template<auto T>
struct pop_first_value<T, value_pack<>>{
    using type = value_pack<>;
};


template<auto T, class Pack>
using pop_first_value_t = typename pop_first_value<T, Pack>::type;

}

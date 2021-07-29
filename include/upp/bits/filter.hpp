#pragma once

#include "upp/bits/pack.hpp"
#include "upp/bits/join.hpp"

namespace upp{

template<class Pack, auto Filter>
struct filter;

template<auto V, auto... Vs, auto Filter>
struct filter<value_pack<V, Vs...>, Filter>{
    using l_type = decltype([](){
        if constexpr (Filter(V)){
            return value_pack<V>();
        } else {
            return value_pack<>();
        }
    }());

    using r_type = filter<value_pack<Vs...>, Filter>::type;

    using type = join_t<l_type, r_type>;
};

template<auto Filter>
struct filter<value_pack<>, Filter>{
    using type = value_pack<>;
};

template<class T, class... Ts, auto Filter>
struct filter<pack<T, Ts...>, Filter>{
    using l_type = decltype([]() consteval {
        if constexpr (Filter(T{})) {
            return pack<T>();
        } else {
            return pack<>();
        }
    }());

    using r_type = filter<pack<Ts...>, Filter>::type;

    using type = join_t<l_type, r_type>;
};

template<auto Filter>
struct filter<pack<>, Filter>{
    using type = pack<>;
};

template<class P, auto F>
using filter_t = typename filter<P, F>::type;

}

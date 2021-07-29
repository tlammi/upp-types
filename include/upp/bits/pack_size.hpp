#pragma once

#include "upp/bits/pack.hpp"

#include <cstddef>

namespace upp{


template<class Pack>
struct pack_size;

template<class... Ts>
struct pack_size<pack<Ts...>>{
    static constexpr size_t value = sizeof...(Ts);
};

template<auto... Vs>
struct pack_size<value_pack<Vs...>>{
    static constexpr size_t value = sizeof...(Vs);
};

template<class Pack>
static constexpr auto pack_size_v = pack_size<Pack>::value;

}

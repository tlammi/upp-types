#pragma once

#include "upp/types.hpp"

using namespace upp::types;

struct S{};

using A = pack<int, S, double>;
using B = value_pack<0, 'b', 100>;

static_assert(std::is_same_v<nth_t<0, A>, int>);
static_assert(nth_v<1, B> == 'b');

static_assert(std::is_same_v<first_t<A>, int>);
static_assert(first_v<B> == 0);


static_assert(std::is_same_v<last_t<A>, double>);
static_assert(last_v<B> == 100);


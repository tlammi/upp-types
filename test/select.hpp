#pragma once

#include "upp/types.hpp"

using namespace upp::types;

using Pack = value_pack<0, 1, 4, 100>;

constexpr auto max_cmp = [](auto a, auto b) constexpr {
  return std::max(a, b);
};
constexpr auto max = select_one_v<Pack, max_cmp>;
static_assert(max == 100);

constexpr auto min = select_one_v<Pack, std::min<int>>;

static_assert(min == 0);

static_assert(max_v<Pack> == 100);
static_assert(min_v<Pack> == 0);

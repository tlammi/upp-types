#pragma once

#include <type_traits>

#include "upp/types.hpp"

namespace sort_test {
using namespace upp::types;

using Input = value_pack<5, 2, 1, 4>;
using ExpectedMin = value_pack<1, 2, 4, 5>;
using ExpectedMax = value_pack<5, 4, 2, 1>;

static_assert(std::is_same_v<sort_t<Input, std::min<int>>, ExpectedMin>);
static_assert(std::is_same_v<sort_t<Input, std::max<int>>, ExpectedMax>);
}  // namespace sort_test

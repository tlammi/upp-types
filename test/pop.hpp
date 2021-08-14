#pragma once

#include <type_traits>

#include "upp/types.hpp"

using namespace upp::types;

using Input = value_pack<0, 100, 99, 99, 'c'>;

using Expected = value_pack<0, 99, 99, 'c'>;

using Result = pop_first_value_t<100, Input>;

static_assert(std::is_same_v<Result, Expected>);

using Expected2 = value_pack<0, 100, 99, 'c'>;
using Result2 = pop_first_value_t<99, Input>;

static_assert(std::is_same_v<Result, Expected>);

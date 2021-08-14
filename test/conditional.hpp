#pragma once

#include <type_traits>

#include "upp/types.hpp"

using namespace upp::types;

static_assert(std::is_same_v<conditional_t<true, int, char>, int>);
static_assert(std::is_same_v<conditional_t<false, int, char>, char>);

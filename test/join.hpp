#pragma once

#include <type_traits>

#include "upp/types.hpp"

using namespace upp;

static_assert(std::is_same_v<join_t<pack<int, double>, pack<float, double>>, pack<int, double, float, double>>);
static_assert(std::is_same_v<join_t<value_pack<0, 'c'>, value_pack<'b', 100>>, value_pack<0, 'c', 'b', 100>>);


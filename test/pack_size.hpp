#pragma once

#include <type_traits>
#include "upp/types.hpp"

using namespace upp;

static_assert(pack_size_v<pack<>> == 0);
static_assert(pack_size_v<value_pack<>> == 0);
static_assert(pack_size_v<pack<int>> == 1);
static_assert(pack_size_v<value_pack<0>> == 1);

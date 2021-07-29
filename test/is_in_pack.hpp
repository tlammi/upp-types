#pragma once

#include "upp/types.hpp"


using namespace upp;


using PackA = pack<int, double, float, char>;

static_assert(is_type_in_pack_v<double, PackA>);
static_assert(is_type_in_pack_v<char, PackA>);
static_assert(is_type_in_pack_v<int, PackA>);

static_assert(!is_type_in_pack_v<long double, PackA>);

static_assert(!is_type_in_pack_v<int, pack<>>);



using PackB = value_pack<0, 'a', 100.0>;


static_assert(is_value_in_pack_v<0, PackB>);
static_assert(is_value_in_pack_v<'a', PackB>);

static_assert(!is_value_in_pack_v<1000, PackB>);

static_assert(!is_value_in_pack_v<1, value_pack<>>);

#pragma once

namespace upp {
namespace types {

template <class... Ts>
struct pack {};

template <auto... Vs>
struct value_pack {};

}  // namespace types
}  // namespace upp
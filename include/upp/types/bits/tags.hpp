#pragma once

namespace upp {
namespace types {

/**
 * Tag type for removing entries
 *
 * Used e.g. in filter<> to indicate that an entry should be removed
 */
struct remove_t {};

constexpr remove_t remove{};

/**
 * Tag type for keeping entries
 *
 * Used e.g. in filter<> to indicate that an entry should be kept
 */
struct keep_t {};
constexpr keep_t keep{};

}  // namespace types
}  // namespace upp

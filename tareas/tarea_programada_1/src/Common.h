#ifndef COMMON_H
#define COMMON_H
#include <cstddef>
#include <cstdint>
#include <string>

namespace Common {
// Constants for subnetting operations
constexpr size_t MAX_SUBNETS = 100;  // Maximum number of subnets allowed

inline std::string addressToString(uint32_t address) {
  return std::to_string((address >> 24) & 0xFF) + "." +
         std::to_string((address >> 16) & 0xFF) + "." +
         std::to_string((address >> 8) & 0xFF) + "." +
         std::to_string(address & 0xFF);
}

}  // namespace Common

#endif  // COMMON_H
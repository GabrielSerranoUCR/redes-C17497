#ifndef REQUEST_H
#define REQUEST_H
#include <cstdint>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

/*
* @struct Request
* @brief Represents a request for subnetting operations.
*
* This structure contains the address to be subnetted, a list of subnet
requests,
* and the results of subnetting operations.
*
* @var Request::address
* The address to be subnetted, represented as a 32-bit unsigned integer.
*
* @var Request::subnetRequests
* A vector of pairs, where each pair contains a string representing the name of
* the subnet request and a size_t representing the quantity of usable addresses
requested.
* The string can be any identifier for the subnet, such as "subnet1", "subnet2",
etc.
*
* @var Request::subnetResults
* A vector of tuples, where each tuple contains a string representing the name
of the subnet, a 32-bit unsigned integer representing the subnet address, and a
size_t representing the subnet mask.
*/
struct Request {
 public:
  uint32_t address;  // Address to be subnetted
  std::vector<std::pair<std::string, size_t>>
      subnetRequests;  // List of subnet requests
  bool ascendingOrder;  // Flag for sorting order

  std::vector<std::tuple<std::string, uint32_t, size_t>>
      subnetResults;  // Results of subnetting operations
};
#endif  // REQUEST_H
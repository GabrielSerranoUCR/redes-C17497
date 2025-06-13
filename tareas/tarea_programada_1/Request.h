#ifndef REQUEST_H
#define REQUEST_H
#include <cstdint>
#include <utility>
#include <vector>
/*
* @struct Request
* @brief Represents a request for subnetting operations.
*
* This structure contains the address to be subnetted, a list of subnet requests,
* and the results of subnetting operations.
*
* @var Request::address
* The address to be subnetted, represented as a 32-bit unsigned integer.
*
* @var Request::subnetRequests
* A vector of 32-bit unsigned integers representing the subnet requests.

* @var Request::subnetResults
* A vector of pairs, where each pair contains a 32-bit unsigned integer 
* representing the subnet address and a size_t representing the mask of the subnet.
*/
struct Request {
 public:
  uint32_t address;                      // Address to be subnetted
  std::vector<uint32_t> subnetRequests;  // List of subnet requests

  std::vector<std::pair<uint32_t, size_t>>
      subnetResults;  // Results of subnetting operations
};
#endif  // REQUEST_H
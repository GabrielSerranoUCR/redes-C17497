#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>

#include "Request.h"

/*
* @namespace InputHandler
* @brief Handles input processing for subnetting operations.

* This namespace provides functions to process command-line input,
* validate address formats, and assign subnet requests based on the provided
* request structure.
*/
namespace InputHandler {
// Public interface
void processInput(const std::string input, Request& request);
std::string inputToString(const int argc, const char* argv[]);
/*
 * @namespace Helper
 * @brief Contains private helper functions for input processing.
 */
namespace Helper {
uint32_t assignAddress(const std::string& ipString);
std::vector<std::pair<std::string, size_t>> assignSubnetRequests(
    const std::string& subnetRequestsString);
bool assignAscendingOrder(const std::string& orderString);
}  // namespace Helper

}  // namespace InputHandler

#endif  // INPUTHANDLER_H

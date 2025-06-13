#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H
#include "Request.h"

/*
 * @namespace RequestHandler
 * @brief Handles the processing of subnetting requests.
 *
 * This namespace provides functions to handle requests for subnetting
 * operations.
 */
namespace RequestHandler {
void handleRequest(Request& request);
/*
 * @namespace Helper
 * @brief Contains private helper functions for request handling.
 */
namespace Helper {
size_t totalAddressesNeeded(
    const std::vector<std::pair<std::string, size_t>>& subnetRequests);
    void subnet(Request& request);
    void sortSubnetRequests(Request& request);
}  // namespace Helper

}  // namespace RequestHandler
#endif  // REQUESTHANDLER_H

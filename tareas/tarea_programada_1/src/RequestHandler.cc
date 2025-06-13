#include "RequestHandler.h"

#include <algorithm>
#include <cmath>

#include "Common.h"
#include "Log.h"

void RequestHandler::handleRequest(Request& request) {
  // Process the request
  Log::getInstance().log(
      "INFO",
      "RequestHandler::handleRequest(): Processing request for address: " +
          Common::addressToString(request.address));
  if (RequestHandler::Helper::totalAddressesNeeded(request.subnetRequests) <=
      0xFFFFFFFF - request.address) {
    RequestHandler::Helper::sortSubnetRequests(request);
    RequestHandler::Helper::subnet(request);
  } else {
    throw std::runtime_error(
        "RequestHandler::handleRequest(): Not enough addresses available for "
        "the requested subnets.");
  }
}

size_t RequestHandler::Helper::totalAddressesNeeded(
    const std::vector<std::pair<std::string, size_t>>& subnetRequests) {
  // Sum all the quantities of usable addresses requested
  size_t totalAddresses = 0;
  for (const auto& request : subnetRequests) {
    size_t usableAddresses = request.second;
    totalAddresses +=
        1 << static_cast<size_t>(std::ceil(std::log2(usableAddresses + 2)));
  }
  Log::getInstance().log(
      "DEBUG",
      "RequestHandler::Helper::totalAddressesNeeded(): Total "
      "addresses needed: " +
          std::to_string(totalAddresses));
  return totalAddresses;
}

void RequestHandler::Helper::subnet(Request& request) {
  for (const auto& subnetRequest : request.subnetRequests) {
    // Calculate the subnet address and mask
    size_t usableAddresses = subnetRequest.second;
    size_t mask =
        32 - static_cast<size_t>(std::ceil(std::log2(usableAddresses + 2)));
    uint32_t subnetAddress = request.address & (~((1 << (32 - mask))));

    // Store the result in the request
    request.subnetResults.emplace_back(subnetRequest.first, subnetAddress,
                                       mask);

    // Log the result
    Log::getInstance().log(
        "INFO", "Subnet created: " + subnetRequest.first +
                    " - Address: " + Common::addressToString(subnetAddress) +
                    " - Mask: " + std::to_string(mask));
    subnetAddress +=
        (1 << (32 - std::get<2>(
                        request.subnetResults.back())));  // Increment address
    request.address =
        subnetAddress;  // Update the request address for next subnet
  }
}

void RequestHandler::Helper::sortSubnetRequests(Request& request) {
  std::sort(request.subnetRequests.begin(), request.subnetRequests.end(),
            [](const auto& a, const auto& b) { return a.second > b.second; });
}

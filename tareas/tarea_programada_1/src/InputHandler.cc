#include "InputHandler.h"

#include <regex>

#include "Common.h"
#include "Log.h"

void InputHandler::processInput(const std::string input, Request& request) {
  // Validate the input format using regex
  if (input.empty()) {
    throw std::invalid_argument(
        "InputHandler::processInput(): Input cannot be empty.");
  }
  std::regex pattern(
      R"((\d{1,3}(?:\.\d{1,3}){3})\s*\|\s*((?:\w+\s*,\s*\d+\s*;?\s*)+)\s*\|\s*(ASC|DESC))");

  std::smatch matches;

  if (!std::regex_match(input, matches, pattern)) {
    throw std::invalid_argument(
        "InputHandler::processInput(): Invalid input format.");
  }
  Log::getInstance().log(
      "DEBUG", "InputHandler::processInput(): matches found: " +
                   std::to_string(matches.size()) + " - " + matches[0].str());
  Log::getInstance().log(
      "DEBUG",
      "InputHandler::processInput(): address found: " + matches[1].str() +
          " - subnet requests found: " + matches[2].str());
  request.address = Helper::assignAddress(matches[1].str());
  request.subnetRequests = Helper::assignSubnetRequests(matches[2].str());
  request.ascendingOrder = Helper::assignAscendingOrder(matches[3].str());
}

uint32_t InputHandler::Helper::assignAddress(const std::string& ipString) {
  // Assign the address from the request
  std::regex ipPattern(R"((\d+)\.(\d+)\.(\d+)\.(\d+))");
  std::smatch ipMatches;
  if (!std::regex_match(ipString, ipMatches, ipPattern)) {
    throw std::invalid_argument("Invalid IP address format");
  }

  uint32_t address = 0;
  for (size_t i = 1; i <= 4; ++i) {
    uint32_t octet = std::stoul(ipMatches[i].str());
    if (octet > 255) {
      throw std::invalid_argument("IP octet value exceeds 255");
    }
    address = (address << 8) | octet;
  }
  return address;
}

std::vector<std::pair<std::string, size_t>>
InputHandler::Helper::assignSubnetRequests(
    const std::string& subnetRequestsString) {
  std::vector<std::pair<std::string, size_t>> subnetRequests;

  std::regex singleSubnetPattern(R"((\w+)\s*,\s*(\d+))");
  // Match the pattern for each subnet request
  std::sregex_iterator it(subnetRequestsString.begin(),
                          subnetRequestsString.end(), singleSubnetPattern);
  std::sregex_iterator end;
  if (it == end) {
    throw std::invalid_argument(
        "InputHandler::Helper::assignSubnetRequests(): No valid subnet "
        "requests found.");
  }

  // Count the number of matches
  size_t matchCount = std::distance(it, end);
  if (matchCount > Common::MAX_SUBNETS) {
    throw std::invalid_argument(
        "InputHandler::Helper::assignSubnetRequests(): Too many subnet "
        "requests. Maximum allowed is " +
        std::to_string(Common::MAX_SUBNETS) + ".");
  }
  // Iterate through all matches
  while (it != end) {
    std::string name = (*it)[1].str();
    size_t quantity = std::stoul((*it)[2].str());
    subnetRequests.emplace_back(name, quantity);
    ++it;
  }

  return subnetRequests;
}

bool InputHandler::Helper::assignAscendingOrder(const std::string& order) {
  // Assign the ascending order based on the input
  if (order == "ASC") {
    return true;
  } else if (order == "DESC") {
    return false;
  } else {
    throw std::invalid_argument(
        "InputHandler::Helper::assignAscendingOrder(): Invalid order "
        "specified. "
        "Use 'ASC' or 'DESC'.");
  }
}

std::string InputHandler::inputToString(int argc, const char* argv[]) {
  std::string inputStr;
  // if not using input redirecting
  if (argc > 1) {
    // Concatenate each C-style string
    for (int i = 1; i < argc; ++i) {
      inputStr += argv[i];
      if (i < argc - 1) {
        inputStr += " ";
      }
    }
  } else {  // if using input redirecting
    std::stringstream fileContents;
    fileContents << std::cin.rdbuf();
    inputStr = fileContents.str();
  }
  return inputStr;
}

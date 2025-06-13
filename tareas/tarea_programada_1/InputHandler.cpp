#include "InputHandler.h"

#include <regex>

void InputHandler::processInput(const int argc, const char* argv[],
                                Request& request) {
  if (argc < 2) {
    throw std::invalid_argument(
        "InputHandler::processInput(): Insufficient arguments provided.");
  }
  // Validate the address format
  assignAddress(request);
  assignSubnetRequests(request);
}

void InputHandler::assignAddress(Request& request) {
  // Assign the address from the request
}

void InputHandler::assignSubnetRequests(Request& request) {
  // Assign the subnet requests from the request
}

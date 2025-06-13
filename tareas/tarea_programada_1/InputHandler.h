#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Request.h"

/*
* @namespace InputHandler
* @brief Handles input processing for subnetting operations.

* This namespace provides functions to process command-line input,
* validate address formats, and assign subnet requests based on the provided
* request structure.
*/
namespace InputHandler {
void processInput(const int argc, const char* argv[], Request& request);

private:
void assignAddress(Request& request);
void assignSubnetRequests(Request& request);

}  // namespace InputHandler

#endif  // INPUTHANDLER_H

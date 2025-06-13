#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include "Request.h"
#include "Log.h"

/*
 * @namespace OutputHandler
 * @brief Handles output printing for subnetting operations.
 *
 * This namespace provides functions to print the results of subnetting operations
 * based on the provided request structure. It formats the output for easy readability.
 */
namespace OutputHandler {
void printOutput(Request &request);
}  // namespace OutputHandler
#endif  // OUTPUTHANDLER_H

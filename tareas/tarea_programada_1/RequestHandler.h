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
void handleRequest(const Request& request);
}  // namespace RequestHandler
#endif  // REQUESTHANDLER_H

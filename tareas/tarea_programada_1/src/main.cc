#include <cstdlib>

#include "InputHandler.h"
#include "Log.h"
#include "OutputHandler.h"
#include "Request.h"
#include "RequestHandler.h"

int main(int argc, const char* argv[]) {
  try {
    Request request;
    InputHandler::processInput(InputHandler::inputToString(argc, argv),
                               request);
    Log::getInstance().log("INFO", "main(): Input processed successfully.");
    Log::getInstance().log(
        "DEBUG", "main(): Address: " + std::to_string(request.address));
    Log::getInstance().log("DEBUG",
                           "main(): Subnet Requests: " +
                               std::to_string(request.subnetRequests.size()));
    for (const auto& subnet : request.subnetRequests) {
      Log::getInstance().log("DEBUG",
                             "main(): Subnet Request: " + subnet.first + ", " +
                                 std::to_string(subnet.second));
    }
    RequestHandler::handleRequest(request);
    Log::getInstance().log("INFO", "main(): Request handled successfully.");

    OutputHandler::printOutput(request);
    Log::getInstance().log("INFO", "main(): Output printed successfully.");

  } catch (const std::exception& e) {
    Log::getInstance().log("EXCEPTION", "main(): " + std::string(e.what()));
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
#include "OutputHandler.h"

#include <iomanip>
#include <sstream>

#include "Common.h"
#include "Log.h"

void OutputHandler::printOutput(Request& request) {
  Log::getInstance().log("INFO",
                         "OutputHandler::printOutput(): Printing output.");

  std::stringstream outputStream;
  outputStream << "------------------------------------------------------------"
                  "------------------\n";
  outputStream << "| " << std::left << std::setw(24) << "Subnet Name"
               << "| " << std::setw(23) << "Subnet Address"
               << "| " << std::setw(16) << "Total Addresses"
               << "| " << std::setw(9) << "Mask"
               << "|\n";
  outputStream << "------------------------------------------------------------"
                  "---------------------\n";

  for (const auto& result : request.subnetResults) {
    std::string subnetName = std::get<0>(result);
    uint32_t subnetAddress = std::get<1>(result);
    size_t subnetMask = std::get<2>(result);

    outputStream << "| " << std::setw(24) << subnetName << "| " << std::setw(23)
                 << Common::addressToString(subnetAddress) << "| "
                 << std::setw(16) << (1 << (32 - subnetMask)) - 2 << "| "
                 << std::setw(9) << subnetMask << "|\n";
  }
  outputStream << "------------------------------------------------------------"
                  "---------------------\n";

  Log::getInstance().log("RESULTS", outputStream.str());
}

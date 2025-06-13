#include "Log.h"

Log& Log::getInstance() {
  static Log instance;  // Guaranteed to be destroyed, instantiated on first use
  return instance;
}

void Log::log(const std::string& level, const std::string& message) {
  std::string filename = level + "_log.txt";
  std::ofstream logFile(filename, std::ios::app);
  if (logFile.is_open()) {
    time_t now = time(0);
    char* dt = ctime(&now);
    logFile << dt << " - " << message << std::endl;
    logFile.close();
  }
}

void Log::printLogs(const std::string& level) {
  std::string filename = level + "_log.txt";
  std::ifstream logFile(filename);
  if (logFile.is_open()) {
    std::string line;
    while (std::getline(logFile, line)) {
      std::cout << line << std::endl;
    }
    logFile.close();
  }
}   

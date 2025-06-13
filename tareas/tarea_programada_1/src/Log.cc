#include "Log.h"
#include <filesystem>

Log& Log::getInstance() {
  static Log instance;  // Guaranteed to be destroyed, instantiated on first use
  return instance;
}

void Log::log(const std::string& level, const std::string& message) {
  std::filesystem::path logDir("./logs");
  if (!std::filesystem::exists(logDir)) {
    std::filesystem::create_directory(logDir);
  }
  
  std::string filename = "./logs/" + level + "_log.txt";
  std::ofstream logFile(filename, std::ios::app);
  if (logFile.is_open()) {
    time_t now = time(0);
    char* dt = ctime(&now);
    logFile << dt << " - " << message << std::endl;
    logFile.close();
  }
}

void Log::printLogs(const std::string& level) {
  std::string filename = "./logs/" + level + "_log.txt";
  std::ifstream logFile(filename);
  if (logFile.is_open()) {
    std::string line;
    while (std::getline(logFile, line)) {
      std::cout << line << std::endl;
    }
    logFile.close();
  }
}

#ifndef LOG_H
#define LOG_H
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

/*
* @class Log
* @brief General logging class for the subnetting application.

* This class provides static methods for logging messages at different levels
* (info, warning, error) to the console. It is designed to be used throughout
* the application for consistent logging practices. It is designed to be a
singleton.
*/
class Log {
 private:
  Log() = default;           // Private constructor to prevent instantiation
  Log(const Log&) = delete;  // Prevent copy construction

 public:
  // Static method to get the singleton instance of Log
  static Log& getInstance();

  void log(const std::string& level, const std::string& message);

  void printLogs(const std::string& level);
};
#endif  // LOG_H
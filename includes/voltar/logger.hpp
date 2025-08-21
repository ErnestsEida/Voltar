#ifndef VOLTAR_LOGGER_HPP
#define VOLTAR_LOGGER_HPP

#include <iostream>

using namespace std;

namespace Voltar
{
  enum LogLevel
  {
    Info,
    Warning,
    Error
  };

  class Logger
  {
  private:
    static void Log(string message, Voltar::LogLevel level);

  public:
    static bool enabled;

    static void Info(string message);
    static void Warning(string message);
    static void Error(string message);

    static void set_enabled(bool state);
  };
};

#endif
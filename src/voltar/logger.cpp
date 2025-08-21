#include <voltar/logger.hpp>

bool Voltar::Logger::enabled = true;

void Voltar::Logger::Log(string message, Voltar::LogLevel level)
{
  switch (level)
  {
  case Voltar::LogLevel::Info:
    cout << "\033[1;34m" << "[INFO] " << message << " " << endl;
    break;
  case Voltar::LogLevel::Warning:
    cout << "\033[1;43m" << "[WARNING] " << message << " " << endl;
    break;
  case Voltar::LogLevel::Error:
    cout << "\033[1;41m" << "[ERROR] " << message << " " << endl;
    break;
  }

  // Return default white color
  cout << "\033[0m" << endl;
}

void Voltar::Logger::Info(string message)
{
  Log(message, Voltar::LogLevel::Info);
}

void Voltar::Logger::Warning(string message)
{
  Log(message, Voltar::LogLevel::Warning);
}

void Voltar::Logger::Error(string message)
{
  Log(message, Voltar::LogLevel::Error);
  exit(1);
}

void Voltar::Logger::set_enabled(bool state)
{
  enabled = state;
}
#pragma once
#include <iomanip>
#include <iostream>

#include <g3log/g3log.hpp>
#include <g3log/logworker.hpp>
#include <g3log/loglevels.hpp>

#include "sinks.hpp"

class MainWindow;

class Logger {
  public:
    Logger(MainWindow* window);
    ~Logger();

    void destroy();

  private:
    std::unique_ptr<g3::LogWorker> logWorker;
    std::unique_ptr<StdoutSink> stdoutSink;
	  std::unique_ptr<QtConsoleSink> qtConsoleSink;
    void initialize();
};

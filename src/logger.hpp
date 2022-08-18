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

    const std::unique_ptr<g3::LogWorker>& getLogWorker() const;
    const std::unique_ptr<StdoutSink>& getStdoutSink() const;
    const std::unique_ptr<QtConsoleSink>& getQtConsoleSink() const;

  private:
    std::unique_ptr<g3::LogWorker> m_LogWorker;
    std::unique_ptr<StdoutSink> m_StdoutSink;
	  std::unique_ptr<QtConsoleSink> m_QtConsoleSink;


};

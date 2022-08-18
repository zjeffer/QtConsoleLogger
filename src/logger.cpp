#include "logger.hpp"

Logger::Logger(MainWindow* window) {
	m_StdoutSink = std::make_unique<StdoutSink>();
	m_QtConsoleSink = std::make_unique<QtConsoleSink>(window);

	m_LogWorker = g3::LogWorker::createLogWorker();
	m_LogWorker->addSink(std::move(m_StdoutSink), &StdoutSink::callback);
	m_LogWorker->addSink(std::move(m_QtConsoleSink), &QtConsoleSink::callback);

	g3::initializeLogging(m_LogWorker.get());
}

Logger::~Logger(){
	destroy();
}

const std::unique_ptr<g3::LogWorker>& Logger::getLogWorker() const {
	return m_LogWorker;
}

const std::unique_ptr<StdoutSink>& Logger::getStdoutSink() const {
	return m_StdoutSink;
}

const std::unique_ptr<QtConsoleSink>& Logger::getQtConsoleSink() const {
	return m_QtConsoleSink;
}

void Logger::destroy(){
	std::cout << "Destroying logger" << std::endl;
	m_LogWorker->removeAllSinks();
	m_LogWorker.reset();
}

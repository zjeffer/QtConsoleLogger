#include "logger.hpp"

Logger::Logger(MainWindow* window) {
	stdoutSink = std::make_unique<StdoutSink>();
	qtConsoleSink = std::make_unique<QtConsoleSink>(window);

	logWorker = g3::LogWorker::createLogWorker();
	logWorker->addSink(std::move(stdoutSink), &StdoutSink::callback);
	logWorker->addSink(std::move(qtConsoleSink), &QtConsoleSink::callback);

	g3::initializeLogging(logWorker.get());
}

Logger::~Logger(){
	destroy();
}

void Logger::destroy(){
	std::cout << "Destroying logger" << std::endl;
	logWorker->removeAllSinks();
	logWorker.reset();
}

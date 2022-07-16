#include "logger.hpp"

Logger::Logger() {
	initialize();
}

Logger::~Logger(){
}

void Logger::destroy(){
	std::cout << "Destroying logger" << std::endl;
	logWorker->removeAllSinks();
	logWorker.reset();
}

void Logger::initialize() {
	logWorker = g3::LogWorker::createLogWorker();
	stdoutSink = std::make_unique<StdoutSink>();
	logWorker->addSink(std::move(stdoutSink), &StdoutSink::callback);

	g3::initializeLogging(logWorker.get());
}
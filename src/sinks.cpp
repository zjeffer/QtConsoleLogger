#include "sinks.hpp"

#include "mainwindow.hpp"

void StdoutSink::callback(g3::LogMessageMover log) {
	std::cout << log.get().toString(CustomSink::FormatMsg) << std::flush;
}



QtConsoleSink::QtConsoleSink(MainWindow* window) {
	m_Window = window;
}

void QtConsoleSink::callback(g3::LogMessageMover log) {
	// TODO: implement way to send log to Qt console widget
	m_Window->print(log.get().toString(CustomSink::FormatMsg));
}
#include "mainwindow.hpp"



MainWindow::MainWindow(QWidget *parent)
	: QMainWindow{parent}
{
	m_Logger = std::make_unique<Logger>(this);

	// create Console widget
	m_Console = new Console{this};

	// add widget to main window
	this->setCentralWidget(m_Console);

	
}

MainWindow::~MainWindow(){
	m_Logger->destroy();
	m_Logger.reset();
	
	delete m_Console;
}


void MainWindow::print(const std::string &text) {
	this->m_Console->putData(text.c_str());
}
#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow{parent}
{

	// create Console widget
	m_Console = new Console{this};

	// add widget to main window
	this->setCentralWidget(m_Console);
		
}

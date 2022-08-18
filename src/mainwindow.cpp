#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow{parent}, m_Ui(new Ui::MainWindow), m_Console(new Console),
	  m_Logger(std::make_unique<Logger>(this)) {
	m_Ui->setupUi(this);

	// add widget to main window
	setCentralWidget(m_Console);

	connect(m_Console, &Console::getData, m_Console, &Console::putData);
}

MainWindow::~MainWindow() { delete m_Console; }

Console *MainWindow::getConsole() const { return m_Console; }

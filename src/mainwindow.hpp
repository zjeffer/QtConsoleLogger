#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "console.hpp"
#include "logger.hpp"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);

private:
	Console* m_Console;

	Logger* m_logger;
};

#endif // MAINWINDOW_HPP

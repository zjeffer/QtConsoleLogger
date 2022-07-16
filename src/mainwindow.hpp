#pragma once

#include <QMainWindow>
#include "console.hpp"
#include "logger.hpp"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void print(const std::string &text);

private:
	Console* m_Console;

	std::unique_ptr<Logger> m_Logger;
};

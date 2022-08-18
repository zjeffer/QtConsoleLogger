#pragma once

#include <QMainWindow>
#include "console.hpp"
#include "logger.hpp"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	Console* getConsole() const;

private:
	Ui::MainWindow *m_Ui;
	Console* m_Console;

	std::unique_ptr<Logger> m_Logger;
};

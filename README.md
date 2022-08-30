# QtConsoleLogger

This is an example project for a Qt Console widget that receives log messages from [g3log](https://github.com/KjellKod/g3log). 

I created a custom g3log sink that sends the logs to the widget. The widget itself (console.hpp & console.cpp) was copied from [here](https://code.qt.io/cgit/qt/qtserialport.git/tree/examples/serialport/terminal) and adapted for use with g3log.

## Basic usage

The main method:

```c++
int main(int argc, char** argv) {
	// create an application
	QApplication a(argc, argv);
	// create a window:
	MainWindow window = MainWindow();
	window.show();

	// start running 
	return a.exec();
}

```

Inside your custom window constructor:

```c++
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, 
    m_Ui(new Ui::MainWindow) 
{
	// create a logger
	Logger logger = std::make_unique<Logger>(this);

	// Create a new Console object
	Console console = Console();

	// you can also create the logger in the constructor's initializer list,
	// but I'm doing it like this to make it easier to understand.

	// place the console where you want, for example as the central widget:
	setCentralWidget(&console);

	// connect the getData signal to the putData method
	connect(m_Console, &Console::getData, m_Console, &Console::putData);

	// Every time you use g3log's LOG(<LEVEL>) macro, 
	// it will print the message to both stdout and the GUI console:
	LOG(INFO) << "Example";
}
```

For a full example on how to create a window with a console, see [src/mainwindow.cpp](src/mainwindow.cpp), [src/mainwindow.hpp](src/mainwindow.hpp), and [src/main.cpp](src/main.cpp).


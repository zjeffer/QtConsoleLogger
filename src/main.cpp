#include "common.hpp"
#include "mainwindow.hpp"
#include <QApplication>

// signal handling
#include <signal.h>
void signal_handler(int signum) {
	std::cout << "Caught signal " << signum << std::endl;
	g_Running = false;
	QApplication::quit();
}

int main(int argc, char **argv) {
	// add signal handler
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);

	QApplication a(argc, argv);
	MainWindow window = MainWindow();
	window.show();

	// do logic in separate thread
	std::thread logic_thread([]() {
		LOG(INFO) << "Test";
		for (int i = 0; i < 100 && g_Running; i++) {
			LOG(DEBUG) << i;
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	});

	int r = a.exec();

	logic_thread.join();
	g_Running = false;
	return r;
}
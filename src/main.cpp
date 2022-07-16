

#include "mainwindow.hpp"
#include <QApplication>
#include <thread>

int main(int argc, char** argv) {
	QApplication a(argc, argv);
	MainWindow window = MainWindow();
	window.show();

	// create new thread for logic
	std::thread logic_thread([]() {
		LOG(INFO) << "Test";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		LOG(INFO) << "Test complete." << std::endl;
	});


	int r = a.exec();

	logic_thread.join();
	return r;
}
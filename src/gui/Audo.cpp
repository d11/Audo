#include <QApplication>
#include "MainWindow.h"

//#include "ABuffer.h"

int main(int argc, char *argv[])
{
//   QString sampleName = QString("Test sample");

//   Buffer *testSample = new ABuffer(48000, 1000, sampleName);

	QApplication app(argc, argv);
	MainWindow mainwin;

	mainwin.show();

	return app.exec();
}

#include <QApplication>
#include "aumainwindow.h"


int main (int argc, char *argv[])
{
	QApplication app(argc, argv);
	AuMainWindow mainwin;

	mainwin.show();

	return app.exec();
}

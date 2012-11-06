#include <QApplication>
#include "MainWindow.h"

#include "output/JackOutput.h"

#include "model/Ref.h"

#include "model/SineWaveSamples.h"

int main(int argc, char *argv[])
{
//   QString sampleName = QString("Test sample");

//   Buffer *testSample = new ABuffer(48000, 1000, sampleName);

	QApplication app(argc, argv);
	MainWindow mainwin;

	mainwin.show();

   JackOutput jackOutput;
   SampleSource::ref sampleSource(new SineWaveSamples(440.0, 0.0));
   jackOutput.setSampleSource( sampleSource );

	return app.exec();
}

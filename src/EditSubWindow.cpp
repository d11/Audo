#include "EditSubWindow.h"
#include <QDebug>
#include <QPushButton>

#include "AudioReader.h"
#include "Buffer.h"

EditSubWindow::EditSubWindow(QWidget *parent) : QWidget(parent) {
   waveDisplay = new WaveDisplay(this);
   waveDisplay->show();
   setMinimumSize(200,100);
   QVBoxLayout *layout = new QVBoxLayout();
   layout->addWidget(waveDisplay);
   layout->addWidget(new QPushButton("test", this));
   setLayout(layout);

   // temp - testing

   Buffer *buff = AudioReader::loadAudio("test_samples/speech_mono.wav");
   waveDisplay->setBuffer(buff);

//   waveDisplay->update();
//   waveDisplay->setAttribute(Qt::WA_OpaquePaintEvent);
//   update();
}

EditSubWindow::~EditSubWindow() {
   delete waveDisplay;
}

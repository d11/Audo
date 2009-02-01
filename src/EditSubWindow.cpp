#include "EditSubWindow.h"
#include <QDebug>
#include <QPushButton>
#include <QScrollArea>

#include "AudioReader.h"
#include "Buffer.h"

EditSubWindow::EditSubWindow(QWidget *parent) : QWidget(parent) {
   waveDisplay = new WaveDisplay(this);
   waveDisplay->show();
   setMinimumSize(200,100);
   QVBoxLayout *layout = new QVBoxLayout();

   QScrollArea *waveScroller = new QScrollArea();
   waveScroller->setWidget(waveDisplay);

   layout->addWidget(waveScroller);
   layout->addWidget(new QPushButton("test button", this));
   setLayout(layout);

   // temp - testing

//   Buffer &buffer = AudioReader::loadAudio("test_samples/speech_mono.wav");
//   waveDisplay->setBuffer(buff);

//   waveDisplay->update();
//   waveDisplay->setAttribute(Qt::WA_OpaquePaintEvent);
//   update();
}

EditSubWindow::~EditSubWindow() {
   delete waveDisplay;
}

EditSubWindow::setBuffer(Buffer &buffer) {
   waveDisplay->setBuffer(buffer);
}

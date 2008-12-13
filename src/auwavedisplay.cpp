#include "auwavedisplay.h"
#include <QPainter>


AuWaveDisplay::AuWaveDisplay(QWidget *parent) : QWidget(parent) {
   setBuffer(NULL);
   setOffset(0);
   setScale(1000); // Arbitrary; temp
   resize(300, 100);
}

AuWaveDisplay::~AuWaveDisplay() {

}

void AuWaveDisplay::setBuffer(Buffer *buffer) {
   this->buffer = buffer;
   update();
}

Buffer *AuWaveDisplay::getBuffer() {
   return buffer;
}

void AuWaveDisplay::setOffset(long samples) {
   this->offset = samples;
}

long AuWaveDisplay::getOffset() {
   return offset;
}

void AuWaveDisplay::setScale(long samples) {
   this->scale = samples;
}

long AuWaveDisplay::getScale() {
   return scale;
}

void AuWaveDisplay::paintEvent(QPaintEvent *event) {
   QPainter painter(this);
   painter.drawLine(10,10,50,60);

}




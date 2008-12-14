#include "WaveDisplay.h"
#include <QPaintEvent>
#include <QPainter>
#include <QFrame>
#include <QColor>

#include <QDebug>

WaveDisplay::WaveDisplay(QWidget *parent) : QFrame(parent) {
   setBuffer(NULL);
   setOffset(0);
   setScale(400); // Arbitrary; temp

   resize(300, 100);
   setMinimumSize(200,100);

   setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
   setLineWidth(1);
}

WaveDisplay::~WaveDisplay() {
}

void WaveDisplay::setBuffer(Buffer *buffer) {
   this->buffer = buffer;
   update();
}

Buffer *WaveDisplay::getBuffer() {
   return buffer;
}

void WaveDisplay::setOffset(long samples) {
   this->offset = samples;
}

long WaveDisplay::getOffset() {
   return offset;
}

void WaveDisplay::setScale(long samples) {
   this->scale = samples;
}

long WaveDisplay::getScale() {
   return scale;
}

void WaveDisplay::paintEvent(QPaintEvent *event) {
   QPainter painter(this);
   QRect toUpdate = event->rect();

   if (buffer == NULL) {
      painter.setPen(Qt::lightGray);
      painter.drawRect(toUpdate);
      painter.setPen(Qt::black);
      painter.drawText(5,5,"No buffer!");
      painter.drawLine(0, 0, width(), height());
      painter.drawLine(0, height(), width(), 0);
      qDebug() << toUpdate;
   } else {
      // Update every column of pixels in the region
      for (int pixelH = toUpdate.left(); pixelH < toUpdate.right(); ++pixelH) {

         if ((pixelH + 1)*scale < buffer->getNumberOfSamples()) {
            // Buffer has data to draw
            // Compute the maximum and minimum
            double sampleMax = 0.0;
            double sampleMin = 0.0;
            for (long sampleH = pixelH * scale; sampleH < (pixelH + 1) * scale; ++sampleH) {
               double currentSample = buffer->getSample(sampleH);
               if (currentSample > sampleMax) sampleMax = currentSample;
               if (currentSample < sampleMin) sampleMin = currentSample;
            }

            // TODO: replace with painter transformations
            int pixelTop = (int)((1.0 - sampleMax)*0.5*height());
            int pixelBottom = (int)((1.0 - sampleMin)*0.5*height());
            painter.setPen(Qt::black);
            painter.drawLine(pixelH, 0, pixelH, pixelTop-1);
            painter.setPen(Qt::white);
            painter.drawLine(pixelH, pixelTop, pixelH, pixelBottom);
            painter.setPen(Qt::black);
            painter.drawLine(pixelH, pixelBottom+1, pixelH, height());
         } else {
            // Beyond end of buffer
            painter.setPen(Qt::darkGray);
            painter.drawLine(pixelH, 0, pixelH, height());
         }
      }

   }
}


#pragma once

#include "model/Buffer.h"
#include "model/BufferRef.h"

#include <QRect>
#include <QFrame>

class WaveDisplay : public QFrame {
   Q_OBJECT

   protected:
      QImage *image;
      BufferRef buffer;
      long offset;
      long scale;

   public:
      // Constructor
		WaveDisplay (QWidget* parent = 0);
      ~WaveDisplay();

      // Set the audio buffer that the widget should display
      void setBuffer(BufferRef buffer);

      // Get the buffer currently being displayed
      BufferRef getBuffer();

      // The offset value controls which part of the buffer is displayed  

      // Set a new offset value
      void setOffset(long samples);
      // Get the current offset value
      long getOffset();

      // Set the horizontal scale
      void setScale(long samples);

      // Get the current scale
      long getScale();

   protected:
      void paintEvent(QPaintEvent *event);
//      void updateImage(const QRect &region);
		
};

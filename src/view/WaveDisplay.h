#ifndef _WAVEDISPLAY_H_

#define _WAVEDISPLAY_H_
#include "Buffer.h"

#include <QRect>
#include <QFrame>

class WaveDisplay : public QFrame {
   Q_OBJECT

   protected:
      QImage *image;
      Buffer *buffer;
      long offset;
      long scale;

   public:
      // Constructor
		WaveDisplay (QWidget* parent = 0);
      ~WaveDisplay();

      // Set the audio buffer that the widget should display
      void setBuffer(Buffer *buffer);

      // Get the buffer currently being displayed
      Buffer *getBuffer();

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
#endif /* _WAVEDISPLAY.H_ */

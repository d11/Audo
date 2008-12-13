#include "buffer.h"

#include <QWidget>

class AuWaveDisplay : public QWidget
{
   Q_OBJECT

   protected:
      Buffer *buffer;
      long offset;
      long scale;

   public:
      // Constructor
		AuWaveDisplay (QWidget* parent = 0);
      ~AuWaveDisplay();

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
		
};

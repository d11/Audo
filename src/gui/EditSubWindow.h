#pragma once

#include <QtGui>
#include "view/WaveDisplay.h"
#include "input/AudioReader.h"
#include "model/BufferRef.h"

class EditSubWindow : public QWidget {

   Q_OBJECT

   protected:
      WaveDisplay *waveDisplay;

	public:
		EditSubWindow (QWidget *parent = 0);
		~EditSubWindow();

      void setBuffer(BufferRef buffer);
};

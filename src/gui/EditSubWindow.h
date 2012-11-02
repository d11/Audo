#ifndef _EDITSUBWINDOW_H_

#define _EDITSUBWINDOW_H_

#include <QtGui>
#include "WaveDisplay.h"
#include "AudioReader.h"

class EditSubWindow : public QWidget {

   Q_OBJECT

   protected:
      WaveDisplay *waveDisplay;

	public:
		EditSubWindow (QWidget *parent = 0);
		~EditSubWindow();

      void setBuffer(Buffer &buffer);
};

#endif /* _EDITSUBWINDOW_H_ */

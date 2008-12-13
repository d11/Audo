#include <QtGui>
#include <QMdiSubWindow>
#include "auwavedisplay.h"


class AuEditSubWindow : public QMdiSubWindow
{
   protected:
      AuWaveDisplay *waveDisplay;

	public:
		AuEditSubWindow (QWidget *parent = 0);
		~AuEditSubWindow();

	private:
		
};


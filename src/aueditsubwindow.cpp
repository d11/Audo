#include "aueditsubwindow.h"

AuEditSubWindow::AuEditSubWindow(QWidget *parent) : QMdiSubWindow(parent) {
   waveDisplay = new AuWaveDisplay(this);
}

AuEditSubWindow::~AuEditSubWindow() {
   delete waveDisplay;
}


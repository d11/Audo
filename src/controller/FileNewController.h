#pragma once

#include "ActionController.h"
#include "model/BufferPool.h"
#include <QtGui>
#include <QMdiArea>

class FileNewController : public ActionController {
   Q_OBJECT

   QMdiArea &mdiMain;
   BufferPool &bufferPool;

   public:
      FileNewController(QAction &action, QMdiArea &mdiMain, BufferPool &bufferPool);
      void react();
};

#pragma once

#include "ActionController.h"
#include <QMdiArea>
#include "model/BufferPool.h"

class FileOpenController : public ActionController {
   Q_OBJECT

   QMdiArea &mdiMain;
   BufferPool &bufferPool;

   public:
      FileOpenController(QAction &action, QMdiArea &mdiMain, BufferPool & bufferPool);
      void react();
};

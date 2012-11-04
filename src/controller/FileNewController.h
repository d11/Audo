#ifndef _FILENEWCONTROLLER_H_
#define _FILENEWCONTROLLER_H_

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
#endif /* FILENEWCONTROLLER_H_ */

#ifndef _FILEOPENCONTROLLER_H_
#define _FILEOPENCONTROLLER_H_

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
#endif /* FILEOPENCONTROLLER_H_ */

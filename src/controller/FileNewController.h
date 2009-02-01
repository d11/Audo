#ifndef _FILENEWCONTROLLER_H_
#define _FILENEWCONTROLLER_H_

#include "ActionController.h"
#include <QtGui>
#include <QMdiArea>

class FileNewController : public ActionController {
   Q_OBJECT

   QMdiArea &mdiMain;

   public:
      FileNewController(QAction &action, QMdiArea &mdiMain);
      void react();
};
#endif /* FILENEWCONTROLLER_H_ */

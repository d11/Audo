#ifndef _FILEOPENCONTROLLER_H_
#define _FILEOPENCONTROLLER_H_

#include "ActionController.h"
#include <QMdiArea>

class FileOpenController : public ActionController {
   Q_OBJECT

   QMdiArea &mdiMain;

   public:
      FileOpenController(QAction &action, QMdiArea &mdiMain);
      void react();
};
#endif /* FILEOPENCONTROLLER_H_ */

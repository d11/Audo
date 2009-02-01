#include "FileNewController.h"
#include "EditSubWindow.h"

FileNewController::FileNewController(QAction &action, QMdiArea &mdiMain)
: ActionController(action), mdiMain(mdiMain) {
}

void FileNewController::react() {
   qDebug() << "Creating new window";
   EditSubWindow *newEditWindow = new EditSubWindow(&mdiMain);
   Buffer &buffer = bufferManager.getEmptyBuffer();
   newEditWindow->setBuffer(buffer);
   newEditWindow->show();
   QMdiSubWindow *subWindow = mdiMain.addSubWindow(newEditWindow);
   subWindow->setAttribute(Qt::WA_DeleteOnClose);
   subWindow->show();
}

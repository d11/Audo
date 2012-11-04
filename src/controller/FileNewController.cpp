#include "FileNewController.h"
#include "gui/EditSubWindow.h"

FileNewController::FileNewController(QAction &action, QMdiArea &mdiMain, BufferPool &bufferPool)
: ActionController(action), mdiMain(mdiMain), bufferPool(bufferPool) {
}

void FileNewController::react() {
   qDebug() << "Creating new window";
   EditSubWindow *newEditWindow = new EditSubWindow(&mdiMain);
   BufferRef buffer = bufferPool.getEmptyBuffer();
   newEditWindow->setBuffer(buffer);
   newEditWindow->show();
   QMdiSubWindow *subWindow = mdiMain.addSubWindow(newEditWindow);
   subWindow->setAttribute(Qt::WA_DeleteOnClose);
   subWindow->show();
}

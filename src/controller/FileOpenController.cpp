#include "QFileDialog"
#include "gui/EditSubWindow.h"
#include "FileOpenController.h"

FileOpenController::FileOpenController(QAction &action, QMdiArea &mdiMain)
: ActionController(action), mdiMain(mdiMain) {
}

void FileOpenController::react() {
   qDebug() << "Opening file";
   QString fileName = QFileDialog::getOpenFileName(&mdiMain, "Open audio file", "/home/dan/Projects/Audo/test_samples/", "Audio Files (*.wav)");
   qDebug() << "Filename is '" << fileName << "'";

   /* TODO
   Buffer &buffer = bufferManager.getNewBufferFromFile(fileName);

   EditSubWindow *newEditWindow = new EditSubWindow(&mdiMain);
   newEditWindow->setBuffer(buffer);
   newEditWindow->show();
   QMdiSubWindow *subWindow = mdiMain.addSubWindow(newEditWindow);
   subWindow->setAttribute(Qt::WA_DeleteOnClose);
   subWindow->show();
   */
}

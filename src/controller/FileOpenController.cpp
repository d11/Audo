#include "QFileDialog"
#include "gui/EditSubWindow.h"
#include "FileOpenController.h"

FileOpenController::FileOpenController(QAction &action, QMdiArea &mdiMain, BufferPool &bufferPool)
: ActionController(action), mdiMain(mdiMain), bufferPool(bufferPool) {
}

void FileOpenController::react() {
   qDebug() << "Opening file";
   QString fileName = QFileDialog::getOpenFileName(&mdiMain, "Open audio file", "/home/dan/Projects/Audo/test_samples/", "Audio Files (*.wav)");
   qDebug() << "Filename is '" << fileName << "'";

   BufferRef buffer = bufferPool.getNewBufferFromFile(fileName);

   EditSubWindow *newEditWindow = new EditSubWindow(&mdiMain);
   newEditWindow->setBuffer(buffer);
   newEditWindow->show();
   QMdiSubWindow *subWindow = mdiMain.addSubWindow(newEditWindow);
   subWindow->setAttribute(Qt::WA_DeleteOnClose);
   subWindow->show();
}

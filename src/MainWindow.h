#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QtGui>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QToolBar>

#include "MDIArea.h"
#include "FileNewController.h"
#include "FileOpenController.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

	private slots:
		void save();
		void saveAs();
		void cut();
		void copy();
		void paste();
		void crop();
		void silence();

	public:
		MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:
		void createActions();
		void createFileToolBar();
		void createEditToolBar();
		void createMenuBar();
		void createFileMenu();
		void createEditMenu();

		QAction *fileNewAct;
		QAction *fileOpenAct;
		QAction *fileSaveAct;
		QAction *fileSaveAsAct;
		QAction *fileExitAct;
		QAction *editCutAct;
		QAction *editCopyAct;
		QAction *editPasteAct;
		QAction *editCropAct;
		QAction *editSilenceAct;
		QMenu *fileMenu;
		QMenu *editMenu;
		QMenuBar *menuBar;
		QToolBar *fileToolBar;
		QToolBar *editToolBar;
		MdiArea *mdiMain;
      FileNewController *fileNewController;
      FileOpenController *fileOpenController;
};

#endif /* _MAINWINDOW_H_ */

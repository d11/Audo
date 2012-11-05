#pragma once

#include <QtGui>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QToolBar>

#include "MDIArea.h"
#include "controller/FileNewController.h"
#include "controller/FileOpenController.h"

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

		QAction            * m_fileNewAct;
		QAction            * m_fileOpenAct;
		QAction            * m_fileSaveAct;
		QAction            * m_fileSaveAsAct;
		QAction            * m_fileExitAct;
		QAction            * m_editCutAct;
		QAction            * m_editCopyAct;
		QAction            * m_editPasteAct;
		QAction            * m_editCropAct;
		QAction            * m_editSilenceAct;
		QMenu              * m_fileMenu;
		QMenu              * m_editMenu;
		QMenuBar           * m_menuBar;
		QToolBar           * m_fileToolBar;
		QToolBar           * m_editToolBar;
		MdiArea            * m_mdiMain;
      FileNewController  * m_fileNewController;
      FileOpenController * m_fileOpenController;
};


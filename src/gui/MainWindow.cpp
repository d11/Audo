#include "MainWindow.h"
#include "MDIArea.h"
#include "EditSubWindow.h"

#include <iostream>

void MainWindow::createActions() {
	m_fileNewAct = new QAction("&New", this);
	m_fileNewAct->setShortcut(tr("Ctrl+N"));
	m_fileNewAct->setStatusTip("Create a new file");
   BufferPool bufferPool; // TODO
   m_fileNewController = new FileNewController(*m_fileNewAct, *m_mdiMain, bufferPool);

	m_fileOpenAct = new QAction("&Open", this);
	m_fileOpenAct->setShortcut(tr("Ctrl+O")); 
	m_fileOpenAct->setStatusTip("Open an existing file");
   m_fileOpenController = new FileOpenController(*m_fileOpenAct, *m_mdiMain, bufferPool);

	m_fileSaveAct = new QAction("&Save", this);
	m_fileSaveAct->setShortcut(tr("Ctrl+S")); 
	m_fileSaveAct->setStatusTip("Save the file to disk");
	connect(m_fileSaveAct, SIGNAL(triggered()), this, SLOT(save()));

	m_fileSaveAsAct = new QAction("Save &As", this);
	m_fileSaveAsAct->setShortcut(tr("Ctrl+Shift+A")); 
	m_fileSaveAsAct->setStatusTip("Save the file with new name");
	connect(m_fileSaveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

	m_fileExitAct = new QAction("E&xit", this);
	m_fileExitAct->setShortcut(tr("Ctrl+Q"));
	m_fileExitAct->setStatusTip("Exit the application");
	connect(m_fileExitAct, SIGNAL(triggered()), this, SLOT(close()));

	m_editCutAct = new QAction("Cu&t", this);
	m_editCutAct->setShortcut(tr("Ctrl+X")); 
	m_editCutAct->setStatusTip("Cut the selection to the clipboard");
	connect(m_editCutAct, SIGNAL(triggered()), this, SLOT(cut()));

	m_editCopyAct = new QAction("&Copy", this);
	m_editCopyAct->setShortcut(tr("Ctrl+C")); 
	m_editCopyAct->setStatusTip("Copy the selection to the clipboard");
	connect(m_editCopyAct, SIGNAL(triggered()), this, SLOT(copy()));

	m_editPasteAct = new QAction("&Paste", this);
	m_editPasteAct->setShortcut(tr("Ctrl+V")); 
	m_editPasteAct->setStatusTip("Paste the contents of the clipboard");
	connect(m_editPasteAct, SIGNAL(triggered()), this, SLOT(paste()));

	m_editCropAct = new QAction("C&rop", this);
	m_editCropAct->setShortcut(tr("Ctrl+R")); 
	m_editCropAct->setStatusTip("Remove everything apart from the selection");
	connect(m_editCropAct, SIGNAL(triggered()), this, SLOT(crop()));

	m_editSilenceAct = new QAction("&Silence", this);
	m_editSilenceAct->setShortcut(tr("Ctrl+_")); 
	m_editSilenceAct->setStatusTip("Set the selection to silence");
	connect(m_editSilenceAct, SIGNAL(triggered()), this, SLOT(silence()));

}

void MainWindow::createFileMenu() {
	m_fileMenu = m_menuBar->addMenu("&File");
	m_fileMenu->addAction(m_fileNewAct);
	m_fileMenu->addAction(m_fileOpenAct);
	m_fileMenu->addAction(m_fileSaveAct);
	m_fileMenu->addAction(m_fileSaveAsAct);
	m_fileMenu->addAction(m_fileExitAct);
}

void MainWindow::createEditMenu() {
	m_editMenu = m_menuBar->addMenu("&Edit");
	m_editMenu->addAction(m_editCutAct);
	m_editMenu->addAction(m_editCopyAct);
	m_editMenu->addAction(m_editPasteAct);
	m_editMenu->addAction(m_editCropAct);
	m_editMenu->addAction(m_editSilenceAct);
}

void MainWindow::createMenuBar() {
	m_menuBar = new QMenuBar(this);
	setMenuBar(m_menuBar);
}

void MainWindow::createFileToolBar() {
	m_fileToolBar = new QToolBar(this);
	m_fileToolBar->addAction(m_fileNewAct);
	m_fileToolBar->addAction(m_fileOpenAct);
	m_fileToolBar->addAction(m_fileSaveAct);
	m_fileToolBar->addAction(m_fileSaveAsAct);
	m_fileToolBar->addAction(m_fileExitAct);
	addToolBar(m_fileToolBar);
}

void MainWindow::createEditToolBar() {
	m_editToolBar = new QToolBar(this);
	m_editToolBar->addAction(m_editCutAct);
	m_editToolBar->addAction(m_editCopyAct);
	m_editToolBar->addAction(m_editPasteAct);
	m_editToolBar->addAction(m_editCropAct);
	m_editToolBar->addAction(m_editSilenceAct);
	addToolBar(m_editToolBar);
}

//void MainWindow::open() { std::cout << "'open' not implemented" << std::endl; }
void MainWindow::save() { std::cout << "'save' not implemented" << std::endl; }
void MainWindow::saveAs() { std::cout << "'saveAs' not implemented" << std::endl; }

void MainWindow::cut() { std::cout << "'cut' not implemented" << std::endl; }
void MainWindow::copy() { std::cout << "'copy' not implemented" << std::endl; }
void MainWindow::paste() { std::cout << "'paste' not implemented" << std::endl; }
void MainWindow::crop() { std::cout << "'crop' not implemented" << std::endl; }
void MainWindow::silence() { std::cout << "'silence' not implemented" << std::endl; }

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	resize(800, 600);
	m_mdiMain = new MdiArea(this);
	createActions();
	createFileToolBar();
	createEditToolBar();
	createMenuBar();
	createFileMenu();
	createEditMenu();
	setCentralWidget(m_mdiMain);
	setStatusBar(statusBar());

	//Qt::Object.connect(m_fileToolBar, "actionTriggered(

}

MainWindow::~MainWindow()
{
	delete m_fileNewAct;
	delete m_fileOpenAct;
	delete m_fileSaveAct;
	delete m_fileSaveAsAct;
	delete m_fileExitAct;
	delete m_editCutAct;
	delete m_editCopyAct;
	delete m_editPasteAct;
	delete m_editCropAct;
	delete m_editSilenceAct;
	delete m_fileMenu;
	delete m_editMenu;
	delete m_menuBar;
	delete m_fileToolBar;
	delete m_editToolBar;
	delete m_mdiMain;
   delete m_fileNewController;
   delete m_fileOpenController;
}

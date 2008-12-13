#include "aumainwindow.h"
#include "aumdiarea.h"
#include "aueditsubwindow.h"

#include <iostream>

void AuMainWindow::createActions()
{
	fileNewAct = new QAction("&New", this);
	fileNewAct->setShortcut(tr("Ctrl+N"));
	fileNewAct->setStatusTip("Create a new file");
	connect(fileNewAct, SIGNAL(triggered()), this, SLOT(newFile()));

	fileOpenAct = new QAction("&Open", this);
	fileOpenAct->setShortcut(tr("Ctrl+O")); 
	fileOpenAct->setStatusTip("Open an existing file");
	connect(fileOpenAct, SIGNAL(triggered()), this, SLOT(open()));

	fileSaveAct = new QAction("&Save", this);
	fileSaveAct->setShortcut(tr("Ctrl+S")); 
	fileSaveAct->setStatusTip("Save the file to disk");
	connect(fileSaveAct, SIGNAL(triggered()), this, SLOT(save()));

	fileSaveAsAct = new QAction("Save &As", this);
	fileSaveAsAct->setShortcut(tr("Ctrl+Shift+A")); 
	fileSaveAsAct->setStatusTip("Save the file with new name");
	connect(fileSaveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

	fileExitAct = new QAction("E&xit", this);
	fileExitAct->setShortcut(tr("Ctrl+Q"));
	fileExitAct->setStatusTip("Exit the application");
	connect(fileExitAct, SIGNAL(triggered()), this, SLOT(close()));

	editCutAct = new QAction("Cu&t", this);
	editCutAct->setShortcut(tr("Ctrl+X")); 
	editCutAct->setStatusTip("Cut the selection to the clipboard");
	connect(editCutAct, SIGNAL(triggered()), this, SLOT(cut()));

	editCopyAct = new QAction("&Copy", this);
	editCopyAct->setShortcut(tr("Ctrl+C")); 
	editCopyAct->setStatusTip("Copy the selection to the clipboard");
	connect(editCopyAct, SIGNAL(triggered()), this, SLOT(copy()));

	editPasteAct = new QAction("&Paste", this);
	editPasteAct->setShortcut(tr("Ctrl+V")); 
	editPasteAct->setStatusTip("Paste the contents of the clipboard");
	connect(editPasteAct, SIGNAL(triggered()), this, SLOT(paste()));

	editCropAct = new QAction("C&rop", this);
	editCropAct->setShortcut(tr("Ctrl+R")); 
	editCropAct->setStatusTip("Remove everything apart from the selection");
	connect(editCropAct, SIGNAL(triggered()), this, SLOT(crop()));

	editSilenceAct = new QAction("&Silence", this);
	editSilenceAct->setShortcut(tr("Ctrl+_")); 
	editSilenceAct->setStatusTip("Set the selection to silence");
	connect(editSilenceAct, SIGNAL(triggered()), this, SLOT(silence()));

}

void AuMainWindow::createFileMenu()
{
	fileMenu = menuBar->addMenu("&File");
	fileMenu->addAction(fileNewAct);
	fileMenu->addAction(fileOpenAct);
	fileMenu->addAction(fileSaveAct);
	fileMenu->addAction(fileSaveAsAct);
	fileMenu->addAction(fileExitAct);
}

void AuMainWindow::createEditMenu()
{
	editMenu = menuBar->addMenu("&Edit");
	editMenu->addAction(editCutAct);
	editMenu->addAction(editCopyAct);
	editMenu->addAction(editPasteAct);
	editMenu->addAction(editCropAct);
	editMenu->addAction(editSilenceAct);
}

void AuMainWindow::createMenuBar()
{
	menuBar = new QMenuBar(this);
	setMenuBar(menuBar);
}

void AuMainWindow::createFileToolBar()
{
	fileToolBar = new QToolBar(this);
	fileToolBar->addAction(fileNewAct);
	fileToolBar->addAction(fileOpenAct);
	fileToolBar->addAction(fileSaveAct);
	fileToolBar->addAction(fileSaveAsAct);
	fileToolBar->addAction(fileExitAct);

	addToolBar(fileToolBar);
}

void AuMainWindow::createEditToolBar()
{
	editToolBar = new QToolBar(this);
	editToolBar->addAction(editCutAct);
	editToolBar->addAction(editCopyAct);
	editToolBar->addAction(editPasteAct);
	editToolBar->addAction(editCropAct);
	editToolBar->addAction(editSilenceAct);

	addToolBar(editToolBar);
}

void AuMainWindow::newFile() { 
   std::cout << "Creating new window" << std::endl; 
   AuEditSubWindow *newEditWindow = new AuEditSubWindow(mdiMain);
   mdiMain->addSubWindow(newEditWindow);
}

void AuMainWindow::open() { std::cout << "'open' not implemented" << std::endl; }
void AuMainWindow::save() { std::cout << "'save' not implemented" << std::endl; }
void AuMainWindow::saveAs() { std::cout << "'saveAs' not implemented" << std::endl; }

void AuMainWindow::cut() { std::cout << "'cut' not implemented" << std::endl; }
void AuMainWindow::copy() { std::cout << "'copy' not implemented" << std::endl; }
void AuMainWindow::paste() { std::cout << "'paste' not implemented" << std::endl; }
void AuMainWindow::crop() { std::cout << "'crop' not implemented" << std::endl; }
void AuMainWindow::silence() { std::cout << "'silence' not implemented" << std::endl; }

AuMainWindow::AuMainWindow(QWidget *parent) : QMainWindow(parent)
{
	resize(800, 600);
	
	mdiMain = new AuMdiArea(this);


	createActions();

	createFileToolBar();
	createEditToolBar();

	createMenuBar();
	createFileMenu();
	createEditMenu();

	setCentralWidget(mdiMain);
	setStatusBar(statusBar());

	//Qt::Object.connect(fileToolBar, "actionTriggered(

	/*
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(hello);
	setLayout(layout);
	*/
}

AuMainWindow::~AuMainWindow()
{
	delete fileNewAct;
	delete fileOpenAct;
	delete fileSaveAct;
	delete fileSaveAsAct;
	delete fileExitAct;
	delete editCutAct;
	delete editCopyAct;
	delete editPasteAct;
	delete editCropAct;
	delete editSilenceAct;

	delete fileMenu;
	delete editMenu;
	delete menuBar;

	delete fileToolBar;
	delete editToolBar;

	delete mdiMain;

}

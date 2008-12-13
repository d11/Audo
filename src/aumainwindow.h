#include <QtGui>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QToolBar>

#include "aumdiarea.h"

class AuMainWindow : public QMainWindow
{
	Q_OBJECT

	private slots:
		void newFile();
		void open();
		void save();
		void saveAs();
		void cut();
		void copy();
		void paste();
		void crop();
		void silence();

	public:
		AuMainWindow(QWidget *parent = 0);
		~AuMainWindow();

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

		AuMdiArea *mdiMain;

};


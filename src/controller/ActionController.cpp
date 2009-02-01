#include "ActionController.h"
#include <QAction>
#include <QtGui>

ActionController::ActionController(QAction &action) : action(action){
   connect(&this->action, SIGNAL(triggered()), this, SLOT(react()));
}

ActionController::~ActionController() { }


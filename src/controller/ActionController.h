#pragma once

#include <QAction>
#include <QObject>

class ActionController : public QObject {
   Q_OBJECT

   public slots:
      virtual void react() = 0;

   protected:
      QAction &action;

   public:
      ActionController(QAction &action);
      virtual ~ActionController();
};

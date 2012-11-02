#ifndef _ACTIONCONTROLLER_H_
#define _ACTIONCONTROLLER_H_

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

#endif /* _ACTIONCONTROLLER_H_ */

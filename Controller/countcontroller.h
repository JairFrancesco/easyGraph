#ifndef COUNTCONTROLLER_H
#define COUNTCONTROLLER_H

#include <QSharedPointer>
#include <QTimer>
#include <QObject>
#include <countmodel.h>

using namespace Model;

namespace Controller{

    class CountController : public QObject
    {
        Q_OBJECT
        public:
            CountController();
            void setModel(QSharedPointer<CountModel> model);

        signals:
            void valueChanged(int newValue);

        public slots:
            void onStart();
            void onStop();
            void onTimer();

        private:
            QSharedPointer<CountModel> mModel;
            QTimer *mTimer;


    };


}


#endif // COUNTCONTROLLER_H

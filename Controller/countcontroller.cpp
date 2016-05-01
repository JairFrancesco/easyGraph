#include "countcontroller.h"

namespace Controller{

    /*
    CountController::CountController(QObject *parent) : QObject(parent)
    {

    }
    */

    CountController::CountController()
    {
        mTimer = new QTimer(this);
        connect(mTimer, SIGNAL(timeout()), this, SLOT(onTimer()));
    }

    void CountController::setModel(QSharedPointer<CountModel> model)
    {
        mModel = model;
    }

    void CountController::onStart()
    {
        if (!mTimer->isActive()) {
            mTimer->start(1000);
        }
    }

    void CountController::onStop()
    {
        mTimer->stop();
    }

    void CountController::onTimer()
    {
        int newValue = mModel->value() + 1;
        mModel->setValue(newValue);
        emit valueChanged(newValue);
    }
}

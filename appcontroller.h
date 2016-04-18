#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "countcontroller.h"
#include "countmodel.h"
#include "mainwindow.h"

namespace Controller{
    class AppController
    {
        public:
            ~AppController();

            void createObjects();
            static int main(int argc, char *argv[]);
            int run(int argc, char*arcg[]);
            void connectObjects();

            QSharedPointer<CountModel> mModel;
            MainWindow *mMainWindowView;
            CountController *mCounterController;

    };

}


#endif // APPCONTROLLER_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myopengl.h"
#include "myopengl2.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo;
    QAction *actionAbrir;
    QAction *actionGuardar;
    QAction *actionSaveAs;
    QAction *actionAcerca_de;
    QAction *actionTutorial;
    QAction *actionExportar_como_imagen;
    QAction *actionImprimir_como_imagen;
    QAction *actionSalir;
    QAction *actionInsertar_Ecuaci_n;
    QAction *actionRemover_ecuaci_n;
    QAction *actionReiniciar_Configuraciones;
    QAction *actionCortar;
    QAction *actionCopiar;
    QAction *actionPegar;
    QAction *actionTeclado;
    QAction *actionConfiguraci_n_de_ejes;
    QAction *actionAtributos_del_Grafico;
    QAction *actionConfiguraciones;
    QAction *action_Que_hay_de_nuevo;
    QAction *actionContactanos;
    QAction *actionMore;
    QAction *actionLess;
    QAction *actionCheckUncheck;
    QAction *actionExample;
    QAction *actionTable;
    QAction *actionZoomAll;
    QAction *actionZoomMore;
    QAction *actionZoomLess;
    QAction *actionSaveGraph;
    QAction *actionShareFacebook;
    QAction *actionCopyToClipboard;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QSplitter *splitterEquations_Table_Graphs;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalEquations;
    QVBoxLayout *verticalLayoutEquations;
    QGroupBox *grpEquations;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QGraphicsView *graphicsView;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblStatus;
    QTextEdit *txtStatus;
    QPushButton *btnRedraw;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QWidget *tab_3;
    QFrame *line_2;
    QSplitter *splitter_Table_Graph;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayoutTable;
    QTableWidget *tableWidget;
    QFrame *line_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayoutGraph;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *chkGrid;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_5;
    QSlider *verticalSlider;
    QTabWidget *tabGraphics;
    QWidget *tab2D;
    QVBoxLayout *verticalLayout_7;
    Myopengl *myopenglw;
    QWidget *tab3D;
    QVBoxLayout *verticalLayout_8;
    Myopengl2 *openGLWidget3D;
    QMenuBar *menuBar;
    QMenu *menuEasyGraph_using_MVC;
    QMenu *menuJair;
    QMenu *menuAyuda;
    QMenu *menuVer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 650);
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName(QStringLiteral("actionNuevo"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNuevo->setIcon(icon);
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbrir->setIcon(icon1);
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGuardar->setIcon(icon2);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSaveAs->setIcon(icon2);
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
        actionTutorial = new QAction(MainWindow);
        actionTutorial->setObjectName(QStringLiteral("actionTutorial"));
        actionExportar_como_imagen = new QAction(MainWindow);
        actionExportar_como_imagen->setObjectName(QStringLiteral("actionExportar_como_imagen"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExportar_como_imagen->setIcon(icon3);
        actionImprimir_como_imagen = new QAction(MainWindow);
        actionImprimir_como_imagen->setObjectName(QStringLiteral("actionImprimir_como_imagen"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/print.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionImprimir_como_imagen->setIcon(icon4);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionInsertar_Ecuaci_n = new QAction(MainWindow);
        actionInsertar_Ecuaci_n->setObjectName(QStringLiteral("actionInsertar_Ecuaci_n"));
        actionRemover_ecuaci_n = new QAction(MainWindow);
        actionRemover_ecuaci_n->setObjectName(QStringLiteral("actionRemover_ecuaci_n"));
        actionReiniciar_Configuraciones = new QAction(MainWindow);
        actionReiniciar_Configuraciones->setObjectName(QStringLiteral("actionReiniciar_Configuraciones"));
        actionCortar = new QAction(MainWindow);
        actionCortar->setObjectName(QStringLiteral("actionCortar"));
        actionCopiar = new QAction(MainWindow);
        actionCopiar->setObjectName(QStringLiteral("actionCopiar"));
        actionPegar = new QAction(MainWindow);
        actionPegar->setObjectName(QStringLiteral("actionPegar"));
        actionTeclado = new QAction(MainWindow);
        actionTeclado->setObjectName(QStringLiteral("actionTeclado"));
        actionConfiguraci_n_de_ejes = new QAction(MainWindow);
        actionConfiguraci_n_de_ejes->setObjectName(QStringLiteral("actionConfiguraci_n_de_ejes"));
        actionAtributos_del_Grafico = new QAction(MainWindow);
        actionAtributos_del_Grafico->setObjectName(QStringLiteral("actionAtributos_del_Grafico"));
        actionConfiguraciones = new QAction(MainWindow);
        actionConfiguraciones->setObjectName(QStringLiteral("actionConfiguraciones"));
        action_Que_hay_de_nuevo = new QAction(MainWindow);
        action_Que_hay_de_nuevo->setObjectName(QStringLiteral("action_Que_hay_de_nuevo"));
        actionContactanos = new QAction(MainWindow);
        actionContactanos->setObjectName(QStringLiteral("actionContactanos"));
        actionMore = new QAction(MainWindow);
        actionMore->setObjectName(QStringLiteral("actionMore"));
        actionLess = new QAction(MainWindow);
        actionLess->setObjectName(QStringLiteral("actionLess"));
        actionCheckUncheck = new QAction(MainWindow);
        actionCheckUncheck->setObjectName(QStringLiteral("actionCheckUncheck"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheckUncheck->setIcon(icon5);
        actionExample = new QAction(MainWindow);
        actionExample->setObjectName(QStringLiteral("actionExample"));
        actionTable = new QAction(MainWindow);
        actionTable->setObjectName(QStringLiteral("actionTable"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/table.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTable->setIcon(icon6);
        actionZoomAll = new QAction(MainWindow);
        actionZoomAll->setObjectName(QStringLiteral("actionZoomAll"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/restorezoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomAll->setIcon(icon7);
        actionZoomMore = new QAction(MainWindow);
        actionZoomMore->setObjectName(QStringLiteral("actionZoomMore"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/zoommore.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomMore->setIcon(icon8);
        actionZoomLess = new QAction(MainWindow);
        actionZoomLess->setObjectName(QStringLiteral("actionZoomLess"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/zoomless.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomLess->setIcon(icon9);
        actionSaveGraph = new QAction(MainWindow);
        actionSaveGraph->setObjectName(QStringLiteral("actionSaveGraph"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/saveGraph.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveGraph->setIcon(icon10);
        actionShareFacebook = new QAction(MainWindow);
        actionShareFacebook->setObjectName(QStringLiteral("actionShareFacebook"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/facebook.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionShareFacebook->setIcon(icon11);
        actionCopyToClipboard = new QAction(MainWindow);
        actionCopyToClipboard->setObjectName(QStringLiteral("actionCopyToClipboard"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/copyclipboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopyToClipboard->setIcon(icon12);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setEnabled(true);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        splitterEquations_Table_Graphs = new QSplitter(centralWidget);
        splitterEquations_Table_Graphs->setObjectName(QStringLiteral("splitterEquations_Table_Graphs"));
        splitterEquations_Table_Graphs->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitterEquations_Table_Graphs);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalEquations = new QHBoxLayout(layoutWidget);
        horizontalEquations->setSpacing(6);
        horizontalEquations->setContentsMargins(11, 11, 11, 11);
        horizontalEquations->setObjectName(QStringLiteral("horizontalEquations"));
        horizontalEquations->setContentsMargins(0, 0, 0, 0);
        verticalLayoutEquations = new QVBoxLayout();
        verticalLayoutEquations->setSpacing(6);
        verticalLayoutEquations->setObjectName(QStringLiteral("verticalLayoutEquations"));
        grpEquations = new QGroupBox(layoutWidget);
        grpEquations->setObjectName(QStringLiteral("grpEquations"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grpEquations->sizePolicy().hasHeightForWidth());
        grpEquations->setSizePolicy(sizePolicy);
        grpEquations->setFlat(false);
        verticalLayout_6 = new QVBoxLayout(grpEquations);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        checkBox = new QCheckBox(grpEquations);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        graphicsView = new QGraphicsView(grpEquations);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(20, 20));
        graphicsView->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(graphicsView);

        comboBox = new QComboBox(grpEquations);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        lineEdit = new QLineEdit(grpEquations);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_2);


        verticalLayoutEquations->addWidget(grpEquations);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lblStatus = new QLabel(layoutWidget);
        lblStatus->setObjectName(QStringLiteral("lblStatus"));
        lblStatus->setMinimumSize(QSize(0, 15));
        lblStatus->setMaximumSize(QSize(16777215, 15));

        verticalLayout_3->addWidget(lblStatus);

        txtStatus = new QTextEdit(layoutWidget);
        txtStatus->setObjectName(QStringLiteral("txtStatus"));
        txtStatus->setMinimumSize(QSize(0, 20));
        txtStatus->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(txtStatus);

        btnRedraw = new QPushButton(layoutWidget);
        btnRedraw->setObjectName(QStringLiteral("btnRedraw"));

        verticalLayout_3->addWidget(btnRedraw);


        verticalLayoutEquations->addLayout(verticalLayout_3);

        tabWidget_2 = new QTabWidget(layoutWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setTabPosition(QTabWidget::South);
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_2->addTab(tab_3, QString());

        verticalLayoutEquations->addWidget(tabWidget_2);


        horizontalEquations->addLayout(verticalLayoutEquations);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalEquations->addWidget(line_2);

        splitterEquations_Table_Graphs->addWidget(layoutWidget);
        splitter_Table_Graph = new QSplitter(splitterEquations_Table_Graphs);
        splitter_Table_Graph->setObjectName(QStringLiteral("splitter_Table_Graph"));
        splitter_Table_Graph->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(splitter_Table_Graph);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        horizontalLayoutTable = new QHBoxLayout(layoutWidget1);
        horizontalLayoutTable->setSpacing(6);
        horizontalLayoutTable->setContentsMargins(11, 11, 11, 11);
        horizontalLayoutTable->setObjectName(QStringLiteral("horizontalLayoutTable"));
        horizontalLayoutTable->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(layoutWidget1);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(125, 0));
        tableWidget->setMaximumSize(QSize(140, 16777215));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        horizontalLayoutTable->addWidget(tableWidget);

        line_3 = new QFrame(layoutWidget1);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayoutTable->addWidget(line_3);

        splitter_Table_Graph->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter_Table_Graph);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        verticalLayoutGraph = new QVBoxLayout(layoutWidget2);
        verticalLayoutGraph->setSpacing(6);
        verticalLayoutGraph->setContentsMargins(11, 11, 11, 11);
        verticalLayoutGraph->setObjectName(QStringLiteral("verticalLayoutGraph"));
        verticalLayoutGraph->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        chkGrid = new QCheckBox(layoutWidget2);
        chkGrid->setObjectName(QStringLiteral("chkGrid"));

        verticalLayout_4->addWidget(chkGrid);

        horizontalSlider = new QSlider(layoutWidget2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider);


        verticalLayoutGraph->addLayout(verticalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalSlider = new QSlider(layoutWidget2);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(verticalSlider);

        tabGraphics = new QTabWidget(layoutWidget2);
        tabGraphics->setObjectName(QStringLiteral("tabGraphics"));
        tabGraphics->setMinimumSize(QSize(500, 0));
        tabGraphics->setMaximumSize(QSize(16777215, 16777215));
        tab2D = new QWidget();
        tab2D->setObjectName(QStringLiteral("tab2D"));
        verticalLayout_7 = new QVBoxLayout(tab2D);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        myopenglw = new Myopengl(tab2D);
        myopenglw->setObjectName(QStringLiteral("myopenglw"));

        verticalLayout_7->addWidget(myopenglw);

        tabGraphics->addTab(tab2D, QString());
        tab3D = new QWidget();
        tab3D->setObjectName(QStringLiteral("tab3D"));
        verticalLayout_8 = new QVBoxLayout(tab3D);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        openGLWidget3D = new Myopengl2(tab3D);
        openGLWidget3D->setObjectName(QStringLiteral("openGLWidget3D"));

        verticalLayout_8->addWidget(openGLWidget3D);

        tabGraphics->addTab(tab3D, QString());

        horizontalLayout_5->addWidget(tabGraphics);


        verticalLayoutGraph->addLayout(horizontalLayout_5);

        splitter_Table_Graph->addWidget(layoutWidget2);
        splitterEquations_Table_Graphs->addWidget(splitter_Table_Graph);

        verticalLayout->addWidget(splitterEquations_Table_Graphs);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 20));
        menuEasyGraph_using_MVC = new QMenu(menuBar);
        menuEasyGraph_using_MVC->setObjectName(QStringLiteral("menuEasyGraph_using_MVC"));
        menuJair = new QMenu(menuBar);
        menuJair->setObjectName(QStringLiteral("menuJair"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        menuVer = new QMenu(menuBar);
        menuVer->setObjectName(QStringLiteral("menuVer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuEasyGraph_using_MVC->menuAction());
        menuBar->addAction(menuJair->menuAction());
        menuBar->addAction(menuVer->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuEasyGraph_using_MVC->addAction(actionNuevo);
        menuEasyGraph_using_MVC->addAction(actionAbrir);
        menuEasyGraph_using_MVC->addAction(actionGuardar);
        menuEasyGraph_using_MVC->addAction(actionSaveAs);
        menuEasyGraph_using_MVC->addAction(actionExportar_como_imagen);
        menuEasyGraph_using_MVC->addAction(actionImprimir_como_imagen);
        menuEasyGraph_using_MVC->addAction(actionSalir);
        menuJair->addAction(actionInsertar_Ecuaci_n);
        menuJair->addAction(actionRemover_ecuaci_n);
        menuJair->addSeparator();
        menuJair->addAction(actionCortar);
        menuJair->addAction(actionCopiar);
        menuJair->addAction(actionPegar);
        menuJair->addSeparator();
        menuJair->addAction(actionReiniciar_Configuraciones);
        menuAyuda->addAction(actionAcerca_de);
        menuAyuda->addAction(actionTutorial);
        menuAyuda->addAction(action_Que_hay_de_nuevo);
        menuAyuda->addAction(actionContactanos);
        menuVer->addAction(actionTeclado);
        menuVer->addAction(actionConfiguraci_n_de_ejes);
        menuVer->addAction(actionAtributos_del_Grafico);
        menuVer->addSeparator();
        menuVer->addAction(actionConfiguraciones);
        mainToolBar->addAction(actionNuevo);
        mainToolBar->addAction(actionAbrir);
        mainToolBar->addAction(actionGuardar);
        mainToolBar->addAction(actionImprimir_como_imagen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionMore);
        mainToolBar->addAction(actionLess);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCheckUncheck);
        mainToolBar->addAction(actionExample);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionTable);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSaveGraph);
        mainToolBar->addAction(actionCopyToClipboard);
        mainToolBar->addAction(actionShareFacebook);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZoomAll);
        mainToolBar->addAction(actionZoomMore);
        mainToolBar->addAction(actionZoomLess);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabGraphics->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "easyGraph - OAD", 0));
        actionNuevo->setText(QApplication::translate("MainWindow", "Nuevo", 0));
        actionNuevo->setShortcut(QApplication::translate("MainWindow", "N", 0));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", 0));
        actionAbrir->setShortcut(QApplication::translate("MainWindow", "O", 0));
        actionGuardar->setText(QApplication::translate("MainWindow", "Guardar...", 0));
        actionGuardar->setShortcut(QApplication::translate("MainWindow", "S", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Guardar Como ...", 0));
        actionSaveAs->setShortcut(QApplication::translate("MainWindow", "A", 0));
        actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de ...", 0));
        actionTutorial->setText(QApplication::translate("MainWindow", "Tutorial", 0));
        actionExportar_como_imagen->setText(QApplication::translate("MainWindow", "Exportar como imagen ...", 0));
        actionImprimir_como_imagen->setText(QApplication::translate("MainWindow", "Imprimir como imagen ...", 0));
        actionImprimir_como_imagen->setShortcut(QApplication::translate("MainWindow", "P", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        actionInsertar_Ecuaci_n->setText(QApplication::translate("MainWindow", "Insertar Ecuaci\303\263n", 0));
        actionRemover_ecuaci_n->setText(QApplication::translate("MainWindow", "Remover Ecuaci\303\263n", 0));
        actionReiniciar_Configuraciones->setText(QApplication::translate("MainWindow", "Reiniciar Configuraciones", 0));
        actionCortar->setText(QApplication::translate("MainWindow", "Cortar", 0));
        actionCopiar->setText(QApplication::translate("MainWindow", "Copiar", 0));
        actionPegar->setText(QApplication::translate("MainWindow", "Pegar", 0));
        actionTeclado->setText(QApplication::translate("MainWindow", "Teclado", 0));
        actionConfiguraci_n_de_ejes->setText(QApplication::translate("MainWindow", "Configuraci\303\263n de ejes", 0));
        actionAtributos_del_Grafico->setText(QApplication::translate("MainWindow", "Atributos del Grafico", 0));
        actionConfiguraciones->setText(QApplication::translate("MainWindow", "Configuraciones", 0));
        action_Que_hay_de_nuevo->setText(QApplication::translate("MainWindow", "\302\277Que hay de nuevo?", 0));
        actionContactanos->setText(QApplication::translate("MainWindow", "Contactanos ...", 0));
        actionMore->setText(QApplication::translate("MainWindow", "+", 0));
#ifndef QT_NO_TOOLTIP
        actionMore->setToolTip(QApplication::translate("MainWindow", "Agregar Nueva ecuaci\303\263n", 0));
#endif // QT_NO_TOOLTIP
        actionLess->setText(QApplication::translate("MainWindow", "-", 0));
#ifndef QT_NO_TOOLTIP
        actionLess->setToolTip(QApplication::translate("MainWindow", "Quitar ecuaci\303\263n", 0));
#endif // QT_NO_TOOLTIP
        actionCheckUncheck->setText(QApplication::translate("MainWindow", "check/uncheck", 0));
#ifndef QT_NO_TOOLTIP
        actionCheckUncheck->setToolTip(QApplication::translate("MainWindow", "Seleccionar/Deseleccionar todas las ecuaciones", 0));
#endif // QT_NO_TOOLTIP
        actionExample->setText(QApplication::translate("MainWindow", "Ejemplo", 0));
#ifndef QT_NO_TOOLTIP
        actionExample->setToolTip(QApplication::translate("MainWindow", "Insertar un Ejemplo", 0));
#endif // QT_NO_TOOLTIP
        actionTable->setText(QApplication::translate("MainWindow", "Tabla", 0));
#ifndef QT_NO_TOOLTIP
        actionTable->setToolTip(QApplication::translate("MainWindow", "Mostrar/Esconder Tabla", 0));
#endif // QT_NO_TOOLTIP
        actionZoomAll->setText(QApplication::translate("MainWindow", "zoomAll", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomAll->setToolTip(QApplication::translate("MainWindow", "Restaurar Zoom", 0));
#endif // QT_NO_TOOLTIP
        actionZoomMore->setText(QApplication::translate("MainWindow", "zoomMore", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomMore->setToolTip(QApplication::translate("MainWindow", "Aumentar Zoom", 0));
#endif // QT_NO_TOOLTIP
        actionZoomLess->setText(QApplication::translate("MainWindow", "zoomLess", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomLess->setToolTip(QApplication::translate("MainWindow", "Disminuir Zoom", 0));
#endif // QT_NO_TOOLTIP
        actionSaveGraph->setText(QApplication::translate("MainWindow", "SaveGraph", 0));
#ifndef QT_NO_TOOLTIP
        actionSaveGraph->setToolTip(QApplication::translate("MainWindow", "Guardar Grafico", 0));
#endif // QT_NO_TOOLTIP
        actionShareFacebook->setText(QApplication::translate("MainWindow", "ShareFacebook", 0));
#ifndef QT_NO_TOOLTIP
        actionShareFacebook->setToolTip(QApplication::translate("MainWindow", "Compartir en Facebook", 0));
#endif // QT_NO_TOOLTIP
        actionCopyToClipboard->setText(QApplication::translate("MainWindow", "CopyToClipboard", 0));
#ifndef QT_NO_TOOLTIP
        actionCopyToClipboard->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Copiar al Portapapeles</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        grpEquations->setTitle(QApplication::translate("MainWindow", "Ecuaciones", 0));
        checkBox->setText(QString());
        lblStatus->setText(QApplication::translate("MainWindow", "Estado:", 0));
        btnRedraw->setText(QApplication::translate("MainWindow", "Redibujar Todo", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Tab 2", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Z", 0));
        chkGrid->setText(QApplication::translate("MainWindow", "Ver Cuadricula", 0));
        tabGraphics->setTabText(tabGraphics->indexOf(tab2D), QApplication::translate("MainWindow", "2D", 0));
        tabGraphics->setTabText(tabGraphics->indexOf(tab3D), QApplication::translate("MainWindow", "3D", 0));
        menuEasyGraph_using_MVC->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuJair->setTitle(QApplication::translate("MainWindow", "Editar", 0));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0));
        menuVer->setTitle(QApplication::translate("MainWindow", "Ver", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

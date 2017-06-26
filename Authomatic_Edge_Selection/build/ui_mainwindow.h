/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 13 14:39:06 2017
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QVTKWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QVTKWidget *qvtkWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Load_PCD;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Edge_Detect;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Compute;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Clear_List;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Start_Live_Stream;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *Stop_Live_Stream;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_2;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout_7;
    QLabel *label_24;
    QLabel *label_26;
    QDoubleSpinBox *Filter_x_neg;
    QLabel *label_23;
    QDoubleSpinBox *Filter_z_neg;
    QDoubleSpinBox *Filter_z_pos;
    QDoubleSpinBox *Filter_y_neg;
    QDoubleSpinBox *Filter_x_pos;
    QDoubleSpinBox *Filter_y_pos;
    QPushButton *Filter_Edge;
    QLabel *label_25;
    QLabel *label_21;
    QLabel *label_22;
    QSpacerItem *verticalSpacer_2;
    QLabel *WorkObj_Label;
    QLineEdit *WorkObj_Frame;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QLineEdit *Gantry_x;
    QLabel *label_16;
    QLineEdit *Gantry_y;
    QLabel *label_17;
    QLineEdit *Gantry_z;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QPushButton *Update_SB;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_SB_x;
    QLabel *label_4;
    QLineEdit *lineEdit_SB_y;
    QLabel *label_5;
    QLineEdit *lineEdit_SB_z;
    QGroupBox *groupBox;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_Quaternion2Euler;
    QPushButton *pushButton_Euler2Quaternion;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLineEdit *lineEdit_q0;
    QLabel *label_9;
    QLineEdit *lineEdit_q1;
    QLabel *label_10;
    QLineEdit *lineEdit_q2;
    QLabel *label_11;
    QLineEdit *lineEdit_q3;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_pitch;
    QLabel *label_14;
    QLineEdit *lineEdit_yaw;
    QLineEdit *lineEdit_roll;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_20;
    QGridLayout *gridLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_RobotPos_x;
    QLabel *label_18;
    QLineEdit *lineEdit_RobotPos_y;
    QLabel *label_19;
    QLineEdit *lineEdit_RobotPos_z;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(919, 591);
        MainWindow->setMinimumSize(QSize(700, 0));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(tab);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setOrientation(Qt::Horizontal);
        qvtkWidget = new QVTKWidget(splitter);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setMinimumSize(QSize(300, 0));
        splitter->addWidget(qvtkWidget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Load_PCD = new QPushButton(layoutWidget);
        Load_PCD->setObjectName(QString::fromUtf8("Load_PCD"));
        sizePolicy.setHeightForWidth(Load_PCD->sizePolicy().hasHeightForWidth());
        Load_PCD->setSizePolicy(sizePolicy);
        Load_PCD->setMaximumSize(QSize(14300000, 13400000));

        horizontalLayout->addWidget(Load_PCD);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Edge_Detect = new QPushButton(layoutWidget);
        Edge_Detect->setObjectName(QString::fromUtf8("Edge_Detect"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Edge_Detect->sizePolicy().hasHeightForWidth());
        Edge_Detect->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(Edge_Detect);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Compute = new QPushButton(layoutWidget);
        Compute->setObjectName(QString::fromUtf8("Compute"));
        sizePolicy2.setHeightForWidth(Compute->sizePolicy().hasHeightForWidth());
        Compute->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(Compute);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        Clear_List = new QPushButton(layoutWidget);
        Clear_List->setObjectName(QString::fromUtf8("Clear_List"));
        Clear_List->setMaximumSize(QSize(14300000, 14300000));

        horizontalLayout->addWidget(Clear_List);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        Start_Live_Stream = new QPushButton(layoutWidget);
        Start_Live_Stream->setObjectName(QString::fromUtf8("Start_Live_Stream"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Start_Live_Stream->sizePolicy().hasHeightForWidth());
        Start_Live_Stream->setSizePolicy(sizePolicy3);
        Start_Live_Stream->setMaximumSize(QSize(14300000, 14300000));

        horizontalLayout_3->addWidget(Start_Live_Stream);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        Stop_Live_Stream = new QPushButton(layoutWidget);
        Stop_Live_Stream->setObjectName(QString::fromUtf8("Stop_Live_Stream"));
        sizePolicy3.setHeightForWidth(Stop_Live_Stream->sizePolicy().hasHeightForWidth());
        Stop_Live_Stream->setSizePolicy(sizePolicy3);
        Stop_Live_Stream->setMaximumSize(QSize(14300000, 14300000));

        horizontalLayout_3->addWidget(Stop_Live_Stream);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(100, 0));
        listWidget->setMaximumSize(QSize(10000, 16777215));

        verticalLayout_3->addWidget(listWidget);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_7->addWidget(label_24, 3, 0, 1, 1);

        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_7->addWidget(label_26, 3, 1, 1, 1);

        Filter_x_neg = new QDoubleSpinBox(layoutWidget);
        Filter_x_neg->setObjectName(QString::fromUtf8("Filter_x_neg"));

        gridLayout_7->addWidget(Filter_x_neg, 4, 0, 1, 1);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_7->addWidget(label_23, 1, 0, 1, 1);

        Filter_z_neg = new QDoubleSpinBox(layoutWidget);
        Filter_z_neg->setObjectName(QString::fromUtf8("Filter_z_neg"));

        gridLayout_7->addWidget(Filter_z_neg, 4, 2, 1, 1);

        Filter_z_pos = new QDoubleSpinBox(layoutWidget);
        Filter_z_pos->setObjectName(QString::fromUtf8("Filter_z_pos"));

        gridLayout_7->addWidget(Filter_z_pos, 2, 2, 1, 1);

        Filter_y_neg = new QDoubleSpinBox(layoutWidget);
        Filter_y_neg->setObjectName(QString::fromUtf8("Filter_y_neg"));

        gridLayout_7->addWidget(Filter_y_neg, 4, 1, 1, 1);

        Filter_x_pos = new QDoubleSpinBox(layoutWidget);
        Filter_x_pos->setObjectName(QString::fromUtf8("Filter_x_pos"));

        gridLayout_7->addWidget(Filter_x_pos, 2, 0, 1, 1);

        Filter_y_pos = new QDoubleSpinBox(layoutWidget);
        Filter_y_pos->setObjectName(QString::fromUtf8("Filter_y_pos"));

        gridLayout_7->addWidget(Filter_y_pos, 2, 1, 1, 1);

        Filter_Edge = new QPushButton(layoutWidget);
        Filter_Edge->setObjectName(QString::fromUtf8("Filter_Edge"));

        gridLayout_7->addWidget(Filter_Edge, 0, 0, 1, 2);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_7->addWidget(label_25, 1, 1, 1, 1);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_7->addWidget(label_21, 1, 2, 1, 1);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_7->addWidget(label_22, 3, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        WorkObj_Label = new QLabel(layoutWidget);
        WorkObj_Label->setObjectName(QString::fromUtf8("WorkObj_Label"));

        verticalLayout_3->addWidget(WorkObj_Label);

        WorkObj_Frame = new QLineEdit(layoutWidget);
        WorkObj_Frame->setObjectName(QString::fromUtf8("WorkObj_Frame"));

        verticalLayout_3->addWidget(WorkObj_Frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        splitter->addWidget(layoutWidget);

        horizontalLayout_2->addWidget(splitter);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 30, 150, 181));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_6->addWidget(label_7);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        Gantry_x = new QLineEdit(layoutWidget1);
        Gantry_x->setObjectName(QString::fromUtf8("Gantry_x"));

        gridLayout_3->addWidget(Gantry_x, 0, 1, 1, 1);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 1, 0, 1, 1);

        Gantry_y = new QLineEdit(layoutWidget1);
        Gantry_y->setObjectName(QString::fromUtf8("Gantry_y"));

        gridLayout_3->addWidget(Gantry_y, 1, 1, 1, 1);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 2, 0, 1, 1);

        Gantry_z = new QLineEdit(layoutWidget1);
        Gantry_z->setObjectName(QString::fromUtf8("Gantry_z"));

        gridLayout_3->addWidget(Gantry_z, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 2, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget_2 = new QWidget(tab_3);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 20, 191, 141));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_7->addWidget(label);

        Update_SB = new QPushButton(layoutWidget_2);
        Update_SB->setObjectName(QString::fromUtf8("Update_SB"));

        verticalLayout_7->addWidget(Update_SB);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_SB_x = new QLineEdit(layoutWidget_2);
        lineEdit_SB_x->setObjectName(QString::fromUtf8("lineEdit_SB_x"));

        gridLayout_5->addWidget(lineEdit_SB_x, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_SB_y = new QLineEdit(layoutWidget_2);
        lineEdit_SB_y->setObjectName(QString::fromUtf8("lineEdit_SB_y"));

        gridLayout_5->addWidget(lineEdit_SB_y, 1, 1, 2, 1);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 2, 0, 2, 1);

        lineEdit_SB_z = new QLineEdit(layoutWidget_2);
        lineEdit_SB_z->setObjectName(QString::fromUtf8("lineEdit_SB_z"));

        gridLayout_5->addWidget(lineEdit_SB_z, 3, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_5);

        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(320, 20, 357, 181));
        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 30, 318, 143));
        gridLayout_4 = new QGridLayout(layoutWidget_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_Quaternion2Euler = new QPushButton(layoutWidget_3);
        pushButton_Quaternion2Euler->setObjectName(QString::fromUtf8("pushButton_Quaternion2Euler"));
        sizePolicy2.setHeightForWidth(pushButton_Quaternion2Euler->sizePolicy().hasHeightForWidth());
        pushButton_Quaternion2Euler->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_Quaternion2Euler, 0, 0, 1, 1);

        pushButton_Euler2Quaternion = new QPushButton(layoutWidget_3);
        pushButton_Euler2Quaternion->setObjectName(QString::fromUtf8("pushButton_Euler2Quaternion"));
        sizePolicy2.setHeightForWidth(pushButton_Euler2Quaternion->sizePolicy().hasHeightForWidth());
        pushButton_Euler2Quaternion->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_Euler2Quaternion, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_q0 = new QLineEdit(layoutWidget_3);
        lineEdit_q0->setObjectName(QString::fromUtf8("lineEdit_q0"));

        gridLayout->addWidget(lineEdit_q0, 0, 1, 1, 2);

        label_9 = new QLabel(layoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        lineEdit_q1 = new QLineEdit(layoutWidget_3);
        lineEdit_q1->setObjectName(QString::fromUtf8("lineEdit_q1"));

        gridLayout->addWidget(lineEdit_q1, 1, 1, 1, 2);

        label_10 = new QLabel(layoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        lineEdit_q2 = new QLineEdit(layoutWidget_3);
        lineEdit_q2->setObjectName(QString::fromUtf8("lineEdit_q2"));

        gridLayout->addWidget(lineEdit_q2, 2, 1, 1, 2);

        label_11 = new QLabel(layoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 0, 1, 1);

        lineEdit_q3 = new QLineEdit(layoutWidget_3);
        lineEdit_q3->setObjectName(QString::fromUtf8("lineEdit_q3"));

        gridLayout->addWidget(lineEdit_q3, 4, 1, 1, 2);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_12 = new QLabel(layoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        label_13 = new QLabel(layoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 1, 0, 1, 1);

        lineEdit_pitch = new QLineEdit(layoutWidget_3);
        lineEdit_pitch->setObjectName(QString::fromUtf8("lineEdit_pitch"));

        gridLayout_2->addWidget(lineEdit_pitch, 1, 1, 1, 1);

        label_14 = new QLabel(layoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 2, 0, 1, 1);

        lineEdit_yaw = new QLineEdit(layoutWidget_3);
        lineEdit_yaw->setObjectName(QString::fromUtf8("lineEdit_yaw"));

        gridLayout_2->addWidget(lineEdit_yaw, 2, 1, 1, 1);

        lineEdit_roll = new QLineEdit(layoutWidget_3);
        lineEdit_roll->setObjectName(QString::fromUtf8("lineEdit_roll"));

        gridLayout_2->addWidget(lineEdit_roll, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 1, 1, 1);

        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 180, 181, 111));
        verticalLayout_8 = new QVBoxLayout(layoutWidget2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_8->addWidget(label_20);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_RobotPos_x = new QLineEdit(layoutWidget2);
        lineEdit_RobotPos_x->setObjectName(QString::fromUtf8("lineEdit_RobotPos_x"));

        gridLayout_6->addWidget(lineEdit_RobotPos_x, 0, 1, 1, 1);

        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_6->addWidget(label_18, 1, 0, 1, 1);

        lineEdit_RobotPos_y = new QLineEdit(layoutWidget2);
        lineEdit_RobotPos_y->setObjectName(QString::fromUtf8("lineEdit_RobotPos_y"));

        gridLayout_6->addWidget(lineEdit_RobotPos_y, 1, 1, 1, 1);

        label_19 = new QLabel(layoutWidget2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_6->addWidget(label_19, 2, 0, 1, 1);

        lineEdit_RobotPos_z = new QLineEdit(layoutWidget2);
        lineEdit_RobotPos_z->setObjectName(QString::fromUtf8("lineEdit_RobotPos_z"));

        gridLayout_6->addWidget(lineEdit_RobotPos_z, 2, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout_6);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_5->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        Load_PCD->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        Edge_Detect->setText(QApplication::translate("MainWindow", "Edge Detection", 0, QApplication::UnicodeUTF8));
        Compute->setText(QApplication::translate("MainWindow", "Compute WorkObj \n"
" Frame", 0, QApplication::UnicodeUTF8));
        Clear_List->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        Start_Live_Stream->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        Stop_Live_Stream->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Position of selected points", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "-x_min", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "-y_min", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "+x_max", 0, QApplication::UnicodeUTF8));
        Filter_Edge->setText(QApplication::translate("MainWindow", "Filter", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "+y_max", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "+z_max", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "+z_min", 0, QApplication::UnicodeUTF8));
        WorkObj_Label->setText(QApplication::translate("MainWindow", "WorkObj Frame", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Main Window", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Gantry position ", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        Gantry_x->setText(QApplication::translate("MainWindow", "3600.1", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        Gantry_y->setText(QApplication::translate("MainWindow", "92.3", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "z", 0, QApplication::UnicodeUTF8));
        Gantry_z->setText(QApplication::translate("MainWindow", "649.2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Setting", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Sensor-Base Transformation", 0, QApplication::UnicodeUTF8));
        Update_SB->setText(QApplication::translate("MainWindow", "Compute/Update", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        lineEdit_SB_x->setText(QApplication::translate("MainWindow", "103.45", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        lineEdit_SB_y->setText(QApplication::translate("MainWindow", "-352.95", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "z", 0, QApplication::UnicodeUTF8));
        lineEdit_SB_z->setText(QApplication::translate("MainWindow", "894.91", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Converter", 0, QApplication::UnicodeUTF8));
        pushButton_Quaternion2Euler->setText(QApplication::translate("MainWindow", "Quaternion->Euler", 0, QApplication::UnicodeUTF8));
        pushButton_Euler2Quaternion->setText(QApplication::translate("MainWindow", "Euler->Quaternion", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "q0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "q1", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "q2", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "q3", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Roll", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Pitch", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Yaw", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Point in Robot Base Frame", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "z", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Calibration", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

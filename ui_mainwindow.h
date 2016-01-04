/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionClose;
    QAction *actionTest_Mode;
    QAction *actionCheck_for_updates;
    QAction *actionExpression_Input;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_save;
    QPushButton *pushButton_reset;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_midi;
    QGridLayout *gridLayout;
    QComboBox *comboBox_type;
    QLabel *label_channel;
    QSpinBox *spinBox_val;
    QLabel *label_val;
    QSpinBox *spinBox_num;
    QLabel *label_type;
    QSpinBox *spinBox_channel;
    QSpinBox *spinBox_val_max;
    QLabel *label_num;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_midi_3;
    QGridLayout *gridLayout_6;
    QLabel *label_num_3;
    QLabel *label_channel_3;
    QLabel *label_val_3;
    QLabel *label_type_3;
    QComboBox *comboBox_type_3;
    QSpinBox *spinBox_num_3;
    QSpinBox *spinBox_val_3;
    QSpinBox *spinBox_channel_3;
    QGroupBox *groupBox_midi_2;
    QGridLayout *gridLayout_5;
    QSpinBox *spinBox_val_2;
    QLabel *label_type_2;
    QLabel *label_num_2;
    QLabel *label_val_2;
    QLabel *label_channel_2;
    QComboBox *comboBox_type_2;
    QSpinBox *spinBox_num_2;
    QSpinBox *spinBox_channel_2;
    QGroupBox *groupBox_midi_4;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_type_4;
    QSpinBox *spinBox_num_4;
    QSpinBox *spinBox_val_4;
    QSpinBox *spinBox_channel_4;
    QLabel *label_num_4;
    QLabel *label_val_4;
    QLabel *label_channel_4;
    QLabel *label_type_4;
    QGroupBox *groupBox_midi_5;
    QGridLayout *gridLayout_8;
    QLabel *label_type_5;
    QLabel *label_num_5;
    QLabel *label_val_5;
    QLabel *label_channel_5;
    QComboBox *comboBox_type_5;
    QSpinBox *spinBox_num_5;
    QSpinBox *spinBox_val_5;
    QSpinBox *spinBox_channel_5;
    QGroupBox *groupBox_presetDetails;
    QGridLayout *gridLayout_2;
    QLabel *label_bank;
    QLabel *label_switch;
    QLabel *label_presetName;
    QComboBox *comboBox_bank;
    QComboBox *comboBox_switch;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_shortName;
    QTextBrowser *textBrowser_output;
    QMenuBar *menuBar;
    QMenu *menuDevice;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(578, 806);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionTest_Mode = new QAction(MainWindow);
        actionTest_Mode->setObjectName(QStringLiteral("actionTest_Mode"));
        actionTest_Mode->setCheckable(true);
        actionCheck_for_updates = new QAction(MainWindow);
        actionCheck_for_updates->setObjectName(QStringLiteral("actionCheck_for_updates"));
        actionExpression_Input = new QAction(MainWindow);
        actionExpression_Input->setObjectName(QStringLiteral("actionExpression_Input"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setMinimumSize(QSize(100, 40));

        gridLayout_3->addWidget(pushButton_save, 6, 1, 1, 1);

        pushButton_reset = new QPushButton(centralWidget);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setMinimumSize(QSize(100, 40));

        gridLayout_3->addWidget(pushButton_reset, 6, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 6, 3, 1, 1);

        groupBox_midi = new QGroupBox(centralWidget);
        groupBox_midi->setObjectName(QStringLiteral("groupBox_midi"));
        gridLayout = new QGridLayout(groupBox_midi);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_type = new QComboBox(groupBox_midi);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        comboBox_type->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(comboBox_type, 1, 0, 1, 1);

        label_channel = new QLabel(groupBox_midi);
        label_channel->setObjectName(QStringLiteral("label_channel"));

        gridLayout->addWidget(label_channel, 0, 3, 1, 1);

        spinBox_val = new QSpinBox(groupBox_midi);
        spinBox_val->setObjectName(QStringLiteral("spinBox_val"));
        spinBox_val->setMinimumSize(QSize(75, 0));
        spinBox_val->setAlignment(Qt::AlignCenter);
        spinBox_val->setMinimum(0);
        spinBox_val->setMaximum(127);

        gridLayout->addWidget(spinBox_val, 1, 2, 1, 1);

        label_val = new QLabel(groupBox_midi);
        label_val->setObjectName(QStringLiteral("label_val"));

        gridLayout->addWidget(label_val, 0, 2, 1, 1);

        spinBox_num = new QSpinBox(groupBox_midi);
        spinBox_num->setObjectName(QStringLiteral("spinBox_num"));
        spinBox_num->setMinimumSize(QSize(100, 0));
        spinBox_num->setAlignment(Qt::AlignCenter);
        spinBox_num->setMinimum(0);
        spinBox_num->setMaximum(127);

        gridLayout->addWidget(spinBox_num, 1, 1, 1, 1);

        label_type = new QLabel(groupBox_midi);
        label_type->setObjectName(QStringLiteral("label_type"));

        gridLayout->addWidget(label_type, 0, 0, 1, 1);

        spinBox_channel = new QSpinBox(groupBox_midi);
        spinBox_channel->setObjectName(QStringLiteral("spinBox_channel"));
        spinBox_channel->setMinimumSize(QSize(100, 0));
        spinBox_channel->setAlignment(Qt::AlignCenter);
        spinBox_channel->setMinimum(1);
        spinBox_channel->setMaximum(16);

        gridLayout->addWidget(spinBox_channel, 1, 3, 1, 1);

        spinBox_val_max = new QSpinBox(groupBox_midi);
        spinBox_val_max->setObjectName(QStringLiteral("spinBox_val_max"));
        spinBox_val_max->setMinimumSize(QSize(75, 0));
        spinBox_val_max->setAlignment(Qt::AlignCenter);
        spinBox_val_max->setMinimum(0);
        spinBox_val_max->setMaximum(127);

        gridLayout->addWidget(spinBox_val_max, 2, 2, 1, 1);

        label_num = new QLabel(groupBox_midi);
        label_num->setObjectName(QStringLiteral("label_num"));

        gridLayout->addWidget(label_num, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_midi, 1, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 6, 0, 1, 1);

        groupBox_midi_3 = new QGroupBox(centralWidget);
        groupBox_midi_3->setObjectName(QStringLiteral("groupBox_midi_3"));
        gridLayout_6 = new QGridLayout(groupBox_midi_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_num_3 = new QLabel(groupBox_midi_3);
        label_num_3->setObjectName(QStringLiteral("label_num_3"));

        gridLayout_6->addWidget(label_num_3, 0, 1, 1, 1);

        label_channel_3 = new QLabel(groupBox_midi_3);
        label_channel_3->setObjectName(QStringLiteral("label_channel_3"));

        gridLayout_6->addWidget(label_channel_3, 0, 3, 1, 1);

        label_val_3 = new QLabel(groupBox_midi_3);
        label_val_3->setObjectName(QStringLiteral("label_val_3"));

        gridLayout_6->addWidget(label_val_3, 0, 2, 1, 1);

        label_type_3 = new QLabel(groupBox_midi_3);
        label_type_3->setObjectName(QStringLiteral("label_type_3"));

        gridLayout_6->addWidget(label_type_3, 0, 0, 1, 1);

        comboBox_type_3 = new QComboBox(groupBox_midi_3);
        comboBox_type_3->setObjectName(QStringLiteral("comboBox_type_3"));
        comboBox_type_3->setMinimumSize(QSize(200, 0));

        gridLayout_6->addWidget(comboBox_type_3, 1, 0, 1, 1);

        spinBox_num_3 = new QSpinBox(groupBox_midi_3);
        spinBox_num_3->setObjectName(QStringLiteral("spinBox_num_3"));
        spinBox_num_3->setMinimumSize(QSize(100, 0));
        spinBox_num_3->setAlignment(Qt::AlignCenter);
        spinBox_num_3->setMinimum(0);
        spinBox_num_3->setMaximum(127);

        gridLayout_6->addWidget(spinBox_num_3, 1, 1, 1, 1);

        spinBox_val_3 = new QSpinBox(groupBox_midi_3);
        spinBox_val_3->setObjectName(QStringLiteral("spinBox_val_3"));
        spinBox_val_3->setMinimumSize(QSize(100, 0));
        spinBox_val_3->setAlignment(Qt::AlignCenter);
        spinBox_val_3->setMinimum(0);
        spinBox_val_3->setMaximum(127);

        gridLayout_6->addWidget(spinBox_val_3, 1, 2, 1, 1);

        spinBox_channel_3 = new QSpinBox(groupBox_midi_3);
        spinBox_channel_3->setObjectName(QStringLiteral("spinBox_channel_3"));
        spinBox_channel_3->setMinimumSize(QSize(100, 0));
        spinBox_channel_3->setAlignment(Qt::AlignCenter);
        spinBox_channel_3->setMinimum(1);
        spinBox_channel_3->setMaximum(16);

        gridLayout_6->addWidget(spinBox_channel_3, 1, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_midi_3, 3, 0, 1, 4);

        groupBox_midi_2 = new QGroupBox(centralWidget);
        groupBox_midi_2->setObjectName(QStringLiteral("groupBox_midi_2"));
        gridLayout_5 = new QGridLayout(groupBox_midi_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        spinBox_val_2 = new QSpinBox(groupBox_midi_2);
        spinBox_val_2->setObjectName(QStringLiteral("spinBox_val_2"));
        spinBox_val_2->setMinimumSize(QSize(100, 0));
        spinBox_val_2->setAlignment(Qt::AlignCenter);
        spinBox_val_2->setMinimum(0);
        spinBox_val_2->setMaximum(127);

        gridLayout_5->addWidget(spinBox_val_2, 1, 2, 1, 1);

        label_type_2 = new QLabel(groupBox_midi_2);
        label_type_2->setObjectName(QStringLiteral("label_type_2"));

        gridLayout_5->addWidget(label_type_2, 0, 0, 1, 1);

        label_num_2 = new QLabel(groupBox_midi_2);
        label_num_2->setObjectName(QStringLiteral("label_num_2"));

        gridLayout_5->addWidget(label_num_2, 0, 1, 1, 1);

        label_val_2 = new QLabel(groupBox_midi_2);
        label_val_2->setObjectName(QStringLiteral("label_val_2"));

        gridLayout_5->addWidget(label_val_2, 0, 2, 1, 1);

        label_channel_2 = new QLabel(groupBox_midi_2);
        label_channel_2->setObjectName(QStringLiteral("label_channel_2"));

        gridLayout_5->addWidget(label_channel_2, 0, 3, 1, 1);

        comboBox_type_2 = new QComboBox(groupBox_midi_2);
        comboBox_type_2->setObjectName(QStringLiteral("comboBox_type_2"));
        comboBox_type_2->setMinimumSize(QSize(200, 0));

        gridLayout_5->addWidget(comboBox_type_2, 1, 0, 1, 1);

        spinBox_num_2 = new QSpinBox(groupBox_midi_2);
        spinBox_num_2->setObjectName(QStringLiteral("spinBox_num_2"));
        spinBox_num_2->setMinimumSize(QSize(100, 0));
        spinBox_num_2->setAlignment(Qt::AlignCenter);
        spinBox_num_2->setMinimum(0);
        spinBox_num_2->setMaximum(127);

        gridLayout_5->addWidget(spinBox_num_2, 1, 1, 1, 1);

        spinBox_channel_2 = new QSpinBox(groupBox_midi_2);
        spinBox_channel_2->setObjectName(QStringLiteral("spinBox_channel_2"));
        spinBox_channel_2->setMinimumSize(QSize(100, 0));
        spinBox_channel_2->setAlignment(Qt::AlignCenter);
        spinBox_channel_2->setMinimum(1);
        spinBox_channel_2->setMaximum(16);

        gridLayout_5->addWidget(spinBox_channel_2, 1, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_midi_2, 2, 0, 1, 4);

        groupBox_midi_4 = new QGroupBox(centralWidget);
        groupBox_midi_4->setObjectName(QStringLiteral("groupBox_midi_4"));
        gridLayout_7 = new QGridLayout(groupBox_midi_4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        comboBox_type_4 = new QComboBox(groupBox_midi_4);
        comboBox_type_4->setObjectName(QStringLiteral("comboBox_type_4"));
        comboBox_type_4->setMinimumSize(QSize(200, 0));

        gridLayout_7->addWidget(comboBox_type_4, 1, 0, 1, 1);

        spinBox_num_4 = new QSpinBox(groupBox_midi_4);
        spinBox_num_4->setObjectName(QStringLiteral("spinBox_num_4"));
        spinBox_num_4->setMinimumSize(QSize(100, 0));
        spinBox_num_4->setAlignment(Qt::AlignCenter);
        spinBox_num_4->setMinimum(0);
        spinBox_num_4->setMaximum(127);

        gridLayout_7->addWidget(spinBox_num_4, 1, 1, 1, 1);

        spinBox_val_4 = new QSpinBox(groupBox_midi_4);
        spinBox_val_4->setObjectName(QStringLiteral("spinBox_val_4"));
        spinBox_val_4->setMinimumSize(QSize(100, 0));
        spinBox_val_4->setAlignment(Qt::AlignCenter);
        spinBox_val_4->setMinimum(0);
        spinBox_val_4->setMaximum(127);

        gridLayout_7->addWidget(spinBox_val_4, 1, 2, 1, 1);

        spinBox_channel_4 = new QSpinBox(groupBox_midi_4);
        spinBox_channel_4->setObjectName(QStringLiteral("spinBox_channel_4"));
        spinBox_channel_4->setMinimumSize(QSize(100, 0));
        spinBox_channel_4->setAlignment(Qt::AlignCenter);
        spinBox_channel_4->setMinimum(1);
        spinBox_channel_4->setMaximum(16);

        gridLayout_7->addWidget(spinBox_channel_4, 1, 3, 1, 1);

        label_num_4 = new QLabel(groupBox_midi_4);
        label_num_4->setObjectName(QStringLiteral("label_num_4"));

        gridLayout_7->addWidget(label_num_4, 0, 1, 1, 1);

        label_val_4 = new QLabel(groupBox_midi_4);
        label_val_4->setObjectName(QStringLiteral("label_val_4"));

        gridLayout_7->addWidget(label_val_4, 0, 2, 1, 1);

        label_channel_4 = new QLabel(groupBox_midi_4);
        label_channel_4->setObjectName(QStringLiteral("label_channel_4"));

        gridLayout_7->addWidget(label_channel_4, 0, 3, 1, 1);

        label_type_4 = new QLabel(groupBox_midi_4);
        label_type_4->setObjectName(QStringLiteral("label_type_4"));

        gridLayout_7->addWidget(label_type_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_midi_4, 4, 0, 1, 4);

        groupBox_midi_5 = new QGroupBox(centralWidget);
        groupBox_midi_5->setObjectName(QStringLiteral("groupBox_midi_5"));
        gridLayout_8 = new QGridLayout(groupBox_midi_5);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_type_5 = new QLabel(groupBox_midi_5);
        label_type_5->setObjectName(QStringLiteral("label_type_5"));

        gridLayout_8->addWidget(label_type_5, 0, 0, 1, 1);

        label_num_5 = new QLabel(groupBox_midi_5);
        label_num_5->setObjectName(QStringLiteral("label_num_5"));

        gridLayout_8->addWidget(label_num_5, 0, 1, 1, 1);

        label_val_5 = new QLabel(groupBox_midi_5);
        label_val_5->setObjectName(QStringLiteral("label_val_5"));

        gridLayout_8->addWidget(label_val_5, 0, 2, 1, 1);

        label_channel_5 = new QLabel(groupBox_midi_5);
        label_channel_5->setObjectName(QStringLiteral("label_channel_5"));

        gridLayout_8->addWidget(label_channel_5, 0, 3, 1, 1);

        comboBox_type_5 = new QComboBox(groupBox_midi_5);
        comboBox_type_5->setObjectName(QStringLiteral("comboBox_type_5"));
        comboBox_type_5->setMinimumSize(QSize(200, 0));

        gridLayout_8->addWidget(comboBox_type_5, 1, 0, 1, 1);

        spinBox_num_5 = new QSpinBox(groupBox_midi_5);
        spinBox_num_5->setObjectName(QStringLiteral("spinBox_num_5"));
        spinBox_num_5->setMinimumSize(QSize(100, 0));
        spinBox_num_5->setAlignment(Qt::AlignCenter);
        spinBox_num_5->setMinimum(0);
        spinBox_num_5->setMaximum(127);

        gridLayout_8->addWidget(spinBox_num_5, 1, 1, 1, 1);

        spinBox_val_5 = new QSpinBox(groupBox_midi_5);
        spinBox_val_5->setObjectName(QStringLiteral("spinBox_val_5"));
        spinBox_val_5->setMinimumSize(QSize(100, 0));
        spinBox_val_5->setAlignment(Qt::AlignCenter);
        spinBox_val_5->setMinimum(0);
        spinBox_val_5->setMaximum(127);

        gridLayout_8->addWidget(spinBox_val_5, 1, 2, 1, 1);

        spinBox_channel_5 = new QSpinBox(groupBox_midi_5);
        spinBox_channel_5->setObjectName(QStringLiteral("spinBox_channel_5"));
        spinBox_channel_5->setMinimumSize(QSize(100, 0));
        spinBox_channel_5->setAlignment(Qt::AlignCenter);
        spinBox_channel_5->setMinimum(1);
        spinBox_channel_5->setMaximum(16);

        gridLayout_8->addWidget(spinBox_channel_5, 1, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_midi_5, 5, 0, 1, 4);

        groupBox_presetDetails = new QGroupBox(centralWidget);
        groupBox_presetDetails->setObjectName(QStringLiteral("groupBox_presetDetails"));
        gridLayout_2 = new QGridLayout(groupBox_presetDetails);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_bank = new QLabel(groupBox_presetDetails);
        label_bank->setObjectName(QStringLiteral("label_bank"));

        gridLayout_2->addWidget(label_bank, 0, 0, 1, 1);

        label_switch = new QLabel(groupBox_presetDetails);
        label_switch->setObjectName(QStringLiteral("label_switch"));

        gridLayout_2->addWidget(label_switch, 0, 1, 1, 1);

        label_presetName = new QLabel(groupBox_presetDetails);
        label_presetName->setObjectName(QStringLiteral("label_presetName"));

        gridLayout_2->addWidget(label_presetName, 0, 3, 1, 1);

        comboBox_bank = new QComboBox(groupBox_presetDetails);
        comboBox_bank->setObjectName(QStringLiteral("comboBox_bank"));
        comboBox_bank->setMinimumSize(QSize(200, 0));

        gridLayout_2->addWidget(comboBox_bank, 1, 0, 1, 1);

        comboBox_switch = new QComboBox(groupBox_presetDetails);
        comboBox_switch->setObjectName(QStringLiteral("comboBox_switch"));
        comboBox_switch->setMinimumSize(QSize(200, 0));

        gridLayout_2->addWidget(comboBox_switch, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        lineEdit_shortName = new QLineEdit(groupBox_presetDetails);
        lineEdit_shortName->setObjectName(QStringLiteral("lineEdit_shortName"));
        lineEdit_shortName->setMinimumSize(QSize(100, 0));
        lineEdit_shortName->setMaxLength(4);
        lineEdit_shortName->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_shortName, 1, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_presetDetails, 0, 0, 1, 4);

        textBrowser_output = new QTextBrowser(centralWidget);
        textBrowser_output->setObjectName(QStringLiteral("textBrowser_output"));

        gridLayout_3->addWidget(textBrowser_output, 7, 0, 1, 4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 578, 22));
        menuDevice = new QMenu(menuBar);
        menuDevice->setObjectName(QStringLiteral("menuDevice"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_channel->setBuddy(spinBox_channel);
        label_val->setBuddy(spinBox_val);
        label_type->setBuddy(comboBox_type);
        label_num->setBuddy(spinBox_num);
        label_num_3->setBuddy(spinBox_num_3);
        label_channel_3->setBuddy(spinBox_channel_3);
        label_val_3->setBuddy(spinBox_val_3);
        label_type_3->setBuddy(comboBox_type_3);
        label_type_2->setBuddy(comboBox_type_2);
        label_num_2->setBuddy(spinBox_num_2);
        label_val_2->setBuddy(spinBox_val_2);
        label_channel_2->setBuddy(spinBox_channel_2);
        label_num_4->setBuddy(spinBox_num_4);
        label_val_4->setBuddy(spinBox_val_4);
        label_channel_4->setBuddy(spinBox_channel_4);
        label_type_4->setBuddy(comboBox_type_4);
        label_type_5->setBuddy(comboBox_type_5);
        label_num_5->setBuddy(spinBox_num_5);
        label_val_5->setBuddy(spinBox_val_5);
        label_channel_5->setBuddy(spinBox_channel_5);
        label_bank->setBuddy(comboBox_bank);
        label_switch->setBuddy(comboBox_switch);
        label_presetName->setBuddy(lineEdit_shortName);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboBox_bank, comboBox_switch);
        QWidget::setTabOrder(comboBox_switch, lineEdit_shortName);
        QWidget::setTabOrder(lineEdit_shortName, comboBox_type);
        QWidget::setTabOrder(comboBox_type, spinBox_num);
        QWidget::setTabOrder(spinBox_num, spinBox_val);
        QWidget::setTabOrder(spinBox_val, spinBox_channel);
        QWidget::setTabOrder(spinBox_channel, comboBox_type_2);
        QWidget::setTabOrder(comboBox_type_2, spinBox_num_2);
        QWidget::setTabOrder(spinBox_num_2, spinBox_val_2);
        QWidget::setTabOrder(spinBox_val_2, spinBox_channel_2);
        QWidget::setTabOrder(spinBox_channel_2, comboBox_type_3);
        QWidget::setTabOrder(comboBox_type_3, spinBox_num_3);
        QWidget::setTabOrder(spinBox_num_3, spinBox_val_3);
        QWidget::setTabOrder(spinBox_val_3, spinBox_channel_3);
        QWidget::setTabOrder(spinBox_channel_3, comboBox_type_4);
        QWidget::setTabOrder(comboBox_type_4, spinBox_num_4);
        QWidget::setTabOrder(spinBox_num_4, spinBox_val_4);
        QWidget::setTabOrder(spinBox_val_4, spinBox_channel_4);
        QWidget::setTabOrder(spinBox_channel_4, comboBox_type_5);
        QWidget::setTabOrder(comboBox_type_5, spinBox_num_5);
        QWidget::setTabOrder(spinBox_num_5, spinBox_val_5);
        QWidget::setTabOrder(spinBox_val_5, spinBox_channel_5);
        QWidget::setTabOrder(spinBox_channel_5, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_reset);

        menuBar->addAction(menuDevice->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuDevice->addAction(actionConnect);
        menuDevice->addAction(actionClose);
        menuDevice->addSeparator();
        menuEdit->addAction(actionExpression_Input);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MorningstarFX Midi Editor v2.03", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionTest_Mode->setText(QApplication::translate("MainWindow", "Test Mode", 0));
        actionCheck_for_updates->setText(QApplication::translate("MainWindow", "Check for updates", 0));
        actionExpression_Input->setText(QApplication::translate("MainWindow", "Expression Input", 0));
        pushButton_save->setText(QApplication::translate("MainWindow", "Save", 0));
        pushButton_reset->setText(QApplication::translate("MainWindow", "Reset", 0));
        groupBox_midi->setTitle(QApplication::translate("MainWindow", "Midi Message 1", 0));
        label_channel->setText(QApplication::translate("MainWindow", "Channel", 0));
        label_val->setText(QApplication::translate("MainWindow", "Value 1 / 2", 0));
        label_type->setText(QApplication::translate("MainWindow", "Midi Type", 0));
        label_num->setText(QApplication::translate("MainWindow", "Number", 0));
        groupBox_midi_3->setTitle(QApplication::translate("MainWindow", "Midi Message 3", 0));
        label_num_3->setText(QApplication::translate("MainWindow", "Number", 0));
        label_channel_3->setText(QApplication::translate("MainWindow", "Channel", 0));
        label_val_3->setText(QApplication::translate("MainWindow", "Value", 0));
        label_type_3->setText(QApplication::translate("MainWindow", "Midi Type", 0));
        groupBox_midi_2->setTitle(QApplication::translate("MainWindow", "Midi Message 2", 0));
        label_type_2->setText(QApplication::translate("MainWindow", "Midi Type", 0));
        label_num_2->setText(QApplication::translate("MainWindow", "Number", 0));
        label_val_2->setText(QApplication::translate("MainWindow", "Value", 0));
        label_channel_2->setText(QApplication::translate("MainWindow", "Channel", 0));
        groupBox_midi_4->setTitle(QApplication::translate("MainWindow", "Midi Message 4", 0));
        label_num_4->setText(QApplication::translate("MainWindow", "Number", 0));
        label_val_4->setText(QApplication::translate("MainWindow", "Value", 0));
        label_channel_4->setText(QApplication::translate("MainWindow", "Channel", 0));
        label_type_4->setText(QApplication::translate("MainWindow", "Midi Type", 0));
        groupBox_midi_5->setTitle(QApplication::translate("MainWindow", "Midi Message 5", 0));
        label_type_5->setText(QApplication::translate("MainWindow", "Midi Type", 0));
        label_num_5->setText(QApplication::translate("MainWindow", "Number", 0));
        label_val_5->setText(QApplication::translate("MainWindow", "Value", 0));
        label_channel_5->setText(QApplication::translate("MainWindow", "Channel", 0));
        groupBox_presetDetails->setTitle(QApplication::translate("MainWindow", "Preset Details", 0));
        label_bank->setText(QApplication::translate("MainWindow", "Bank", 0));
        label_switch->setText(QApplication::translate("MainWindow", "Switch", 0));
        label_presetName->setText(QApplication::translate("MainWindow", "Preset Name", 0));
        menuDevice->setTitle(QApplication::translate("MainWindow", "Device", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Aug 4 23:15:45 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <palnetwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    palnetWidget *widget_2;
    QWidget *widget;
    QLabel *label;
    QDateEdit *dateEdit;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(803, 476);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new palnetWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(widget_2);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 80));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 31, 16));
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(50, 10, 91, 22));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 10, 75, 23));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 111, 20));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 50, 121, 22));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(680, 10, 91, 23));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 10, 61, 16));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(280, 50, 54, 12));
        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(350, 10, 131, 22));
        comboBox_3 = new QComboBox(widget);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(350, 50, 131, 22));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(680, 50, 91, 23));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 10, 151, 23));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(500, 50, 151, 23));

        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 803, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Set", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\246\201\350\247\202\345\257\237\347\232\204\350\241\214\346\230\237\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mercury", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Venus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Earth", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mars", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Jupiter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Saturn", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Uranus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Neptune", 0, QApplication::UnicodeUTF8)
        );
        pushButton_4->setText(QApplication::translate("MainWindow", "Hot Key List", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Look From:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Look To :", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Default", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Center", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Distance 9", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Default( the Sun)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Moon", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mercury", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Venus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Earth", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mars", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Jupiter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Saturn", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Uranus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Neptune", 0, QApplication::UnicodeUTF8)
        );
        pushButton->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Planetary Alignments", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

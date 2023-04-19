/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pickPosButton;
    QLineEdit *startNftId;
    QPlainTextEdit *initalPts;
    QLineEdit *spdSync;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(641, 354);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 40, 81, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 291, 301));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        pickPosButton = new QPushButton(centralWidget);
        pickPosButton->setObjectName(QStringLiteral("pickPosButton"));
        pickPosButton->setGeometry(QRect(430, 10, 201, 31));
        startNftId = new QLineEdit(centralWidget);
        startNftId->setObjectName(QStringLiteral("startNftId"));
        startNftId->setGeometry(QRect(510, 100, 113, 20));
        initalPts = new QPlainTextEdit(centralWidget);
        initalPts->setObjectName(QStringLiteral("initalPts"));
        initalPts->setGeometry(QRect(430, 130, 191, 191));
        spdSync = new QLineEdit(centralWidget);
        spdSync->setObjectName(QStringLiteral("spdSync"));
        spdSync->setGeometry(QRect(532, 70, 91, 20));
        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        pushButton->raise();
        pickPosButton->raise();
        startNftId->raise();
        initalPts->raise();
        spdSync->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Start Bot", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>1. Open URL / id - wait 5 secs</p><p>2. check pixel</p><p>- for sellinng , CTRL+W</p><p>- else CTRL+W</p><p>3. Open URL / id / sell - wait 5 secs</p><p>4. INPUT 0.0041</p><p>5. CLICK Duration, Date Range, 6 months, CLICK outside, </p><p>6. Click complete Listing - wait 5 secs</p><p>7. Click Scroll down on Metamask</p><p>8. Click Sign on Metamask - wait 2 secs</p><p>9. Close Browser</p></body></html>", 0));
        pickPosButton->setText(QApplication::translate("MainWindow", "Pick Position for Checking selling", 0));
        initalPts->setPlainText(QApplication::translate("MainWindow", "820,379\n"
"1033,162\n"
"187,331\n"
"274,399\n"
"216,529\n"
"61,365\n"
"207, 478\n"
"1553,519\n"
"1465,580", 0));
        spdSync->setText(QApplication::translate("MainWindow", "1.0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

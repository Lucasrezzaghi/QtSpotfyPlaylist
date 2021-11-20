/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *addButton;
    QPushButton *prevButton;
    QPushButton *playButton;
    QPushButton *stopButton;
    QPushButton *nextButton;
    QPushButton *grantButton;
    QPushButton *removeButton;
    QListWidget *listWidget;
    QListWidget *lstPlaylist;
    QTextEdit *txtSearch;
    QPushButton *searchButton;
    QPushButton *shuffleButton;
    QPushButton *saveButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 111, 16));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(20, 460, 71, 21));
        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setGeometry(QRect(220, 460, 51, 21));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(290, 460, 41, 21));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(390, 460, 41, 21));
        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(450, 460, 51, 21));
        grantButton = new QPushButton(centralwidget);
        grantButton->setObjectName(QString::fromUtf8("grantButton"));
        grantButton->setGeometry(QRect(530, 10, 91, 41));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(550, 460, 71, 21));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 60, 191, 391));
        lstPlaylist = new QListWidget(centralwidget);
        lstPlaylist->setObjectName(QString::fromUtf8("lstPlaylist"));
        lstPlaylist->setGeometry(QRect(220, 60, 401, 391));
        txtSearch = new QTextEdit(centralwidget);
        txtSearch->setObjectName(QString::fromUtf8("txtSearch"));
        txtSearch->setGeometry(QRect(20, 30, 131, 21));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(150, 30, 61, 21));
        shuffleButton = new QPushButton(centralwidget);
        shuffleButton->setObjectName(QString::fromUtf8("shuffleButton"));
        shuffleButton->setGeometry(QRect(330, 460, 61, 21));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(430, 10, 91, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Procurar musica", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Adicionar", nullptr));
        prevButton->setText(QCoreApplication::translate("MainWindow", "Anterior", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Tocar", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Parar", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Proxima", nullptr));
        grantButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Remover", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        shuffleButton->setText(QCoreApplication::translate("MainWindow", "Shuffle", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Salvar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "api.h"
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Api *api;
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QMessageBox msgBox;

private:
    Ui::MainWindow *ui;
    QVector<QString> checkList;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_grantButton_clicked();

    void on_addButton_clicked();

    void on_lstPlaylist_itemClicked();

    void on_removeButton_clicked();

    void on_playButton_clicked();

    void stopPlayer();

    void on_stopButton_clicked();

    void on_nextButton_clicked();

    void on_prevButton_clicked();

    void on_searchButton_clicked();

    void on_shuffleButton_clicked();

    void showMessage(QString);

    void on_saveButton_clicked();

    void loadPlaylist();


};

#endif // MAINWINDOW_H

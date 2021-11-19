#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->api = new Api();
    loadPlaylist();
    api->connectToSpotify();
    this->player = new QMediaPlayer(this);
    this->playlist = new QMediaPlaylist(this->player);

}

MainWindow::~MainWindow()
{
    delete this->ui;
    delete this->api;
    delete this->player;
    delete this->playlist;
}

void MainWindow::on_grantButton_clicked(){
    this->api->grant();
}


void MainWindow::on_addButton_clicked(){
    if (ui->listWidget->currentRow() != -1){
        QString element = api->getStringFromSearchMap(ui->listWidget->currentRow());
        if (api->addToPlaylist(element)){
            ui->lstPlaylist->addItem(ui->listWidget->currentItem()->clone());
        }
    }
}

void MainWindow::on_lstPlaylist_itemClicked(){
    ui->removeButton->setEnabled(true);
}

void MainWindow::on_removeButton_clicked(){
    if (ui->lstPlaylist->currentRow() != -1){
        if (api->removeFromPlaylist(ui->lstPlaylist->currentRow())){
            if (api->getPlaylistSize() == 0){
                    ui->removeButton->setEnabled(false);
            }
            this->playlist->removeMedia(ui->lstPlaylist->currentRow());
            delete ui->lstPlaylist->takeItem(ui->lstPlaylist->row(ui->lstPlaylist->currentItem()));
        }
        checkList.remove(ui->lstPlaylist->currentRow()+1);
    }
    else{
        this->showMessage("Nenhuma musica selecionada para ser removida");
    }
}


void MainWindow::stopPlayer(){
    this->player->stop();
}


void MainWindow::on_playButton_clicked(){
    //evitando bug de adicionar lista vazia
    if(ui->lstPlaylist->currentRow() != -1){
        //Adicionando as musicas em uma playlist para evitar duplicatas.
        for(int i = 0; i < ui->lstPlaylist->count(); ++i){
            if(!checkList.contains(api->getPlaylistItem(i))){
                playlist->addMedia(QUrl(api->getPlaylistItem(i)));
            }
        }

        for(int i = 0; i < ui->lstPlaylist->count(); ++i){
            checkList.push_back(api->getPlaylistItem(i));
        }
        this->player->setPlaylist(playlist);
        this->player->play();
    }
    else{
        this->showMessage("selecionar musica na playlist");
    }
}



void MainWindow::on_stopButton_clicked(){
    this->player->stop();
}


void MainWindow::on_nextButton_clicked(){
    if(this->playlist->nextIndex() >= 0)
        this->player->playlist()->next();
    else{
        this->showMessage("Nenhuma musica Posterior");
    }
}


void MainWindow::on_prevButton_clicked(){
    if(this->playlist->previousIndex() >= 0)
        this->player->playlist()->previous();
    else{
        this->showMessage("Nenhuma musica anterior");
    }
}

void MainWindow::on_searchButton_clicked(){
    if(api->isLogged() == true){
        ui->listWidget->clear();
        api->search(ui->txtSearch->toPlainText(), ui->listWidget);
    }
    else{
        this->showMessage("Por favor, primeiro faca o login");
    }
}


void MainWindow::on_shuffleButton_clicked(){
    //evitando bug de adicionar lista vazia.
    if(ui->lstPlaylist->currentRow() != -1){
        //Adicionando as musicas em uma playlist temporaria para evitar duplicatas.
        for(int i = 0; i < ui->lstPlaylist->count(); ++i){
            if(!checkList.contains(api->getPlaylistItem(i))){
                playlist->addMedia(QUrl(api->getPlaylistItem(i)));
            }
        }

        for(int i = 0; i < ui->lstPlaylist->count(); ++i){
            checkList.push_back(api->getPlaylistItem(i));
        }
    //randomizando playlist.
        playlist->shuffle();
        this->player->setPlaylist(playlist);
        this->player->play();
    }
    else{
        this->showMessage("selecionar musica na playlist");
    }
}

void MainWindow::showMessage(QString message){
    this->msgBox.setText(message);
    this->msgBox.exec();
    return;
}

void MainWindow::on_saveButton_clicked(){
    QVector<QString> musicList;
    for (int i=0; i<api->getPlaylistSize(); ++i){
        musicList.push_back(ui->lstPlaylist->item(i)->text());
    }
   api->savePlaylist(musicList);
   this->showMessage("Playlist salva!");
}

void MainWindow::loadPlaylist(){
    QVector<QString> playlist = api->loadPlaylist();
    for (int i=0; i<playlist.size(); ++i){
        ui->lstPlaylist->addItem(playlist[i]);
    }
}

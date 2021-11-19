#include "api.h"
#include <QDebug>
#define PLAYLIST_FILE "user_playlist.txt"

Api::Api()
{

}

Api::~Api(){
}


void Api::setupConnection(){
    auto replyHandler = new QOAuthHttpServerReplyHandler(8080, this);
    spotifyApi.setReplyHandler(replyHandler);
    spotifyApi.setAuthorizationUrl(QUrl("https://accounts.spotify.com/authorize"));
    spotifyApi.setAccessTokenUrl(QUrl("https://accounts.spotify.com/api/token"));
    spotifyApi.setClientIdentifier(clientId);
    spotifyApi.setClientIdentifierSharedKey(clientSecret);
    spotifyApi.setScope("user-read-private user-top-read playlist-read-private playlist-modify-public playlist-modify-private");
}

void Api::granted(){
    this->showMessage("Login feito!");
    isGranted = true;
}

bool Api::isLogged(){
    if(isGranted == true)
        return true;
    else
        return false;
}

int Api::connectToSpotify(){
    try
    {
        setupConnection();
        connect(&spotifyApi, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);
        connect(&spotifyApi, &QOAuth2AuthorizationCodeFlow::granted, this, &Api::granted);
        return 0;

    }
    catch (const int error){
        return error;
    }
}

void Api::grant(){
    this->spotifyApi.grant();
}

QString Api::getStringFromSearchMap(int index){
    return searchMap[index];
}


int Api::getPlaylistSize(){
    return playListUrls.size();
}


QString Api::getPlaylistItem(int index){
    return playListUrls[index];
}


void Api::search(QString searchString, QListWidget * lstSearchResults){
    QUrlQuery url ("https://api.spotify.com/v1/search?type=track&limit=20&q=" + searchString);

    searchMap.clear();

    auto reply = spotifyApi.get(url.toString());

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() != QNetworkReply::NoError){
            this->showMessage(reply->errorString());
            return;
        }
        const auto data = reply->readAll();

        const auto document = QJsonDocument::fromJson(data);
        const auto jsonObj = document.object();

        QJsonObject finalObject = jsonObj["tracks"].toObject();

        QJsonArray jsonArray = finalObject["items"].toArray();
        int cont = 0;
        foreach (const QJsonValue & value, jsonArray){
            QJsonObject obj = value.toObject();
            if (obj["preview_url"].toString() != ""){
                lstSearchResults->addItem(obj["name"].toString());
                searchMap.insert(cont++, obj["preview_url"].toString());
            }
        }

        reply->deleteLater();
    });
}

bool Api::removeFromPlaylist(int index){
    if (index >= playListUrls.size() || index < 0)
        return false;

    playListUrls.removeAt(index);
    return true;
}

bool Api::addToPlaylist(QString element){
    if (!playListUrls.contains(element)){
        playListUrls.push_back(element);
        return true;
    }
    return false;
}

void Api::showMessage(QString message){
    this->msgBox.setText(message);
    this->msgBox.exec();
    return;
}

void Api::savePlaylist(QVector<QString> playlist){
    QFile::remove(PLAYLIST_FILE);
    QSettings settings(PLAYLIST_FILE, QSettings::IniFormat);
    settings.beginGroup("Musicas");
    int playlistSize = playListUrls.size();
    for (int i=0; i < playlistSize; ++i)
    {
        settings.setValue(playlist[i], playListUrls[i]);
    }
}

QVector<QString> Api::loadPlaylist(){
    QSettings settings(PLAYLIST_FILE, QSettings::IniFormat);
    settings.beginGroup("Musicas");
    QStringList keys = settings.allKeys();
    QVector<QString> songNames;
    for (int i=0; i<keys.size(); ++i)
    {
        playListUrls.push_back(settings.value(keys[i]).toString());
        songNames.push_back(keys[i]);
    }
    return songNames;
}



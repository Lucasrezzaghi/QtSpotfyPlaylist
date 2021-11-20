#include <QtTest>
#include <QCoreApplication>
#include <../api.h>

// add necessary includes here

class testsApi : public QObject
{
    Q_OBJECT
    Api *api;

public:
    testsApi();
    ~testsApi();


private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_getPlaylistSize();
    void test_getPlaylistItem();
    void test_addToPlaylist();
    void test_removeFromPlaylist();
    void test_removeFalse();
    void test_searchMap();
    void test_connect();

};

testsApi::testsApi()
{
    this->api = new Api();

}

testsApi::~testsApi()
{
    delete this->api;
}

void testsApi::initTestCase()
{

}

void testsApi::cleanupTestCase()
{

}


void testsApi::test_getPlaylistSize()
{
    QCOMPARE(this->api->getPlaylistSize(), 0);
    QCOMPARE(this->api->addToPlaylist("teste"), true);
    QCOMPARE(this->api->getPlaylistSize(), 1);
    QCOMPARE(this->api->addToPlaylist("teste2"), true);
    QCOMPARE(this->api->getPlaylistSize(), 2);
}

void testsApi::test_getPlaylistItem()
{
    QCOMPARE(this->api->getPlaylistItem(0), "teste");
    QCOMPARE(this->api->getPlaylistItem(1), "teste2");
}

void testsApi::test_addToPlaylist(){
    QCOMPARE(this->api->addToPlaylist("teste3"), true);
    QCOMPARE(this->api->addToPlaylist("teste4"), true);
}

void testsApi::test_removeFromPlaylist()
{
    QCOMPARE(this->api->getPlaylistSize(), 4);
    QCOMPARE(this->api->removeFromPlaylist(0), true);
    QCOMPARE(this->api->getPlaylistSize(), 3);
    QCOMPARE(this->api->removeFromPlaylist(0), true);
    QCOMPARE(this->api->getPlaylistItem(0), "teste3");
    QCOMPARE(this->api->getPlaylistSize(), 2);
}

void testsApi::test_removeFalse(){
    QCOMPARE(this->api->removeFromPlaylist(3), false);
    QCOMPARE(this->api->removeFromPlaylist(2), false);

}

void testsApi::test_searchMap(){
    QCOMPARE(this->api->getStringFromSearchMap(0), "");
}

void testsApi::test_connect(){
    QCOMPARE(this->api->connectToSpotify(clientId, clientSecret), 0);
}


QTEST_MAIN(testsApi)

#include "tst_testsapi.moc"

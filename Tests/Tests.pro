QT += testlib
QT += core gui

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testsapi.cpp

INCLUDEPATH += ../

VPATH += ../
SOURCES += api.cpp
HEADERS += api.h


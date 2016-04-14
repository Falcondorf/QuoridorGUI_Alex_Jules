#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T16:57:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Quoridor
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    mainView.cpp \
    board.cpp \
    Frame.cpp \
    game.cpp \
    player.cpp \
    Side.cpp \
    subject.cpp \
    test.cpp

HEADERS  += mainwindow.h \
    board.h \
    Frame.h \
    game.h \
    keyboard.hpp \
    observer.h \
    player.h \
    QuoridorConsole.h \
    Side.h \
    stringConvert.hpp \
    subject.h \
    Test.h

FORMS    += mainwindow.ui
CONFIG += console
CONFIG -= app_bundle
#CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11 -pedantic-errors

DISTFILES +=

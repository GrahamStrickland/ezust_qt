#-------------------------------------------------
#
# Project created by QtCreator 2022-08-12T13:28:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 15puzzle
TEMPLATE = app


SOURCES += main.cpp\
    puzzlewindow.cpp \
    puzzlemodel.cpp \
    puzzleview.cpp \
    tile.cpp

HEADERS  += \
    puzzlewindow.h \
    puzzlemodel.h \
    puzzleview.h \
    tile.h

FORMS    += mainwindow.ui

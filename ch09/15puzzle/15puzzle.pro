#-------------------------------------------------
#
# Project created by QtCreator 2022-07-21T13:47:20
#
#-------------------------------------------------

QT       += core widgets

QT       -= gui

TARGET = q1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# Input
HEADERS += puzzlemodel.h puzzleview.h puzzlewindow.h tile.h ui_mainwindow.h
SOURCES += main.cpp puzzlemodel.cpp puzzleview.cpp puzzlewindow.cpp tile.cpp
CONFIG += qt

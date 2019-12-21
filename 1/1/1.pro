#-------------------------------------------------
#
# Project created by QtCreator 2019-10-31T19:30:41
#
#-------------------------------------------------


QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        add1.cpp \
        building.cpp \
        data.cpp \
        easycity2.cpp \
        fib.cpp \
        findfactorial.cpp \
        floor.cpp \
        getsignature.cpp \
        judge.cpp \
        judgewindow.cpp \
        largefactorial.cpp \
        largestroot.cpp \
        longestpair.cpp \
        longestshorestdisstance.cpp \
        main.cpp \
        mainwindow.cpp \
        minesweeper.cpp \
        mydatabase.cpp \
        mymath.cpp \
        problemset.cpp \
        shortestdistance.cpp \
        shygame.cpp \
        people.cpp \
        prime.cpp \
        scheduler.cpp

HEADERS += \
        add1.h \
        building.h \
        data.h \
        easycity2.h \
        fib.h \
        findfactorial.h \
        floor.h \
        getsignature.h \
        judge.h \
        judgewindow.h \
        largefactorial.h \
        largestroot.h \
        longestpair.h \
        longestshorestdisstance.h \
        mainwindow.h \
        minesweeper.h \
        shortestdistance.h \
        mydatabase.h \
        mymath.h \
        people.h \
        prime.h \
        problemset.h \
        scheduler.h \
        shygame.h

FORMS += \
        judgewindow.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

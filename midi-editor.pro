#-------------------------------------------------
#
# Project created by QtCreator 2015-10-17T11:08:51
#
#-------------------------------------------------

QT       += core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_MAC_SDK = macosx10.11

TARGET = midi-editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    midi_base.cpp \
    midi_structure.cpp \
    midi_controller.cpp \
    conn_mgr.cpp \
    debug_log.cpp \
    expdialogwidget.cpp

HEADERS  += mainwindow.h \
    midi_base.h \
    midi_structure.h \
    midi_controller.h \
    conn_mgr.h \
    debug_log.h \
    expdialogwidget.h

FORMS    += mainwindow.ui \
    Expression.ui

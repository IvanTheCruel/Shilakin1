TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    pipe.cpp \
    station.cpp

HEADERS += \
    pipe.h \
    station.h \
    check_idiot.h

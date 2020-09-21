TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    pipe.cpp \
    station.cpp \
    check_idiot.cpp

HEADERS += \
    pipe.h \
    station.h \
    check_idiot.h

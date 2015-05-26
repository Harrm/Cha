#-------------------------------------------------
#
# Project created by QtCreator 2015-01-25T15:16:42
#
#-------------------------------------------------

QT += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CharacterBuider
TEMPLATE = app

QMAKE_CXXFLAGS = -std=c++1y
CONFIG += c++14

SOURCES += main.cpp\
    character_builder.cpp \
    character/character.cpp \
    character/character_reader.cpp \
    interface/name_screen.cpp \
    interface/ability_screen.cpp \
    interface/ability_screen_line.cpp \
    interface/skill_screen.cpp \
    character/ability.cpp

HEADERS  += character_builder.h \
    character/character.h \
    character/character_reader.h \
    interface/name_screen.h \
    interface/ability_screen.h \
    interface/ability_screen_line.h \
    interface/skill_screen.h \
    character/ability.h

DISTFILES += \
    bin/Debug/data/default_character.xml

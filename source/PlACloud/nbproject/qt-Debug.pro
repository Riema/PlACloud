# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = PlACloud
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui
SOURCES += src/main.cpp src/PlaCloud/configurator.cpp src/PlaCloud/kConfigOwnCloud.cpp src/PlaCloud/fileOwnCloud.cpp src/PlaCloud/application.cpp src/gui/primeWindow.cpp
HEADERS += src/PlaCloud/configurator.h src/commons.h src/PlaCloud/kConfigOwnCloud.h src/gui/primeWindow.h src/PlaCloud/fileOwnCloud.h src/PlaCloud/application.h
FORMS += src/gui/primeWindow.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += -lkdecore -lkio  
"CONFIG += console"

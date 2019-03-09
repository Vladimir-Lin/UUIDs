# Author : Foxman A.K.A. Vladimir Lin <lin.vladimir@gmail.com>
# Lastest update : 2019/03/05 09:38

QT          -= gui
TARGET       = UUIDs
TEMPLATE     = lib
DEFINES     += QT_DEPRECATED_WARNINGS
DEFINES     += EXPORT_UUIDS

SRCROOT      = ../
SRCPATH      = $$SRCROOT/SRCs

INCLUDEPATH  = $$SRCROOT/include
INCLUDEPATH += $$SRCPATH/Windows

HEADERS     += $$SRCROOT/include/UUIDs.hpp
HEADERS     += $$SRCPATH/Windows/PrivateUUIDs.hpp

SOURCES     += $$SRCPATH/UUIDs.cpp
SOURCES     += $$SRCPATH/nDestroyer.cpp
SOURCES     += $$SRCPATH/Convoy.cpp
SOURCES     += $$SRCPATH/Windows/PrivateConvoy.cpp

OTHER_FILES += $$SRCROOT/CMakeLists.txt
OTHER_FILES += $$SRCROOT/*.bat
OTHER_FILES += $$SRCROOT/*.pc.in
OTHER_FILES += $$SRCROOT/VERSION.txt
OTHER_FILES += $$SRCROOT/README.md

OTHER_FILES += $$SRCROOT/projects/*

OTHER_FILES += $$SRCROOT/docs/index.html
OTHER_FILES += $$SRCROOT/docs/*.txt
OTHER_FILES += $$SRCROOT/docs/tw/*
OTHER_FILES += $$SRCROOT/docs/en/*
OTHER_FILES += $$SRCROOT/docs/cn/*
OTHER_FILES += $$SRCROOT/docs/css/*.css

OTHER_FILES += $$SRCROOT/Html/en/*
OTHER_FILES += $$SRCROOT/Html/tw/*
OTHER_FILES += $$SRCROOT/Html/cn/*

OTHER_FILES += $$SRCROOT/JS/*
OTHER_FILES += $$SRCROOT/PHP/*
OTHER_FILES += $$SRCROOT/Python/*
OTHER_FILES += $$SRCROOT/Ruby/*
OTHER_FILES += $$SRCROOT/scripts/*

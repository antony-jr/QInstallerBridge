TEMPLATE = lib
CONFIG += staticlib
TARGET = QInstallerBridge
LIBS += -larchive
INCLUDEPATH += .
DEFINES += QT_DEPRECATED_WARNINGS
QT += core concurrent network xml 

# Input
HEADERS += QInstallerBridge.hpp \
           QArchive/QArchive.hpp \
           QEasyDownloader/QEasyDownloader.hpp

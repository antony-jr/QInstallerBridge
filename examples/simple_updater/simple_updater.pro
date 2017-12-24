TEMPLATE=app
TARGET=Update
LIBS += -larchive
QT+=core network xml
SOURCES += main.cpp 
HEADERS += ../../QInstallerBridge.hpp \
	   ../../QArchive/QArchive.hpp \
	   ../../QEasyDownloader/QEasyDownloader.hpp

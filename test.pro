TEMPLATE=app
TARGET=test
LIBS += -larchive
QT+=core network xml
SOURCES += test.cpp 
HEADERS += QInstallerBridge.hpp \
	   QArchive/QArchive.hpp \
	   QEasyDownloader/QEasyDownloader.hpp

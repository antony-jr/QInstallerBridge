---
id: AddingQInstallerBridge
title: Add QInstallerBridge to Your Qt Project
sidebar_label: Adding to Your Qt Project
---

|	        |             				                                       |		
|-----------|------------------------------------------------------------------|
|  Header:  | #include "QInstallerBridge/QInstallerBridge.hpp"                 |
|   qmake:  | LIBS += -larchive	                                               |
|           | QT += core network xml concurrent                                      |
|	        | HEADERS += QInstallerBridge/QInstallerBridge.hpp                 |
|           | HEADERS += QInstallerBridge/QArchive/QArchive.hpp                |
|           | HEADERS += QInstallerBridge/QEasyDownloader/QEasyDownloader.hpp  |
|Inherits:  | [QObject](http://doc.qt.io/qt-5/qobject.html)                    |

**QInstallerBridge** is just a header and all you have to do after installation is to add   
it in your **.pro** file ( **Qt Project file** ).

### Qt Project file (**.pro**)

Append these **lines** to your **Qt Project file**.

```
LIBS += -larchive
QT += core network xml concurrent
HEADERS += QInstallerBridge/QInstallerBridge.hpp \
           QInstallerBridge/QArchive/QArchive.hpp \
           QInstallerBridge/QEasyDownloader/QEasyDownloader.hpp
```

### Including QInstallerBridge in your Source

Whenever you want to use **QInstallerBridge** , you just need to include it!

```
#include "QInstallerBridge/QInstallerBridge.hpp"
```


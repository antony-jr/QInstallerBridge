---
id: UsingInstallerBridge
title: Using QInstallerBridge for a simple AutoUpdate!
sidebar_label: Simple QInstallerBridge Usage
---

In this example we are going to update **Exercism-GUI** from version **4.3** to **4.4** , instead   
of a real example this is just a prototype and only requires you to execute this code on the   
startup of your app that needs AutoUpdate , If your app is installed through **Qt Installer   
Framework** then you don't need to include the **components.xml** in your package!

### components.xml

This file will be automatically created on **installation** by **Qt Installer Framework** ,   
we are just using this xml as an example but you should not include this file with your packages   
if you install it with **Qt Installer Framework**.

```
<Packages>
    <ApplicationName>Exercism</ApplicationName>
    <ApplicationVersion>1.0.0</ApplicationVersion>
    <Package>
        <Name>com.exercism.exercism_gui</Name>
        <Title>Exercism</Title>
        <Description>
	    Exercism provides countless small wins. The exercises are achievable mini-quests: 
	    small and well-defined, and with enough complexity to uncover bite-sized 
	    knowledge gaps.
    </Description>
        <Version>0.4.3</Version>
        <LastUpdateDate></LastUpdateDate>
        <InstallDate>2017-12-12</InstallDate>
        <Size>88</Size>
        <Checkable>true</Checkable>
    </Package>
</Packages>
```

### main.cpp

This must be your **Qt Apps** main execution file.

```
#include <QCoreApplication>
#include "QInstallerBridge/QInstallerBridge.hpp"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QInstallerBridge Bridge(
    "https://raw.githubusercontent.com/antony-jr/exercism-installer/master/exercism-installers/linux/repo",
    "components.xml",
    "./",
    false);
    QObject::connect(&Bridge, &QInstallerBridge::updatesList, [&](QVector<QInstallerBridge::PackageUpdate> list) {
        if(list.isEmpty()) {
            qDebug() << "No Updates Available!"; // Execute your app here 
            app.quit();
            return;
        }
        qDebug() << "Downloading " << list.size() << "Packages!";
        for(int it = 0; it < list.size() ; ++it) {
            qDebug() << "Package Name ->" << list.at(it).PackageName;
            qDebug() << "Version ->" << list.at(it).Version;
        }
        Bridge.DownloadUpdates();
    });

    QObject::connect(&Bridge, &QInstallerBridge::updatesDownloaded,
    [&]() {
        Bridge.InstallUpdates();
        return;
    });
    QObject::connect(&Bridge, &QInstallerBridge::updatesInstalling,
    [&](QString file) {
        qDebug() << "QInstallerBridge::Installing::" << file;
        return;
    });
    QObject::connect(&Bridge, &QInstallerBridge::updatesInstalled,
    [&]() {
        qDebug() << "QInstallerBridge::Installed Update!";
        app.quit(); // Execute your app here 
        return;
    });
    Bridge.CheckForUpdates();
    return app.exec();
}
```

### simple_update.pro

```
TEMPLATE=app
TARGET=Update

LIBS += -larchive
QT += core network xml
HEADERS += QInstallerBridge/QInstallerBridge.hpp \
           QInstallerBridge/QArchive/QArchive.hpp \
           QInstallerBridge/QEasyDownloader/QEasyDownloader.hpp
```


## Compilation and Execution

```
 $ mkdir build
 $ cd build
 $ qmake ../simple_update.pro
 $ make -j4
 $ cp ../components.xml 
 $ ./Update # Downloads the latest version and installs them
```

Please refer the **API** for more information.

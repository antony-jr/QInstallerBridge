#include <QCoreApplication>
#include "QInstallerBridge.hpp"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QInstallerBridge Bridge("https://raw.githubusercontent.com/antony-jr/exercism-installer/master/exercism-installers/linux/repo",
                            "components.xml",
                            true);
    QObject::connect(&Bridge, &QInstallerBridge::updatesList, [&](QVector<PackageUpdate> list) {
        for(int it = 0; it < list.size() ; ++it) {
            qDebug() << "Package Name ->" << list.at(it).PackageName;
            qDebug() << "Version ->" << list.at(it).Version;
        }
	qDebug() << "Downloading Updates... ";
	Bridge.DownloadUpdates();
    });

    QObject::connect(&Bridge, &QInstallerBridge::updatesDownloaded,
    [&]()
    {
	Bridge.InstallUpdates();
	return;
    });

    QObject::connect(&Bridge, &QInstallerBridge::updatesInstalling ,
    [&](QString file)
    {
	qDebug() << "QInstallerBridge::Installing::" << file;
	return;
    });

    QObject::connect(&Bridge , &QInstallerBridge::updatesInstalled ,
    [&](){
    	qDebug() << "QInstallerBridge::Installed Update!";
	app.quit();
	return;
    });

    Bridge.CheckForUpdates();
    return app.exec();
}

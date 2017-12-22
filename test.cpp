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
    });
    Bridge.CheckForUpdates();
    return app.exec();
}

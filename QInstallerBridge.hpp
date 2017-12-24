/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2017, Antony jr
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------------
 *
 *  @filename		: QInstallerBridge.hpp
 *  @description	: Header file for the QInstallerBridge.
 * -----------------------------------------------------------------------------
*/
#if !defined(QINSTALLER_BRIDGE_HPP_INCLUDED)
#define QINSTALLER_BRIDGE_HPP_INCLUDED
#include <QtCore>
#include <QXmlStreamReader>
#include <QTemporaryFile>
#include <QDomDocument>
#include <QDomElement>
#include "QArchive/QArchive.hpp"
#include "QEasyDownloader/QEasyDownloader.hpp"

/*
 * Error Codes
*/
#define COMPONENTS_XML_NOT_FOUND -1
#define COMPONENTS_XML_SYNTAX_ERROR -2
#define TEMP_FILE_OPEN_ERROR -3
#define NETWORK_ERROR -4
#define UPDATES_XML_NOT_FOUND -5
#define UPDATES_XML_SYNTAX_ERROR -6
#define SHA1_KEY_MISMATCH -7
#define UNKNOWN_ERROR -8

/*
 * Semver
*/
#define MAJOR 0
#define MINOR 1
#define PATCH 2


/*
 * Structure PackageUpdate
 * -----------------------
 *  Contains the information for a package update!
*/
typedef struct {
    QString PackageName;
    QString Description;
    QString Version;
    QString DownloadableArchives;
    QString SHA1;
} PackageUpdate;

/*
 * Class QInstallerBridge  <- Inherits QObject
 * ----------------------
 *
 *  This is the main class that communicates with the Qt Installer Framework
 *  Elegantly , this avoid you from creating nasty subprocess to the Maintanance Tool.
 *
 *  Constructors:
 *
 *  	QInstallerBridge(QObject *p = 0)  - Default Constructor.
 *  	QInstallerBridge(const QString&,
 *  			 const QString&,
 *  			 bool)		  - Constructs the class and also assign
 *  			 		    (1) repoLink , (2) componentsXML and (3) debug.
 *
 *  Methods:
 *
 *  	void setConfiguration(const QString&,
 *                            const QString&,
 *                            bool)		  - Assigns (1) repoLink , (2) componentsXML and (3) debug.
 *
 *	void showConfiguration()		  - Prints your configuration if debug is set true ,
 *					    you must enable debug to print anything from QInstallerBridge!
 *
 *	void setRepoLink(const QString&) 	  - Assigns (1) repoLink.
 *	void setComponentsXML(const QString&)	  - Assigns (2) componentsXML.
 *	void setDebug(bool)			  - Assigns or sets (3) Debug.
 *
 *	const QString &getRepoLink(void)	  - Gets (1) repoLink.
 *	const QString &getComponentsXML(void)  	  - Gets (2) componentsXML.
 *	bool  isDebug(void)			  - Returns True or False from (3) Debug.
 *
 * Private Slots:
 * 	void RepoSync(const QUrl& , const QString&)         - This slot is connected to the signal of
 * 						       	      QEasyDownloader::DownloadFinished
 * 						              Downloads Updates.xml from the remote
 * 						              repo and checks for new update.
 * 						              If found updatesList(const QStringList&) is
 * 						              emitted.
 *
 * 	void VerifyAndMergeRepo(const QUrl&,const QString&) - This slot is connect to the signal of
 * 							      QEasyDownloader::DownloadFinished
 * 							      Downloads {Version}meta.7z from the
 * 							      remote repo and checks the SHA1 sum of
 * 							      the {Version}meta.7z.
 *
 * 	void RepoMergeXML(const QString& , const QString&)  - Sets the new version for the respective package.
 *
 * 	void FreeTemporaryFiles()			    - This slot is used to free all the allocated
 * 							      QTemporaryFile.
 *
 * Public Slots:
 *
 * 	void CheckForUpdates()	- Checks for updates and if found then emits a signal.
 * 	void DownloadUpdates()	- Downloads the entried updates by (1) CheckForUpdates.
 * 	void InstallUpdates()	- Installs the content cached by (2) DownloadUpdates
 * 				  from the remote repo.
 *
 * 	Note: The Above slots must be called in sequence , only execute the next slot once
 * 	      You know that the previous or the current slot emits a positive signal!
 *
 *
 * 	void AbortDownload() - Cancel Downloading Updates.
 * 	void AbortInstallation() - Cancel Installation.
 *
 * Signals:
 *
 * 	void error(short, const QString&) - Emitted when something goes wrong.
 * 	void updatesList(const QVector<PackageUpdate>&) - Emitted when new updates are found.
 *
 * 	void updatesDownloadProgress(qint64 bytesReceived,
 *                                   qint64 bytesTotal,
 *                                   int percent,
 *                                   double speed,
 *                                   const QString &unit,
 *                                   const QUrl &url,
 *                                   const QString &fileName) - Emitted for progress for downloading
 *                                   				updates.
 *
 *      void updateDownloaded(const QUrl&, const QString&) - Emitted when a single update is downloaded.
 *      void updatesDownloaded() - Emitted when all updates are downloaded.
 *      void updatesInstalling(const QString&) - Emitted when a package is beign installed.
 *      void updatesInstalled() - Emitted when all updates get installed , this will be our endpoint!
 *
 * 	void DownloadAborted()  - Emitted when AbortDownload() is successfull.
 * 	void InstallationAborted() - Emitted when AbortInstallation() is successfull.
 *
*/
class QInstallerBridge : public QObject
{
    Q_OBJECT
public:
    explicit QInstallerBridge(QObject *p = 0)
        : QObject(p)
    {
        return;
    }
    explicit QInstallerBridge(const QString& repoLink,
                              const QString& componentsXML,
                              const QString& installPath,
                              bool debug)
        : debug(debug),
          repoLink(repoLink),
          componentsXML(componentsXML),
          installationPath(installPath)
    {
        showConfiguration();
        return;
    }

    void setConfiguration(const QString& repoLink,
                          const QString& componentsXML,
                          const QString& installPath,
                          bool debug)
    {
        this->debug = debug;
        this->repoLink = repoLink;
        this->componentsXML = componentsXML;
        this->installationPath = installPath;

        showConfiguration();
        return;
    }

    void showConfiguration(void)
    {
        if(debug) {
            qDebug() << "*** Configuration ***";
            qDebug() << "Remote Repo URL  :: " << ((repoLink.isEmpty()) ? "Empty!" : repoLink);
            qDebug() << "Components XML   :: " << ((componentsXML.isEmpty()) ? "Empty!" : componentsXML);
            qDebug() << "installationPath :: " << ((installationPath.isEmpty()) ? "Empty!" : installationPath);
            qDebug() << "Debug            :: " << "True";
            qDebug() << "*********************";
        }
        return;
    }


    void setRepoLink(const QString& repoLink)
    {
        this->repoLink = repoLink;
        return;
    }

    void setComponentsXML(const QString& componentsXML)
    {
        this->componentsXML = componentsXML;
        return;
    }

    void setInstallationPath(const QString& installPath)
    {
        this->installationPath = installPath;
        return;
    }

    void setDebug(bool ch)
    {
        this->debug = ch;
        return;
    }

    bool isDebug()
    {
        return debug;
    }

    const QString &getRepoLink()
    {
        return repoLink;
    }

    const QString &getComponentsXML()
    {
        return componentsXML;
    }

    const QString &getInstallationPath()
    {
        return installationPath;
    }

    ~QInstallerBridge()
    {
        FreeTemporaryFiles();
    }

private slots:
    void RepoSync(const QUrl& url, const QString& file)
    {
        if(debug) {
            qDebug() << "QInstallerBridge::Downloaded::" << file << "::From::" << url;
        }
        QFile UFile(file);
        if(!UFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            if(debug) {
                qDebug() << "QInstallerBridge::UpdatesXML:: Not Found!";
            }
            emit error(UPDATES_XML_NOT_FOUND, file);
            return;
        } else {
            if(debug) {
                qDebug() << "QInstallerBridge::UpdatesXML::Open Success!";
            }
        }

        QXmlStreamReader XMLReader(&UFile);
        QVector<PackageUpdate> RepoPackages;
        PackageUpdate Package;

        while (!XMLReader.atEnd() && !XMLReader.hasError()) {
            XMLReader.readNext();
            if (XMLReader.isStartElement()) {
                QString Key = XMLReader.name().toString();

                if(Key == "Name") {
                    Package.PackageName = QString(XMLReader.readElementText());
                } else if(Key == "Description") {
                    Package.Description = QString(XMLReader.readElementText());
                } else if(Key == "Version") {
                    Package.Version = QString(XMLReader.readElementText());
                } else if(Key == "DownloadableArchives") {
                    Package.DownloadableArchives = QString(XMLReader.readElementText());
                } else if(Key == "SHA1") {
                    Package.SHA1 = QString(XMLReader.readElementText());
                    RepoPackages.push_back(Package);
                }
            }
        }

        FreeTemporaryFiles(); // Deletes all allocated QTemporaryFile 's

        if(XMLReader.hasError()) {
            if(debug) {
                qDebug() << "QInstallerBridge::UpdatesXML::Error::" << XMLReader.errorString();
            }
            emit error(UPDATES_XML_SYNTAX_ERROR, XMLReader.errorString());
            return;
        }

        QFile localComponents(componentsXML);
        if(!localComponents.open(QIODevice::ReadOnly | QIODevice::Text)) {
            if(debug) {
                qDebug() << "QInstallerBridge::ComponentsXML:: Not Found!";
            }
            emit error(COMPONENTS_XML_NOT_FOUND, componentsXML);
            return;
        } else {
            if(debug) {
                qDebug() << "QInstallerBridge::ComponentsXML::Open Success!";
            }
        }

        QXmlStreamReader XMLReaderLocal(&localComponents);
        QString PackageNameLocal;

        while (!XMLReaderLocal.atEnd() && !XMLReaderLocal.hasError()) {
            XMLReaderLocal.readNext();
            if (XMLReaderLocal.isStartElement()) {
                QString Key = XMLReaderLocal.name().toString();
                if (Key == "Name") {
                    PackageNameLocal = QString(XMLReaderLocal.readElementText());
                }

                if(Key == "Version") {
                    QString Version(XMLReaderLocal.readElementText());
                    for(int item = 0; item < RepoPackages.size() ; ++item) {
                        if(PackageNameLocal == RepoPackages.at(item).PackageName) {
                            QStringList SemVerLocal = Version.split(".");
                            QStringList SemVerRepos = RepoPackages.at(item).Version.split(".");

                            if(SemVerRepos.at(MAJOR).toInt() >= SemVerLocal.at(MAJOR).toInt()) {
                                if(SemVerRepos.at(MINOR).toInt() >= SemVerLocal.at(MINOR).toInt()) {
                                    if(SemVerRepos.at(PATCH).toInt() > SemVerLocal.at(PATCH).toInt()) {
                                        if(debug) {
                                            qDebug() << "QInstallerBridge::New Update Available!";
                                        }
                                        Updates.push_back(RepoPackages.at(item));
                                    }
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        }

        if(XMLReaderLocal.hasError()) {
            if(debug) {
                qDebug() << "QInstallerBridge::ComponentsXML::Error::" << XMLReader.errorString();
            }
            emit error(COMPONENTS_XML_SYNTAX_ERROR, XMLReader.errorString());
            return;
        }
        emit updatesList(Updates);

        /*
         * Disconnect Previous Connections
         * just in case!
        */
        disconnect(&DownloadManager,
                   SIGNAL(DownloadFinished(const QUrl&, const QString& )),
                   this,
                   SLOT(RepoSync(const QUrl&, const QString&)));
        return;
    }

    void RepoMergeXML(const QString& packageName, const QString& newVersion)
    {
        QDomDocument doc("components");
        QFile file(componentsXML);
        if (!file.open(QIODevice::ReadOnly)) {
            if(debug) {
                qDebug() << "QInstallerBridge::ComponentsXML::Error::Cannot Open file!";
            }
            emit error(COMPONENTS_XML_SYNTAX_ERROR, componentsXML );
            return;
        }

        if (!doc.setContent(&file)) {
            if(debug) {
                qDebug() << "QInstallerBridge::ComponentsXML::Error::Cannot set QDomDocument!";
            }
            emit error(COMPONENTS_XML_SYNTAX_ERROR, componentsXML);

            file.close();
            return ;
        }
        file.close();

        QDomNodeList Packages = doc.elementsByTagName("Package");

        for(int i = 0 ; i < Packages.size() ; ++i) {
            QDomElement Package = Packages.at(i).toElement();
            QDomNodeList Version = Package.elementsByTagName("Version");
            QDomNodeList Name    = Package.elementsByTagName("Name");
            if(Name.at(0).toElement().text() == packageName) {
                Version.at(0).firstChild().setNodeValue(newVersion);
                break;
            }
        }

        if (!file.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
            if(debug) {
                qDebug() << "QInstallerBridge::ComponentsXML::Error::Cannot Append file!";
            }
            emit error(COMPONENTS_XML_SYNTAX_ERROR, componentsXML);
            return;
        }
        QByteArray xml = doc.toByteArray();
        file.write(xml);
        file.close();
        return;
    }

    void FreeTemporaryFiles()
    {
        for(int item = 0; item < CachedTemporaryFiles.size() ; ++item) {
            auto TFile = CachedTemporaryFiles.at(item);
            TFile->deleteLater();
        }
        CachedTemporaryFiles.clear();
        return;
    }

public slots:
    void CheckForUpdates()
    {
        if(debug) {
            qDebug() << "QInstallerBridge::Checking for updates";
            qDebug() << "QInstallerBridge::Collecting online information.";
        }

        Updates.clear(); // clear previous updates!
        auto TempFile = new QTemporaryFile;
        QString updatesXML;

        if(TempFile->open()) {
            updatesXML = TempFile->fileName();
            if(debug) {
                qDebug() << "QInstallerBridge::Using::"<< updatesXML;
            }
        } else {
            emit error(TEMP_FILE_OPEN_ERROR, updatesXML);
            return;
        }
        CachedTemporaryFiles.push_back(TempFile);

        if(debug) {
            qDebug() << "QInstallerBridge::Downloading::Updates.xml:: " << repoLink + "/Updates.xml";
        }

        /*
         * Connect Callbacks!
        */
        connect(&DownloadManager,
                SIGNAL(DownloadFinished(const QUrl&, const QString& )),
                this,
                SLOT(RepoSync(const QUrl&, const QString&)));
        connect(&DownloadManager, &QEasyDownloader::Error,
        [&](QNetworkReply::NetworkError errorCode, const QUrl &url, const QString &fileName) {
            if(errorCode == QNetworkReply::HostNotFoundError) {
                emit error(NETWORK_ERROR,url.toString() + " :: " + fileName);
            }
            return;
        });

        DownloadManager.Debug(debug);
        DownloadManager.Download(repoLink + "/Updates.xml", updatesXML);

        if(debug) {
            qDebug() << "QInstallerBridge::AwaitFor::RepoSync";
        }

        return;
    }

    void DownloadUpdates()
    {
        if(Updates.isEmpty()) {
            return;
        }

        CachedPackagesData.clear(); // clean previous data

        connect(&DownloadManager, &QEasyDownloader::DownloadFinished,
        [&](const QUrl &url, const QString &file) {
            emit updateDownloaded(url, file);
        });

        connect(&DownloadManager, &QEasyDownloader::Error,
        [&](QNetworkReply::NetworkError errorCode, const QUrl &url, const QString &fileName) {
            if(errorCode == QNetworkReply::HostNotFoundError) {
                emit error(NETWORK_ERROR,url.toString() + " :: " + fileName);
            } else {
                emit error(NETWORK_ERROR, "In Retriving " + url.toString());
            }
            return;
        });

        connect(&DownloadManager, &QEasyDownloader::DownloadProgress,
                [&](qint64 bytesReceived,
                    qint64 bytesTotal,
                    int percent,
                    double speed,
                    const QString &unit,
                    const QUrl &url,
        const QString &fileName) {
            emit updatesDownloadProgress(bytesReceived, bytesTotal, percent, speed, unit, url,fileName);
            return;
        });

        connect(&DownloadManager, &QEasyDownloader::Finished,
        [&]() {
            emit updatesDownloaded();
        });

        for(int item = 0; item < Updates.size() ; ++item) {
            QStringList PackagesData = Updates
                                       .at(item)
                                       .DownloadableArchives
                                       .split(",");

            for(int dataItem = 0; dataItem < PackagesData.size() ; ++dataItem) {
                QString ArchiveURL = repoLink
                                     + "/"
                                     + Updates.at(item).PackageName
                                     + "/"
                                     + Updates.at(item).Version
                                     + PackagesData.at(dataItem);
                auto TFile = new QTemporaryFile;
                TFile->open();
                CachedPackagesData << TFile->fileName();
                DownloadManager.Download(ArchiveURL, TFile->fileName());
                CachedTemporaryFiles.push_back(TFile);
            }
        }
        return;
    }

    void InstallUpdates()
    {
        connect(&Archiver, &QArchive::Extractor::status,
        [&](const QString& Archive,const QString& file) {
            (void)Archive;
            emit updatesInstalling(file);
            return;
        });

        connect(&Archiver, &QArchive::Extractor::error,
        [&](short errorCode, const QString& Archive) {
            emit error(errorCode, Archive);
            return;
        });

        connect(&Archiver, &QArchive::Extractor::finished,
        [&]() {
            FreeTemporaryFiles();
            CachedPackagesData.clear();

            /*
             * Update Local Information!
             * ~This is Very Important than Anything~
            */
            for(int item = 0; item < Updates.size() ; ++item) {
                RepoMergeXML(Updates.at(item).PackageName, Updates.at(item).Version);
            }

            emit updatesInstalled();
            return;
        });

        Archiver.addArchive(CachedPackagesData);
        Archiver.setDestination(installationPath);
        Archiver.start(); // Start the extraction off!
        return;
    }

    void AbortDownload()
    {
        DownloadManager.Pause();
        FreeTemporaryFiles();
        emit DownloadAborted();
        return;
    }

    void AbortInstallation()
    {
        if(Archiver.isRunning()) {
            Archiver.requestInterruption();
        }
        FreeTemporaryFiles();
        emit InstallationAborted();
        return;
    }
signals:
    void error(short, const QString&);
    void updatesList(const QVector<PackageUpdate>&);
    void updatesDownloadProgress(qint64 bytesReceived,
                                 qint64 bytesTotal,
                                 int percent,
                                 double speed,
                                 const QString &unit,
                                 const QUrl &url,
                                 const QString &fileName);
    void updateDownloaded(const QUrl&, const QString&);
    void updatesDownloaded();
    void updatesInstalling(const QString&);
    void updatesInstalled();

    void DownloadAborted();
    void InstallationAborted();

private:
    bool debug = false,
         doUpdate = false;
    QString repoLink,
            componentsXML,
            installationPath;
    QStringList CachedPackagesData;
    QVector<QTemporaryFile*> CachedTemporaryFiles;
    QVector<PackageUpdate> Updates;
    QEasyDownloader DownloadManager;
    QArchive::Extractor Archiver;
}; // Class QInstallerBridge Ends
#endif // QINSTALLER_BRIDGE_HPP_INCLUDED

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

/*
 * Semver
*/
#define MAJOR 0
#define MINOR 1
#define PATCH 2

typedef struct {
    QString PackageName;
    QString Description;
    QString Version;
    QString DownloadableArchives;
    QString SHA1;
} PackageUpdate;

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
                              bool debug)
        : debug(debug),
          repoLink(repoLink),
          componentsXML(componentsXML)
    {
        showConfiguration();
        return;
    }

    void setConfiguration(const QString& repoLink,
                          const QString& componentsXML,
                          bool debug)
    {
        this->debug = debug;
        this->repoLink = repoLink;
        this->componentsXML = componentsXML;

        showConfiguration();
        return;
    }

    void showConfiguration(void)
    {
        if(debug) {
            qDebug() << "*** Configuration ***";
            qDebug() << "Remote Repo URL:: " << ((repoLink.isEmpty()) ? "Empty!" : repoLink);
            qDebug() << "Components XML :: " << ((componentsXML.isEmpty()) ? "Empty!" : componentsXML);
            qDebug() << "Debug          :: " << "True";
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

    ~QInstallerBridge()
    {
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
                }/*else if(Key == "Description")
                {
                    Package.Description = QString(XMLReader.readElementText());
                }*/else if(Key == "Version") {
                    Package.Version = QString(XMLReader.readElementText());
                } else if(Key == "DownloadableArchives") {
                    Package.DownloadableArchives = QString(XMLReader.readElementText());
                } else if(Key == "SHA1") {
                    Package.SHA1 = QString(XMLReader.readElementText());
                    RepoPackages.push_back(Package);
                }
            }
        }

        TempFile->remove();

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

                            if(
                                SemVerRepos.at(PATCH) > SemVerLocal.at(PATCH) ||
                                SemVerRepos.at(MINOR) > SemVerLocal.at(MINOR) ||
                                SemVerRepos.at(MAJOR) > SemVerLocal.at(MAJOR)
                            ) {
                                if(debug) {
                                    qDebug() << "QInstallerBridge::New Update Available!";
                                }
                                Updates.push_back(RepoPackages.at(item));
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
        return;
    }

public slots:
    void CheckForUpdates()
    {
        if(debug) {
            qDebug() << "QInstallerBridge::Checking for updates";
            qDebug() << "QInstallerBridge::Collecting online information.";
        }

        TempFile = new QTemporaryFile;
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

        if(debug) {
            qDebug() << "QInstallerBridge::Downloading::Updates.xml:: " << repoLink + "/Updates.xml";
        }

        /*
         * Connect Callbacks!
        */
        connect(&DownloadManager, SIGNAL(DownloadFinished(const QUrl&, const QString& )), this, SLOT(RepoSync(const QUrl&, const QString&)));
        connect(&DownloadManager, &QEasyDownloader::Error,
        [&](QNetworkReply::NetworkError errorCode, const QUrl &url, const QString &fileName) {
            if(errorCode == QNetworkReply::HostNotFoundError) {
                emit error(NETWORK_ERROR,repoLink + "/Updates.xml");
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
        return;
    }

    void UpdatePackages()
    {
        return;
    }

signals:
    void error(short, const QString&);
    void updatesList(const QVector<PackageUpdate>&);
private:
    bool debug = false,
         doUpdate = false;
    QString repoLink,
            componentsXML;
    QVector<PackageUpdate> Updates;
    QTemporaryFile *TempFile;
    QEasyDownloader DownloadManager;
    QArchive::Extractor Archiver;
}; // Class QInstallerBridge Ends
#endif // QINSTALLER_BRIDGE_HPP_INCLUDED

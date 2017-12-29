---
id: ClassQInstallerBridge
title: Class QInstallerBridge
sidebar_label: Class QInstallerBridge
---

This is the only **class** that is provided by **QInstallerBridge** , this takes care of everything you   
want in a single class and thus its **easier** for you to **remember**.

## Public Functions

|                       |                                                                                                              |
|-----------------------|--------------------------------------------------------------------------------------------------------------|
| **explicit**          | QInstallerBridge(QObject *p = 0)                                                                             |
| **explicit**          | QInstallerBridge(const QString& repoLink,const QString& componentsXML,const QString& installPath,bool debug) |
| **void**              | setConfiguration(const QString& repoLink,const QString& componentsXML,const QString& installPath,bool debug) |
| **void**              | showConfiguration(void)                                                                                      |
| **void**              | setRepoLink(const QString& repoLink)                                                                         |
| **void**              | setComponentsXML(const QString& componentsXML)                                                               |
| **void**              | setInstallationPath(const QString& installPath)                                                              |
| **void**              | setDebug(bool ch)                                                                                            |
| **bool**              | isDebug(void)                                                                                                |
| **const QString&**    | getComponentsXML(void)                                                                                       |
| **const QString&**    | getInstallationPath(void)                                                                                    |


## Slots

|                       |                                       |
|-----------------------|---------------------------------------|
| **void**              | CheckForUpdates(void)                 |
| **void**              | DownloadUpdates(void)                 |
| **void**              | InstallUpdates(void)                  |
| **void**              | AbortDownload(void)                   |
| **void**              | AbortInstallation(void)               |

## Signals

|              |                                                                                                                                             |
|--------------|---------------------------------------------------------------------------------------------------------------------------------------------|
| **void**     | error(short **[erroCode](QInstallerBridgeErrorCodes.md)** , const QString& what)                                                            |
| **void**     | updatesList(const QVector<**[PackageUpdate](StructurePackageUpdate.md)**>& AllUpdates)                                                      |
| **void**     | updatesDownloadProgress(qint64 received,qint64 total,int percent,double speed,const QString &unit,const QUrl &url,const QString &fileName)  |
| **void**     | updateDownloaded(const QUrl& url, const QString& filename)                                                                                  |
| **void**     | updatesDownloaded(void)                                                                                                                     |
| **void**     | updatesInstalling(const QString& pacakgeTempFileName)                                                                                       |
| **void**     | updatesInstalled(void)                                                                                                                      |
| **void**     | DownloadAborted(void)                                                                                                                       |
| **void**     | InstallationAborted(void)                                                                                                                   |


## Member Functions Documentation

#### explicit QInstallerBridge(QObject *p = 0)

Only Constructs the **Class**. Sets the **QObject Parent** as NULL or **0** if the does not give it!

#### explicit QInstallerBridge(const QString& repoLink,const QString& componentsXML,const QString& installPath,bool debug)

Sets the configuration and Constructs the **Class**. Sets the **QObject Parent** as NULL or **0**.

> **repoLink** : The Qt Remote repo's url  
>    ex: https://raw.githubusercontent.com/antony-jr/exercism-installer/master/exercism-installers/linux/repo
>   
> **componentsXML** : The path to local components.xml file located near the   
>     **Maintainance Tool** , Usually **./components.xml** for most of the **platform**.   
>   
> **installPath**   : The path where the downloaded packages should be extracted.   
>     Most usually **./** for most of the **platforms**.   
>   
> **debug**         : Set debug true or false.

#### void setConfiguration(const QString& repoLink,const QString& componentsXML,const QString& installPath,bool debug)

Sets the configuration.

> **repoLink** : The Qt Remote repo's url  
>    ex: https://raw.githubusercontent.com/antony-jr/exercism-installer/master/exercism-installers/linux/repo
>   
> **componentsXML** : The path to local components.xml file located near the   
>     **Maintainance Tool** , Usually **./components.xml** for most of the **platform**.   
>   
> **installPath**   : The path where the downloaded packages should be extracted.   
>     Most usually **./** for most of the **platforms**.   
>   
> **debug**         : Set debug true or false.


#### void showConfiguration(void)

Shows the configuration if debug is set to **true**.

> **Note:** Automatically shows the configuration if debug is true.

#### void setRepoLink(const QString& repoLink)

Sets the **Qt Remote Repo** Url. ex: https://raw.githubusercontent.com/antony-jr/exercism-installer/master/exercism-installers/linux/repo

#### void setComponentsXML(const QString& componentsXML)

Sets the **components.xml** path.   
The path to local components.xml file located near the **Maintainance Tool** , Usually **./components.xml** for most of the **platform**.

#### void setInstallationPath(const QString& installPath)

Sets the installation path. The path where the downloaded packages should be extracted. Most usually **./** for most of the **platforms**.

#### void setDebug(bool ch)

Sets whether to debug or not.

#### bool isDebug(void)

Returns **true** if debug is enabled.

#### const QString&	getComponentsXML(void)

Returns the **components.xml** path.

#### const QString&	getInstallationPath(void)

Returns the **installation path**.

#### void CheckForUpdates(void)
<p align="right"> <b> [SLOT] </b> </p>

Checks for new updates from the Qt Remote Repo. Emits updatesList(const QVector<**[PackageUpdate](StructurePackageUpdate.md)**>& AllUpdates) when finished.

#### void DownloadUpdates(void)
<p align="right"> <b> [SLOT] </b> </p>

Downloads new updates if available , **Must Be Called After CheckForUpdates()**. Emits **updatesDownloaded()** when finished.

#### void InstallUpdates(void)
<p align="right"> <b> [SLOT] </b> </p>

Installs the downloaded updates to the **installation path** , **Must Be Called After DownloadUpdates()** , Emits **updatesInstalled()** when finished.

#### void AbortDownload(void)
<p align="right"> <b> [SLOT] </b> </p>

Aborts the current downloads. Emits **DownloadAborted()** on success.

#### void AbortInstallation(void)
<p align="right"> <b> [SLOT] </b> </p>

Aborts thhe current installation. Emits **InstallationAborted()** on success.


#### void error(short **[erroCode](QInstallerBridgeErrorCodes.md)** , const QString& what)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted when something goes wrong.

#### void updatesList(const QVector<**[PackageUpdate](StructurePackageUpdate.md)**>& AllUpdates)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted when **CheckForUpdates()** is finished , The list contains all updates. If empty then there is no update.

#### void updatesDownloadProgress(qint64 received,qint64 total,int percent,double speed,const QString &unit,const QUrl &url,const QString &fileName)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted on progress of the download for the updates.

> **received** : The bytes recived.   
> **total**    : Total bytes to be retrived.   
> **percent**  : The percent of file downloaded from the url.   
> **speed**    : The speed of the download of the current progress.   
> **unit**     : The unit that needs to be used to represent **speed**.(ex: kbps/s)   
> **url**      : The current download url.
> **filename** : The filename which is beign writen to.


#### void updateDownloaded(const QUrl& url, const QString& filename)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted when a single package is downloaded. The **filename** is useless here , because its the location of the temp file.


#### void updatesDownloaded(void)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted when all updates are downloaded.

#### void updatesInstalling(const QString& pacakgeTempFileName)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted when installing a file. (i.e) Copying a single file.


#### void updatesInstalled(void)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted when the installation is successfull.


#### void DownloadAborted(void)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted when download was aborted successfully.

#### void InstallationAborted(void)
<p align="right"> <b> [SIGNAL] </b> </p>

Emitted when installation was aborted successfully.

---
id: StructurePackageUpdate
title: struct QInstallerBridge::PackageUpdate
sidebar_label: struct QInstallerBridge::PackageUpdate
---

This **struct** is used all over QInstallerBridge to store the information on new updates.
**Everything** in this **struct** is a **QString**.

| Key                   |    Meaning                                               |
|-----------------------|----------------------------------------------------------|
| PackageName           | Holds the name of the package.                           | 
| Description           | Holds the remote description of the package.             |
| Version               | Holds the latest version of the package.                 |
| DownloadableArchives  | Holds the information on the package data.               |
| SHA1                  | Contains the SHA1 Sum of **meta.7z** of the remote repo. |

This **struct** is emitted inside a **QVector** when **CheckForUpdates()** is finished.

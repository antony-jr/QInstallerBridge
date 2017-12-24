/****************************************************************************
** Meta object code from reading C++ file 'QInstallerBridge.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QInstallerBridge.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QInstallerBridge.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QInstallerBridge_t {
    QByteArrayData data[30];
    char stringdata0[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QInstallerBridge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QInstallerBridge_t qt_meta_stringdata_QInstallerBridge = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QInstallerBridge"
QT_MOC_LITERAL(1, 17, 5), // "error"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "updatesList"
QT_MOC_LITERAL(4, 36, 22), // "QVector<PackageUpdate>"
QT_MOC_LITERAL(5, 59, 23), // "updatesDownloadProgress"
QT_MOC_LITERAL(6, 83, 13), // "bytesReceived"
QT_MOC_LITERAL(7, 97, 10), // "bytesTotal"
QT_MOC_LITERAL(8, 108, 7), // "percent"
QT_MOC_LITERAL(9, 116, 5), // "speed"
QT_MOC_LITERAL(10, 122, 4), // "unit"
QT_MOC_LITERAL(11, 127, 3), // "url"
QT_MOC_LITERAL(12, 131, 8), // "fileName"
QT_MOC_LITERAL(13, 140, 16), // "updateDownloaded"
QT_MOC_LITERAL(14, 157, 17), // "updatesDownloaded"
QT_MOC_LITERAL(15, 175, 17), // "updatesInstalling"
QT_MOC_LITERAL(16, 193, 16), // "updatesInstalled"
QT_MOC_LITERAL(17, 210, 15), // "DownloadAborted"
QT_MOC_LITERAL(18, 226, 19), // "InstallationAborted"
QT_MOC_LITERAL(19, 246, 8), // "RepoSync"
QT_MOC_LITERAL(20, 255, 4), // "resp"
QT_MOC_LITERAL(21, 260, 12), // "RepoMergeXML"
QT_MOC_LITERAL(22, 273, 11), // "packageName"
QT_MOC_LITERAL(23, 285, 10), // "newVersion"
QT_MOC_LITERAL(24, 296, 18), // "FreeTemporaryFiles"
QT_MOC_LITERAL(25, 315, 15), // "CheckForUpdates"
QT_MOC_LITERAL(26, 331, 15), // "DownloadUpdates"
QT_MOC_LITERAL(27, 347, 14), // "InstallUpdates"
QT_MOC_LITERAL(28, 362, 13), // "AbortDownload"
QT_MOC_LITERAL(29, 376, 17) // "AbortInstallation"

    },
    "QInstallerBridge\0error\0\0updatesList\0"
    "QVector<PackageUpdate>\0updatesDownloadProgress\0"
    "bytesReceived\0bytesTotal\0percent\0speed\0"
    "unit\0url\0fileName\0updateDownloaded\0"
    "updatesDownloaded\0updatesInstalling\0"
    "updatesInstalled\0DownloadAborted\0"
    "InstallationAborted\0RepoSync\0resp\0"
    "RepoMergeXML\0packageName\0newVersion\0"
    "FreeTemporaryFiles\0CheckForUpdates\0"
    "DownloadUpdates\0InstallUpdates\0"
    "AbortDownload\0AbortInstallation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QInstallerBridge[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       3,    1,  104,    2, 0x06 /* Public */,
       5,    7,  107,    2, 0x06 /* Public */,
      13,    2,  122,    2, 0x06 /* Public */,
      14,    0,  127,    2, 0x06 /* Public */,
      15,    1,  128,    2, 0x06 /* Public */,
      16,    0,  131,    2, 0x06 /* Public */,
      17,    0,  132,    2, 0x06 /* Public */,
      18,    0,  133,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  134,    2, 0x08 /* Private */,
      21,    2,  137,    2, 0x08 /* Private */,
      24,    0,  142,    2, 0x08 /* Private */,
      25,    0,  143,    2, 0x0a /* Public */,
      26,    0,  144,    2, 0x0a /* Public */,
      27,    0,  145,    2, 0x0a /* Public */,
      28,    0,  146,    2, 0x0a /* Public */,
      29,    0,  147,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Short, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Int, QMetaType::Double, QMetaType::QString, QMetaType::QUrl, QMetaType::QString,    6,    7,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QInstallerBridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QInstallerBridge *_t = static_cast<QInstallerBridge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->updatesList((*reinterpret_cast< const QVector<PackageUpdate>(*)>(_a[1]))); break;
        case 2: _t->updatesDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QUrl(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 3: _t->updateDownloaded((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->updatesDownloaded(); break;
        case 5: _t->updatesInstalling((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->updatesInstalled(); break;
        case 7: _t->DownloadAborted(); break;
        case 8: _t->InstallationAborted(); break;
        case 9: _t->RepoSync((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->RepoMergeXML((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->FreeTemporaryFiles(); break;
        case 12: _t->CheckForUpdates(); break;
        case 13: _t->DownloadUpdates(); break;
        case 14: _t->InstallUpdates(); break;
        case 15: _t->AbortDownload(); break;
        case 16: _t->AbortInstallation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QInstallerBridge::*_t)(short , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QInstallerBridge::*_t)(const QVector<PackageUpdate> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::updatesList)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QInstallerBridge::*_t)(qint64 , qint64 , int , double , const QString & , const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::updatesDownloadProgress)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QInstallerBridge::*_t)(const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::updateDownloaded)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QInstallerBridge::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::updatesDownloaded)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QInstallerBridge::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::updatesInstalling)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QInstallerBridge::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::updatesInstalled)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QInstallerBridge::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::DownloadAborted)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (QInstallerBridge::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QInstallerBridge::InstallationAborted)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject QInstallerBridge::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QInstallerBridge.data,
      qt_meta_data_QInstallerBridge,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QInstallerBridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QInstallerBridge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QInstallerBridge.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QInstallerBridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void QInstallerBridge::error(short _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QInstallerBridge::updatesList(const QVector<PackageUpdate> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QInstallerBridge::updatesDownloadProgress(qint64 _t1, qint64 _t2, int _t3, double _t4, const QString & _t5, const QUrl & _t6, const QString & _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QInstallerBridge::updateDownloaded(const QUrl & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QInstallerBridge::updatesDownloaded()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QInstallerBridge::updatesInstalling(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QInstallerBridge::updatesInstalled()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QInstallerBridge::DownloadAborted()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QInstallerBridge::InstallationAborted()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

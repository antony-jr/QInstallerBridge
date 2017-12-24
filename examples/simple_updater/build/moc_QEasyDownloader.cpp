/****************************************************************************
** Meta object code from reading C++ file 'QEasyDownloader.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QEasyDownloader/QEasyDownloader.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QEasyDownloader.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QEasyDownloader_t {
    QByteArrayData data[34];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QEasyDownloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QEasyDownloader_t qt_meta_stringdata_QEasyDownloader = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QEasyDownloader"
QT_MOC_LITERAL(1, 16, 8), // "Finished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "DownloadFinished"
QT_MOC_LITERAL(4, 43, 3), // "url"
QT_MOC_LITERAL(5, 47, 8), // "fileName"
QT_MOC_LITERAL(6, 56, 16), // "DownloadProgress"
QT_MOC_LITERAL(7, 73, 13), // "bytesReceived"
QT_MOC_LITERAL(8, 87, 10), // "bytesTotal"
QT_MOC_LITERAL(9, 98, 7), // "percent"
QT_MOC_LITERAL(10, 106, 5), // "speed"
QT_MOC_LITERAL(11, 112, 4), // "unit"
QT_MOC_LITERAL(12, 117, 5), // "Error"
QT_MOC_LITERAL(13, 123, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(14, 151, 9), // "errorCode"
QT_MOC_LITERAL(15, 161, 7), // "Timeout"
QT_MOC_LITERAL(16, 169, 11), // "GetResponse"
QT_MOC_LITERAL(17, 181, 7), // "content"
QT_MOC_LITERAL(18, 189, 8), // "download"
QT_MOC_LITERAL(19, 198, 12), // "finishedHead"
QT_MOC_LITERAL(20, 211, 8), // "finished"
QT_MOC_LITERAL(21, 220, 16), // "downloadProgress"
QT_MOC_LITERAL(22, 237, 17), // "startNextDownload"
QT_MOC_LITERAL(23, 255, 5), // "error"
QT_MOC_LITERAL(24, 261, 7), // "timeout"
QT_MOC_LITERAL(25, 269, 12), // "saveFileName"
QT_MOC_LITERAL(26, 282, 8), // "Download"
QT_MOC_LITERAL(27, 291, 8), // "givenURL"
QT_MOC_LITERAL(28, 300, 5), // "Pause"
QT_MOC_LITERAL(29, 306, 6), // "Resume"
QT_MOC_LITERAL(30, 313, 5), // "Retry"
QT_MOC_LITERAL(31, 319, 43), // "QNetworkAccessManager::Networ..."
QT_MOC_LITERAL(32, 363, 6), // "access"
QT_MOC_LITERAL(33, 370, 3) // "Get"

    },
    "QEasyDownloader\0Finished\0\0DownloadFinished\0"
    "url\0fileName\0DownloadProgress\0"
    "bytesReceived\0bytesTotal\0percent\0speed\0"
    "unit\0Error\0QNetworkReply::NetworkError\0"
    "errorCode\0Timeout\0GetResponse\0content\0"
    "download\0finishedHead\0finished\0"
    "downloadProgress\0startNextDownload\0"
    "error\0timeout\0saveFileName\0Download\0"
    "givenURL\0Pause\0Resume\0Retry\0"
    "QNetworkAccessManager::NetworkAccessibility\0"
    "access\0Get"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QEasyDownloader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    2,  115,    2, 0x06 /* Public */,
       6,    7,  120,    2, 0x06 /* Public */,
      12,    3,  135,    2, 0x06 /* Public */,
      15,    2,  142,    2, 0x06 /* Public */,
      16,    1,  147,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  150,    2, 0x08 /* Private */,
      19,    0,  151,    2, 0x08 /* Private */,
      20,    0,  152,    2, 0x08 /* Private */,
      21,    2,  153,    2, 0x08 /* Private */,
      22,    0,  158,    2, 0x08 /* Private */,
      23,    1,  159,    2, 0x08 /* Private */,
      24,    0,  162,    2, 0x08 /* Private */,
      25,    1,  163,    2, 0x08 /* Private */,
      26,    2,  166,    2, 0x0a /* Public */,
      26,    1,  171,    2, 0x0a /* Public */,
      28,    0,  174,    2, 0x0a /* Public */,
      29,    0,  175,    2, 0x0a /* Public */,
      30,    1,  176,    2, 0x0a /* Public */,
      33,    1,  179,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Int, QMetaType::Double, QMetaType::QString, QMetaType::QUrl, QMetaType::QString,    7,    8,    9,   10,   11,    4,    5,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QUrl, QMetaType::QString,   14,    4,    5,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   27,    5,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, QMetaType::QUrl,    4,

       0        // eod
};

void QEasyDownloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QEasyDownloader *_t = static_cast<QEasyDownloader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Finished(); break;
        case 1: _t->DownloadFinished((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->DownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QUrl(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 3: _t->Error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1])),(*reinterpret_cast< const QUrl(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->Timeout((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->GetResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->download(); break;
        case 7: _t->finishedHead(); break;
        case 8: _t->finished(); break;
        case 9: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 10: _t->startNextDownload(); break;
        case 11: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 12: _t->timeout(); break;
        case 13: { QString _r = _t->saveFileName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->Download((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: _t->Download((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->Pause(); break;
        case 17: _t->Resume(); break;
        case 18: _t->Retry((*reinterpret_cast< QNetworkAccessManager::NetworkAccessibility(*)>(_a[1]))); break;
        case 19: _t->Get((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QEasyDownloader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::DownloadFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(qint64 , qint64 , int , double , const QString & , const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::DownloadProgress)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(QNetworkReply::NetworkError , const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Error)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Timeout)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::GetResponse)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject QEasyDownloader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QEasyDownloader.data,
      qt_meta_data_QEasyDownloader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QEasyDownloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEasyDownloader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QEasyDownloader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEasyDownloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void QEasyDownloader::Finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QEasyDownloader::DownloadFinished(const QUrl & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QEasyDownloader::DownloadProgress(qint64 _t1, qint64 _t2, int _t3, double _t4, const QString & _t5, const QUrl & _t6, const QString & _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QEasyDownloader::Error(QNetworkReply::NetworkError _t1, const QUrl & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QEasyDownloader::Timeout(const QUrl & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QEasyDownloader::GetResponse(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

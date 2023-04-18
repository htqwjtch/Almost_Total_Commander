/****************************************************************************
** Meta object code from reading C++ file 'threadtocpy.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FileManager/thToCopy/threadtocpy.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadtocpy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSThreadToCopyENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSThreadToCopyENDCLASS = QtMocHelpers::stringData(
    "ThreadToCopy",
    "copyFinished",
    "",
    "runCopy",
    "QDir",
    "rDir",
    "SysElem*",
    "file",
    "dir",
    "filePath",
    "dirPath"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSThreadToCopyENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[5];
    char stringdata5[5];
    char stringdata6[9];
    char stringdata7[5];
    char stringdata8[4];
    char stringdata9[9];
    char stringdata10[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSThreadToCopyENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSThreadToCopyENDCLASS_t qt_meta_stringdata_CLASSThreadToCopyENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "ThreadToCopy"
        QT_MOC_LITERAL(13, 12),  // "copyFinished"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 7),  // "runCopy"
        QT_MOC_LITERAL(35, 4),  // "QDir"
        QT_MOC_LITERAL(40, 4),  // "rDir"
        QT_MOC_LITERAL(45, 8),  // "SysElem*"
        QT_MOC_LITERAL(54, 4),  // "file"
        QT_MOC_LITERAL(59, 3),  // "dir"
        QT_MOC_LITERAL(63, 8),  // "filePath"
        QT_MOC_LITERAL(72, 7)   // "dirPath"
    },
    "ThreadToCopy",
    "copyFinished",
    "",
    "runCopy",
    "QDir",
    "rDir",
    "SysElem*",
    "file",
    "dir",
    "filePath",
    "dirPath"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSThreadToCopyENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    5,   27,    2, 0x0a,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 6, QMetaType::QString, QMetaType::QString,    5,    7,    8,    9,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject ThreadToCopy::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSThreadToCopyENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSThreadToCopyENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSThreadToCopyENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ThreadToCopy, std::true_type>,
        // method 'copyFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'runCopy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDir, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void ThreadToCopy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadToCopy *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->copyFinished(); break;
        case 1: _t->runCopy((*reinterpret_cast< std::add_pointer_t<QDir>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadToCopy::*)();
            if (_t _q_method = &ThreadToCopy::copyFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ThreadToCopy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadToCopy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSThreadToCopyENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadToCopy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadToCopy::copyFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP

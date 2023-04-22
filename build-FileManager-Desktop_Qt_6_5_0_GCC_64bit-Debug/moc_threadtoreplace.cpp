/****************************************************************************
** Meta object code from reading C++ file 'threadtoreplace.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FileManager/thToReplace/threadtoreplace.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadtoreplace.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSThreadToReplaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSThreadToReplaceENDCLASS = QtMocHelpers::stringData(
    "ThreadToReplace",
    "notPerformed",
    "",
    "replaceFinished",
    "runReplace",
    "QDir",
    "rDir",
    "SysElem*",
    "file",
    "dir",
    "filePath",
    "dirPath"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSThreadToReplaceENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[16];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[11];
    char stringdata5[5];
    char stringdata6[5];
    char stringdata7[9];
    char stringdata8[5];
    char stringdata9[4];
    char stringdata10[9];
    char stringdata11[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSThreadToReplaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSThreadToReplaceENDCLASS_t qt_meta_stringdata_CLASSThreadToReplaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "ThreadToReplace"
        QT_MOC_LITERAL(16, 12),  // "notPerformed"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 15),  // "replaceFinished"
        QT_MOC_LITERAL(46, 10),  // "runReplace"
        QT_MOC_LITERAL(57, 4),  // "QDir"
        QT_MOC_LITERAL(62, 4),  // "rDir"
        QT_MOC_LITERAL(67, 8),  // "SysElem*"
        QT_MOC_LITERAL(76, 4),  // "file"
        QT_MOC_LITERAL(81, 3),  // "dir"
        QT_MOC_LITERAL(85, 8),  // "filePath"
        QT_MOC_LITERAL(94, 7)   // "dirPath"
    },
    "ThreadToReplace",
    "notPerformed",
    "",
    "replaceFinished",
    "runReplace",
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

Q_CONSTINIT static const uint qt_meta_data_CLASSThreadToReplaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,
       3,    0,   33,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    5,   34,    2, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 7, QMetaType::QString, QMetaType::QString,    6,    8,    9,   10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject ThreadToReplace::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSThreadToReplaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSThreadToReplaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSThreadToReplaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ThreadToReplace, std::true_type>,
        // method 'notPerformed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'replaceFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'runReplace'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDir, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void ThreadToReplace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadToReplace *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->notPerformed(); break;
        case 1: _t->replaceFinished(); break;
        case 2: _t->runReplace((*reinterpret_cast< std::add_pointer_t<QDir>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadToReplace::*)();
            if (_t _q_method = &ThreadToReplace::notPerformed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadToReplace::*)();
            if (_t _q_method = &ThreadToReplace::replaceFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ThreadToReplace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadToReplace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSThreadToReplaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadToReplace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ThreadToReplace::notPerformed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ThreadToReplace::replaceFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

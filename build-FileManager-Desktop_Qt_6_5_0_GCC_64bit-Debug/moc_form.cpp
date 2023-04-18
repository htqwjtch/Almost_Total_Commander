/****************************************************************************
** Meta object code from reading C++ file 'form.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FileManager/form/form.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFormENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFormENDCLASS = QtMocHelpers::stringData(
    "Form",
    "startCopy",
    "",
    "QDir",
    "rDir",
    "SysElem*",
    "file",
    "dir",
    "filePath",
    "dirPath",
    "startRemove",
    "startReplace",
    "startSearch",
    "on_lvLeft_clicked",
    "QModelIndex",
    "index",
    "on_lvLeft_doubleClicked",
    "on_btnCreate_clicked",
    "on_btnRemove_clicked",
    "on_btnCopy_clicked",
    "on_btnReplace_clicked",
    "on_btnRename_clicked",
    "on_lineSearch_textEdited",
    "arg1",
    "on_btnSearch_clicked",
    "on_leftPath_textEdited",
    "ready_to_remove",
    "ready_to_copy",
    "ready_to_replace",
    "ready_to_search",
    "QFileInfoList",
    "list"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFormENDCLASS_t {
    uint offsetsAndSizes[64];
    char stringdata0[5];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[5];
    char stringdata5[9];
    char stringdata6[5];
    char stringdata7[4];
    char stringdata8[9];
    char stringdata9[8];
    char stringdata10[12];
    char stringdata11[13];
    char stringdata12[12];
    char stringdata13[18];
    char stringdata14[12];
    char stringdata15[6];
    char stringdata16[24];
    char stringdata17[21];
    char stringdata18[21];
    char stringdata19[19];
    char stringdata20[22];
    char stringdata21[21];
    char stringdata22[25];
    char stringdata23[5];
    char stringdata24[21];
    char stringdata25[23];
    char stringdata26[16];
    char stringdata27[14];
    char stringdata28[17];
    char stringdata29[16];
    char stringdata30[14];
    char stringdata31[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFormENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFormENDCLASS_t qt_meta_stringdata_CLASSFormENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "Form"
        QT_MOC_LITERAL(5, 9),  // "startCopy"
        QT_MOC_LITERAL(15, 0),  // ""
        QT_MOC_LITERAL(16, 4),  // "QDir"
        QT_MOC_LITERAL(21, 4),  // "rDir"
        QT_MOC_LITERAL(26, 8),  // "SysElem*"
        QT_MOC_LITERAL(35, 4),  // "file"
        QT_MOC_LITERAL(40, 3),  // "dir"
        QT_MOC_LITERAL(44, 8),  // "filePath"
        QT_MOC_LITERAL(53, 7),  // "dirPath"
        QT_MOC_LITERAL(61, 11),  // "startRemove"
        QT_MOC_LITERAL(73, 12),  // "startReplace"
        QT_MOC_LITERAL(86, 11),  // "startSearch"
        QT_MOC_LITERAL(98, 17),  // "on_lvLeft_clicked"
        QT_MOC_LITERAL(116, 11),  // "QModelIndex"
        QT_MOC_LITERAL(128, 5),  // "index"
        QT_MOC_LITERAL(134, 23),  // "on_lvLeft_doubleClicked"
        QT_MOC_LITERAL(158, 20),  // "on_btnCreate_clicked"
        QT_MOC_LITERAL(179, 20),  // "on_btnRemove_clicked"
        QT_MOC_LITERAL(200, 18),  // "on_btnCopy_clicked"
        QT_MOC_LITERAL(219, 21),  // "on_btnReplace_clicked"
        QT_MOC_LITERAL(241, 20),  // "on_btnRename_clicked"
        QT_MOC_LITERAL(262, 24),  // "on_lineSearch_textEdited"
        QT_MOC_LITERAL(287, 4),  // "arg1"
        QT_MOC_LITERAL(292, 20),  // "on_btnSearch_clicked"
        QT_MOC_LITERAL(313, 22),  // "on_leftPath_textEdited"
        QT_MOC_LITERAL(336, 15),  // "ready_to_remove"
        QT_MOC_LITERAL(352, 13),  // "ready_to_copy"
        QT_MOC_LITERAL(366, 16),  // "ready_to_replace"
        QT_MOC_LITERAL(383, 15),  // "ready_to_search"
        QT_MOC_LITERAL(399, 13),  // "QFileInfoList"
        QT_MOC_LITERAL(413, 4)   // "list"
    },
    "Form",
    "startCopy",
    "",
    "QDir",
    "rDir",
    "SysElem*",
    "file",
    "dir",
    "filePath",
    "dirPath",
    "startRemove",
    "startReplace",
    "startSearch",
    "on_lvLeft_clicked",
    "QModelIndex",
    "index",
    "on_lvLeft_doubleClicked",
    "on_btnCreate_clicked",
    "on_btnRemove_clicked",
    "on_btnCopy_clicked",
    "on_btnReplace_clicked",
    "on_btnRename_clicked",
    "on_lineSearch_textEdited",
    "arg1",
    "on_btnSearch_clicked",
    "on_leftPath_textEdited",
    "ready_to_remove",
    "ready_to_copy",
    "ready_to_replace",
    "ready_to_search",
    "QFileInfoList",
    "list"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFormENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,  122,    2, 0x06,    1 /* Public */,
      10,    4,  133,    2, 0x06,    7 /* Public */,
      11,    5,  142,    2, 0x06,   12 /* Public */,
      12,    3,  153,    2, 0x06,   18 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,  160,    2, 0x08,   22 /* Private */,
      16,    1,  163,    2, 0x08,   24 /* Private */,
      17,    0,  166,    2, 0x08,   26 /* Private */,
      18,    0,  167,    2, 0x08,   27 /* Private */,
      19,    0,  168,    2, 0x08,   28 /* Private */,
      20,    0,  169,    2, 0x08,   29 /* Private */,
      21,    0,  170,    2, 0x08,   30 /* Private */,
      22,    1,  171,    2, 0x08,   31 /* Private */,
      24,    0,  174,    2, 0x08,   33 /* Private */,
      25,    1,  175,    2, 0x08,   34 /* Private */,
      26,    0,  178,    2, 0x08,   36 /* Private */,
      27,    0,  179,    2, 0x08,   37 /* Private */,
      28,    0,  180,    2, 0x08,   38 /* Private */,
      29,    1,  181,    2, 0x08,   39 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    4,    6,    7,    8,    9,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    4,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,

       0        // eod
};

Q_CONSTINIT const QMetaObject Form::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSFormENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFormENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFormENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Form, std::true_type>,
        // method 'startCopy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDir, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'startRemove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'startReplace'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDir, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<SysElem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'startSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_lvLeft_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_lvLeft_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_btnCreate_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRemove_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnCopy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnReplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRename_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineSearch_textEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_btnSearch_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_leftPath_textEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'ready_to_remove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ready_to_copy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ready_to_replace'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ready_to_search'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QFileInfoList, std::false_type>
    >,
    nullptr
} };

void Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startCopy((*reinterpret_cast< std::add_pointer_t<QDir>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 1: _t->startRemove((*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 2: _t->startReplace((*reinterpret_cast< std::add_pointer_t<QDir>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<SysElem*>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 3: _t->startSearch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 4: _t->on_lvLeft_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 5: _t->on_lvLeft_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 6: _t->on_btnCreate_clicked(); break;
        case 7: _t->on_btnRemove_clicked(); break;
        case 8: _t->on_btnCopy_clicked(); break;
        case 9: _t->on_btnReplace_clicked(); break;
        case 10: _t->on_btnRename_clicked(); break;
        case 11: _t->on_lineSearch_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->on_btnSearch_clicked(); break;
        case 13: _t->on_leftPath_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->ready_to_remove(); break;
        case 15: _t->ready_to_copy(); break;
        case 16: _t->ready_to_replace(); break;
        case 17: _t->ready_to_search((*reinterpret_cast< std::add_pointer_t<QFileInfoList>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Form::*)(QDir , SysElem * , SysElem * , QString , QString );
            if (_t _q_method = &Form::startCopy; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Form::*)(SysElem * , SysElem * , QString , QString );
            if (_t _q_method = &Form::startRemove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Form::*)(QDir , SysElem * , SysElem * , QString , QString );
            if (_t _q_method = &Form::startReplace; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Form::*)(QString , QString , QString );
            if (_t _q_method = &Form::startSearch; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFormENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Form::startCopy(QDir _t1, SysElem * _t2, SysElem * _t3, QString _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Form::startRemove(SysElem * _t1, SysElem * _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Form::startReplace(QDir _t1, SysElem * _t2, SysElem * _t3, QString _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Form::startSearch(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP

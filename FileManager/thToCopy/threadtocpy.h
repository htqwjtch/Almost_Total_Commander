#ifndef THREADTOCPY_H
#define THREADTOCPY_H

#include "../sysElem/syselem.h"

#include <QDir>
#include <QFileInfo>
#include <QObject>

class ThreadToCopy : public QObject
{
    Q_OBJECT

public slots:
    void runCopy(QDir lDir, QDir rDir, SysElem* file, SysElem* dir, QString dirName);

public:
    explicit ThreadToCopy(QObject* parent = nullptr);
    void c_py(QDir lDir, QDir rDir, SysElem* file, SysElem* dir, QString dirName);
    void recursiveCopyList(QDir&, QFileInfoList&); //функция рекурсивного наполнения содержимым списка для копирования

signals:
};

#endif // THREADTOCPY_H

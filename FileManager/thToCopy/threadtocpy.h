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
    void run_copy(QDir rDir, SysElem* file, SysElem* dir, QString filePath, QString dirPath);

public:
    explicit ThreadToCopy(QObject* parent = nullptr);
    void c_py(QDir, SysElem*, SysElem*, QString);

signals:
    void not_performed();
    void copy_finished();
};

#endif // THREADTOCPY_H

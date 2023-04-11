#ifndef THREADTOCOPY_H
#define THREADTOCOPY_H

#include "systemfiles.h"

#include <QDir>
#include <QFileInfo>
#include <QObject>

class ThreadToCopy : public QObject
{
    Q_OBJECT

public slots:
    void runCopy(QDir lDir, QDir rDir, System* file, System* dir, System* link, QString dirName);

public:
    explicit ThreadToCopy(QObject* parent = nullptr);
    void c_py(QDir lDir, QDir rDir, System* file, System* dir, System* link, QString dirName);
    void recursiveCopyList(QDir&, QFileInfoList&); //функция рекурсивного наполнения содержимым списка для копирования

signals:
};

#endif // THREADTOCOPY_H

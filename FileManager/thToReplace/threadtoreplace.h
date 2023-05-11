#ifndef THREADTOREPLACE_H
#define THREADTOREPLACE_H

#include "../sysElem/syselem.h"

#include <QDir>
#include <QFileInfo>
#include <QObject>

class ThreadToReplace : public QObject
{
    Q_OBJECT
public slots:
    void run_replace(QDir rDir, SysElem* file, SysElem* dir, QString filePath, QString dirPath);

public:
    explicit ThreadToReplace(QObject* parent = nullptr);
    void c_py(QDir, SysElem*, SysElem*, QString);
    bool rec_remove(QDir&, SysElem*, SysElem*);
    void r_move(SysElem*, SysElem*, QString);

signals:
    void not_performed();
    void replace_finished();
};

#endif // THREADTOREPLACE_H

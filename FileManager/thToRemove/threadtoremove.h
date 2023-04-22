#ifndef THREADTOREMOVE_H
#define THREADTOREMOVE_H

#include "../sysElem/syselem.h"

#include <QDir>
#include <QObject>

class ThreadToRemove : public QObject
{
    Q_OBJECT

public slots:
    void runRemove(SysElem* file, SysElem* dir, QString filePath, QString dirPath);

public:
    explicit ThreadToRemove(QObject* parent = nullptr);
    bool recRemove(QDir&, SysElem*, SysElem*); //функция рекурсивного удаления содержимого выбранной папки
    void r_move(SysElem*, SysElem*, QString);

signals:
    void notPerformed();
    void removeFinished();
};
#endif // THREADTOREMOVE_H

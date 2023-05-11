#ifndef THREADTOREMOVE_H
#define THREADTOREMOVE_H

#include "../sysElem/syselem.h"

#include <QDir>
#include <QObject>

class ThreadToRemove : public QObject
{
    Q_OBJECT

public slots:
    void run_remove(SysElem* file, SysElem* dir, QString filePath, QString dirPath);

public:
    explicit ThreadToRemove(QObject* parent = nullptr);
    bool rec_remove(QDir&, SysElem*, SysElem*); //функция рекурсивного удаления содержимого выбранной папки
    void r_move(SysElem*, SysElem*, QString);

signals:
    void not_performed();
    void remove_finished();
};
#endif // THREADTOREMOVE_H

#ifndef THREADTOREMOVE_H
#define THREADTOREMOVE_H

#include "systemfiles.h"

#include <QDir>
#include <QObject>

class ThreadToRemove : public QObject
{
    Q_OBJECT

public slots:
    void runRemove(System* file, System* dir, System* link, QString dirPath);

public:
    explicit ThreadToRemove(QObject* parent = nullptr);
    bool recursiveDelete(QDir&, System*, System*, System*); //функция рекурсивного удаления содержимого выбранной папки
    void r_move(System*, System*, System*, QString);

signals:
};

#endif // THREADTOREMOVE_H

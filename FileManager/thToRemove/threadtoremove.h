#ifndef THREADTOREMOVE_H
#define THREADTOREMOVE_H

#include <QDir>
#include <QFile>
#include <QObject>

class ThreadToRemove : public QObject
{
    Q_OBJECT

public slots:
    void run_remove(const QString&, const QString&);

public:
    explicit ThreadToRemove(QObject* parent = nullptr);
    bool rec_remove(QDir&); //функция рекурсивного удаления содержимого выбранной папки
    void remove(const QString&);

signals:
    void not_performed();
    void remove_finished();
};
#endif // THREADTOREMOVE_H

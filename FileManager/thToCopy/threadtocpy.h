#ifndef THREADTOCPY_H
#define THREADTOCPY_H

#include <QDir>
#include <QFile>
#include <QObject>

class ThreadToCopy : public QObject
{
    Q_OBJECT

public slots:
    void run_copy(QDir rDir, const QString& filePath, const QString& dirPath);

public:
    explicit ThreadToCopy(QObject* parent = nullptr);
    void c_py(QDir, const QString&);

signals:
    void not_performed();
    void copy_finished();
};

#endif // THREADTOCPY_H

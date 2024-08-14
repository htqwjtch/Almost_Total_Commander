#ifndef THREADTOREPLACE_H
#define THREADTOREPLACE_H

#include <QDir>
#include <QFileInfo>
#include <QObject>

class ThreadToReplace : public QObject
{
    Q_OBJECT
public slots:
    void run_replace(QDir rDir, const QString& filePath, const QString& dirPath);

public:
    explicit ThreadToReplace(QObject* parent = nullptr);
    void c_py(QDir, const QString&);
    bool rec_remove(QDir&);
    void r_move(const QString&);

signals:
    void not_performed();
    void replace_finished();
};

#endif // THREADTOREPLACE_H

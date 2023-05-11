#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

#include "../form/form.h"
#include "../thToCopy/threadtocpy.h"
#include "../thToRemove/threadtoremove.h"
#include "../thToReplace/threadtoreplace.h"
#include "../thToSearch/threadtosearch.h"

#include <QLabel>
#include <QThread>

void connect_threads(Form* form, QThread* threadCopy, QThread* threadRemove, QThread* threadReplace, QThread* threadSearch, ThreadToCopy* thCopy,
                     ThreadToRemove* thRemove, ThreadToReplace* thReplace, ThreadToSearch* thSearch)
{
    QObject::connect(form, SIGNAL(destroyed()), threadCopy, SLOT(quit()));

    QObject::connect(form, SIGNAL(destroyed()), threadRemove, SLOT(quit()));

    QObject::connect(form, SIGNAL(destroyed()), threadReplace, SLOT(quit()));

    QObject::connect(form, SIGNAL(destroyed()), threadSearch, SLOT(quit()));

    QObject::connect(form, SIGNAL(start_copy(QDir, SysElem*, SysElem*, QString, QString)), thCopy,
                     SLOT(run_copy(QDir, SysElem*, SysElem*, QString, QString)));
    thCopy->moveToThread(threadCopy);
    threadCopy->start();

    QObject::connect(form, SIGNAL(start_remove(SysElem*, SysElem*, QString, QString)), thRemove,
                     SLOT(run_remove(SysElem*, SysElem*, QString, QString)));
    thRemove->moveToThread(threadRemove);
    threadRemove->start();

    QObject::connect(form, SIGNAL(start_replace(QDir, SysElem*, SysElem*, QString, QString)), thReplace,
                     SLOT(run_replace(QDir, SysElem*, SysElem*, QString, QString)));
    thReplace->moveToThread(threadReplace);
    threadReplace->start();

    QObject::connect(form, SIGNAL(start_search(QString, QString, QString)), thSearch, SLOT(run_search(QString, QString, QString)));
    thSearch->moveToThread(threadSearch);
    threadSearch->start();

    QObject::connect(thRemove, SIGNAL(not_performed()), form, SLOT(remove_is_not_performed()));
    QObject::connect(thCopy, SIGNAL(not_performed()), form, SLOT(copy_is_not_performed()));
    QObject::connect(thReplace, SIGNAL(not_performed()), form, SLOT(replace_is_not_performed()));

    QObject::connect(thRemove, SIGNAL(remove_finished()), form, SLOT(ready_to_remove()));
    QObject::connect(thCopy, SIGNAL(copy_finished()), form, SLOT(ready_to_copy()));
    QObject::connect(thReplace, SIGNAL(replace_finished()), form, SLOT(ready_to_replace()));
    QObject::connect(thSearch, SIGNAL(search_finished(QFileInfoList)), form, SLOT(ready_to_search(QFileInfoList)));
}

void init_infoBar(QFileInfo info, QLabel* uiSize, QLabel* uiType, QLabel* uiDate)
{
    QString sizeFile = "";                                                     // переменная размера файла
    if (info.size() < 1024)                                                    // если размер файла меньше 1 килобайта
        sizeFile = sizeFile.append(QString::number(info.size())).append(" B"); // приведение размера к виду "B"
    else if (info.size() >= 1024 && info.size() < 1048576) // если размер файла больше 1 килобайта и меньше 1 мегабайта
    {
        double d = info.size() / 1024.;
        sizeFile = sizeFile.append(QString::number(d)).append(" KB"); // приведение размера к виду "KB"
    }
    else if (info.size() >= 1048576 && info.size() < 1073741824) // если размер файла больше 1 мегабайта и меньше 1 гигабайта
    {
        double d = info.size() / 1048576.;
        sizeFile = sizeFile.append(QString::number(d)).append(" MB"); // приведение размера к виду "MB"
    }
    else if (info.size() >= 1073741824) // если размер файла больше 1 гигабайта
    {
        double d = info.size() / 1073741824.;
        sizeFile = sizeFile.append(QString::number(d)).append(" GB"); // приведение размера к виду "GB"
    }
    QString size = "Size : ";
    QString allSize = size.append(sizeFile); // строка для отображения размера файла
    uiSize->setText(allSize);                // отображениe размера файла
    QString typeInfo = "Type : ";
    if (info.isSymLink())
        typeInfo = typeInfo.append("link ");
    else
        typeInfo = typeInfo.append("file ").append(info.suffix());
    uiType->setText(typeInfo);                             // отображениe типа файла
    QString format = "dddd, d MMMM yy hh:mm:ss";           // формат вывода даты последнего изменения
    uiDate->setText(info.lastModified().toString(format)); // вывод даты последнего изменения
}

#endif // OTHER_FUNCTIONS_H

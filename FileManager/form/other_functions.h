#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

#include <QDateTime>
#include <QFileInfo>
#include <QLabel>
#include <QThread>

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

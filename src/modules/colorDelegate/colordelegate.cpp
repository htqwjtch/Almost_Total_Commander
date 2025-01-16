#include "colordelegate.h"

ColorDelegate::ColorDelegate(QObject *parent) : QStyledItemDelegate(parent) {}

void ColorDelegate::paint(QPainter *painter,
    const QStyleOptionViewItem &option,
    const QModelIndex &index) const
{
    QString filePath = index.data(QFileSystemModel::FilePathRole).toString();

    QFileInfo fileInfo(filePath);

    QStyleOptionViewItem optionCopy = option;
    optionCopy.palette.setColor(QPalette::Text, classifyFileColor(fileInfo));

    QStyledItemDelegate::paint(painter, optionCopy, index);
}

QColor ColorDelegate::classifyFileColor(const QFileInfo &fileInfo) const
{
    QMimeDatabase mimeDb;
    QMimeType mimeType = mimeDb.mimeTypeForFile(fileInfo);

    QColor textColor = Qt::black;

    if (fileInfo.isDir())
    {
        textColor = Qt::black;
    }
    else if (fileInfo.isSymLink())
    {
        textColor = Qt::cyan;
    }
    else if (fileInfo.isExecutable())
    {
        textColor = Qt::green;
    }
    else if (mimeType.name().startsWith("text/"))
    {
        textColor = QColor(0, 0, 0); // black for text files
    }
    else if (mimeType.name().startsWith("image/"))
    {
        textColor = QColor(255, 0, 0); // red for pics
    }
    else if (mimeType.name().startsWith("audio/"))
    {
        textColor = QColor(0, 255, 0); // green for audio
    }
    else if (mimeType.name().startsWith("video/"))
    {
        textColor = QColor(0, 0, 255); // blue for video
    }
    else if (mimeType.name() == "application/zip" || mimeType.name() == "application/x-tar" ||
        mimeType.name() == "application/x-gzip" || mimeType.name() == "application/x-bzip2" ||
        mimeType.name() == "application/x-rar-compressed" ||
        mimeType.name() == "application/x-7z-compressed")
    {
        textColor = QColor(255, 165, 0); // orange for archives
    }
    else if (mimeType.name() == "application/pdf" ||
        mimeType.name().startsWith("application/msword") ||
        mimeType.name().startsWith("application/vnd.ms-excel") ||
        mimeType.name().startsWith("application/vnd.ms-powerpoint"))
    {
        textColor = QColor(255, 255, 0); // yellow for docs
    }
    else if (mimeType.name().startsWith("font/") || mimeType.name() == "application/x-font-ttf" ||
        mimeType.name() == "application/x-font-otf")
    {
        textColor = QColor(128, 0, 128); // purple for fonts
    }
    else
    {
        textColor = QColor(169, 169, 169); // gray for unknown files
    }

    return textColor;
}
